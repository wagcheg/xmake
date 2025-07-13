--!A cross-platform build utility based on Lua
--
-- Licensed under the Apache License, Version 2.0 (the "License");
-- you may not use this file except in compliance with the License.
-- You may obtain a copy of the License at
--
--     http://www.apache.org/licenses/LICENSE-2.0
--
-- Unless required by applicable law or agreed to in writing, software
-- distributed under the License is distributed on an "AS IS" BASIS,
-- WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
-- See the License for the specific language governing permissions and
-- limitations under the License.
--
-- Copyright (C) 2015-present, Xmake Open Source Community.
--
-- @author      ruki
-- @file        depend.lua
--

-- imports
import("core.base.option")
import("core.cache.localcache")
import("core.project.project")

-- load depfiles
function _load_depfiles(parser, dependinfo, depfiles, opt)
    depfiles = parser(depfiles, opt)
    if depfiles then
        if dependinfo.files then
            table.join2(dependinfo.files, depfiles)
        else
            dependinfo.files = depfiles
        end
    end
end

-- get depfiles parser
function _get_depfiles_parser(depfiles_format)
    assert(depfiles_format, "no depfiles format")
    local depfiles_parsers = _g._depfiles_parsers
    if depfiles_parsers == nil then
        depfiles_parsers = {}
        _g._depfiles_parsers = depfiles_parsers
    end
    local parser = depfiles_parsers[depfiles_format]
    if parser == nil then
        parser = import("core.tools." .. depfiles_format .. ".parse_deps", {anonymous = true})
        depfiles_parsers[depfiles_format] = parser or false
    end
    return parser or nil
end

-- load dependent info from the given file (.d)
function load(dependfile, opt)
    if os.isfile(dependfile) then
        -- may be the depend file has been incomplete when if the compilation process is abnormally interrupted
        local dependinfo = try { function() return io.load(dependfile) end }
        if dependinfo then
            -- attempt to load depfiles from the compilers
            local notloadfiles = (opt ~= nil and opt.notloadfiles ~= nil) and opt.notloadfiles or notloadfiles(dependfile)
            if not notloadfiles then
                local depfiles = dependinfo.depfiles
                if depfiles then
                    local depfiles_parser = _get_depfiles_parser(dependinfo.depfiles_format)
                    _load_depfiles(depfiles_parser, dependinfo, depfiles, opt)
                    dependinfo.depfiles = nil
                end
            end
            dependinfo.dependfile = dependfile
            return dependinfo
        end
    end
end

-- show diagnosis info?
function _is_show_diagnosis_info()
    local show = _g.is_show_diagnosis_info
    if show == nil then
        if project.policy("diagnosis.check_build_deps") then
            show = true
        else
            show = false
        end
        _g.is_show_diagnosis_info = show
    end
    return show
end

function _normailize_path(dep)
    local projectdir = os.projectdir()
    dep = path.normalize(dep)
    if path.is_absolute(dep) then
        dep = path.translate(dep)
    else
        dep = path.absolute(dep, projectdir)
    end
    return is_plat("windows") and string.upper(dep) or dep
end

-- save dependent info to file
function save(dependinfo, dependfile)
    local dependfile_normailize = _normailize_path(dependfile)
    local depfiles = dependinfo.depfiles
    local files = dependinfo.files
    dependinfo.files = nil
    if depfiles then
        local depfiles_parser = _get_depfiles_parser(dependinfo.depfiles_format)
        _load_depfiles(depfiles_parser, dependinfo, depfiles, opt)
        dependinfo.depfiles = nil
        dependinfo.depfiles_format = nil
    end

    if dependinfo.files then
        local maxindex = localcache.get2("depend", "log", "maxindex") or 1
        local dependfileindex = localcache.get2("depend", "log", dependfile_normailize) or maxindex
    
        local deps = localcache.get("depend", "deps")
        for dep, depinfo in pairs(deps) do
            for lastmtime, dependfiles in pairs(depinfo) do
                if dependfiles then
                    dependfiles[dependfileindex] = nil
                end
            end
        end
        for _, file in ipairs(dependinfo.files) do
            local mtime =  os.mtime(file)
            file = _normailize_path(file)
            local dependfiles = localcache.get3("depend", "deps", file, mtime)
            if dependfiles == nil then
                dependfiles = {}
                dependfiles[dependfileindex] = true
                localcache.set3("depend", "deps", file, mtime, dependfiles)
            else
                dependfiles[dependfileindex] = true
            end
        end
        localcache.set2("depend", "log", dependfile_normailize, dependfileindex)
        maxindex = maxindex + 1
        localcache.set2("depend", "log", "maxindex", maxindex)

        dependneedsave = dependneedsave and dependneedsave + 1 or 0
    end

    dependinfo.files = files
    io.save(dependfile, dependinfo)

    for _, file in ipairs(table.wrap(dependinfo.outputs)) do
        filechanged(file)
    end

    if dependneedsave and dependneedsave % 100 == 0 then
        localcache.save("depend")
    end
end

-- Is the dependent info changed?
--
-- if not depend.is_changed(dependinfo, {filemtime = os.mtime(objectfile), values = {...}}) then
--      return
-- end
--
function is_changed(dependinfo, opt)
    if is_quickchanged(dependinfo.dependfile) then
        return true
    end

    -- empty depend info? always be changed
    local files = table.wrap(dependinfo.files)
    local values = table.wrap(dependinfo.values)
    if #files == 0 and #values == 0 then
        if _is_show_diagnosis_info() then
            cprint("${color.warning}[check_build_deps]: files and values are empty")
        end
        return true
    end

    -- check whether the dependent files are changed
    local timecache = opt.timecache
    local lastmtime = opt.lastmtime or 0
    _g.files_mtime = _g.files_mtime or {}
    local files_mtime = _g.files_mtime
    for _, file in ipairs(files) do

        -- get and cache the file mtime
        local mtime
        if timecache then
            mtime = files_mtime[file]
            if mtime == nil then
                mtime = os.mtime(file)
                files_mtime[file] = mtime
            end
        else
            mtime = os.mtime(file)
        end

        -- source and header files have been changed or not exists?
        if mtime == 0 or mtime > lastmtime then
            if _is_show_diagnosis_info() then
                cprint("${color.warning}[check_build_deps]: file %s is changed, mtime: %s, lastmtime: %s", file, mtime, lastmtime)
            end
            return true
        end
    end

    -- check whether the dependent values are changed
    local depvalues = values
    local optvalues = table.wrap(opt.values)
    if #depvalues ~= #optvalues then
        if _is_show_diagnosis_info() then
            cprint("${color.warning}[check_build_deps]: values count mismatch, old: %s, new: %s", #depvalues, optvalues)
        end
        return true
    end
    for idx, depvalue in ipairs(depvalues) do
        local optvalue = optvalues[idx]
        local deptype = type(depvalue)
        local opttype = type(optvalue)
        if deptype ~= opttype then
            if _is_show_diagnosis_info() then
                cprint("${color.warning}[check_build_deps]: value %s != %s", depvalue, optvalue)
            end
            return true
        elseif deptype == "string" and depvalue ~= optvalue then
            if _is_show_diagnosis_info() then
                cprint("${color.warning}[check_build_deps]: value %s != %s", depvalue, optvalue)
            end
            return true
        elseif deptype == "table" then
            for subidx, subvalue in ipairs(depvalue) do
                if subvalue ~= optvalue[subidx] then
                    if _is_show_diagnosis_info() then
                        cprint("${color.warning}[check_build_deps]: value %s != %s at index %d", subvalue, optvalue[subidx], subidx)
                    end
                    return true
                end
            end
        end
    end

    -- check whether the dependent files list are changed
    if opt.files and dependinfo.files then
        local optfiles = table.wrap(opt.files)
        if #files ~= #optfiles then
            if _is_show_diagnosis_info() then
                cprint("${color.warning}[check_build_deps]: files count mismatch, old: %s, new: %s", #files, #optfiles)
            end
            return true
        end
        for idx, file in ipairs(files) do
            if file ~= optfiles[idx] then
                if _is_show_diagnosis_info() then
                    cprint("${color.warning}[check_build_deps]: file %s != %s at index %d", file, optfiles[idx], idx)
                end
                return true
            end
        end
    end
end

-- dependfile must be last or else targetfile is corruption
function time_compare(before, after)
    return (before > after) and 0 or before
end

-- on changed for the dependent files and values
--
-- e.g.
--
-- depend.on_changed(function ()
--     -- do some thing
--     -- ..
--
--     -- maybe need update dependent files
--     dependinfo.files = {""}
--
--     -- return new dependinfo (optional)
--     return {files = {}, ..}
--
-- end, {dependfile = "/xx/xx",
--       values = {compinst:program(), compflags},
--       files = {sourcefile, ...}})
--
function on_changed(callback, opt)
    opt = opt or {}

    -- dry run? we only do callback directly and do not change any status
    if opt.dryrun then
        return callback()
    end

    -- get files
    assert(opt.files, "depend.on_changed(): please set files list!")

    -- get dependfile
    local dependfile = opt.dependfile
    if not dependfile then
        dependfile = project.tmpfile(table.concat(table.wrap(opt.files), ""))
    end

    -- load dependent info
    local dependinfo = opt.changed and {} or (load(dependfile) or {})

    -- @note we use mtime(dependfile) instead of mtime(objectfile) to ensure the object file is is fully compiled.
    -- @see https://github.com/xmake-io/xmake/issues/748
    if not is_changed(dependinfo, {
            timecache = opt.timecache,
            lastmtime = opt.lastmtime or os.mtime(dependfile),
            values = opt.values, files = opt.files}) then
        return
    end

    -- do callback if changed and maybe files and values will be updated
    dependinfo = callback() or {}

    -- update files and values to the dependent file
    dependinfo.files = dependinfo.files or {}
    table.join2(dependinfo.files, opt.files)
    if opt.values then
        dependinfo.values = dependinfo.values or {}
        table.join2(dependinfo.values, opt.values)
    end
    dependinfo.outputs = dependinfo.outputs or {}
    table.join2(dependinfo.outputs, opt.outputs)
    save(dependinfo, dependfile)
end

function is_quickchanged(dependfile)
    dependfile = _normailize_path(dependfile)
    local dependfileindex = localcache.get2("depend", "log", dependfile)
    local loged = dependfileindex
    local fileschanged = false
    if loged then
        _init_quickchanged()
        fileschanged = changeddependfile[dependfileindex]
    end

    local quickchanged = loged and fileschanged
    if quickchanged then
        if _is_show_diagnosis_info() then
            cprint("${color.warning}[check_build_deps]: quickly check file %s is changed, mtime: %s, lastmtime: %s", quickchanged.file, quickchanged.mtime, quickchanged.lastmtime)
        end
    end
    return quickchanged
end

function notloadfiles(dependfile)
    dependfile = _normailize_path(dependfile)
    local dependfileindex = localcache.get2("depend", "log", dependfile)
    local loged = dependfileindex
    local fileschanged = false
    if loged then
        _init_quickchanged()
        fileschanged = changeddependfile[dependfileindex]
    end

    return loged and not fileschanged
end

function _init_quickchanged()
    if not changeddependfile then
        changeddependfile = {}
        local deps = localcache.get("depend", "deps")
        for dep, depinfo in pairs(deps) do
            local mtime = os.mtime(dep)
            for lastmtime, dependfiles in pairs(depinfo) do
                if lastmtime ~= mtime then
                    for dependfileindex, v in pairs(dependfiles) do
                        changeddependfile[dependfileindex] = {file = dep, mtime = mtime, lastmtime = lastmtime}
                    end
                end
            end
        end
    end
end

function needsave()
    return dependneedsave
end

function filechanged(dep)
    if changeddependfile then
        dep = _normailize_path(dep)
        local depinfo = localcache.get2("depend", "deps", dep)
        local mtime = os.mtime(dep)
        for lastmtime, dependfiles in pairs(depinfo) do
            if lastmtime ~= mtime then
                for dependfileindex, v in pairs(dependfiles) do
                    changeddependfile[dependfileindex] = {file = dep, mtime = mtime, lastmtime = lastmtime}
                end
            end
        end
    end
end