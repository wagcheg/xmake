#ifndef TB_CONFIG_H
#define TB_CONFIG_H

// version
#define TB_CONFIG_VERSION "1.7.3"
#define TB_CONFIG_VERSION_MAJOR 1
#define TB_CONFIG_VERSION_MINOR 7
#define TB_CONFIG_VERSION_ALTER 3
#define TB_CONFIG_VERSION_BUILD 20230201

// defines
#define TB_CONFIG_OS_HAIKU 1
#define _GNU_SOURCE 1
#define _REENTRANT 1
#define TB_CONFIG_SMALL 1
/*#undef TB_CONFIG_MICRO_ENABLE*/
/*#undef TB_CONFIG_TYPE_HAVE_WCHAR*/
#define TB_CONFIG_TYPE_HAVE_FLOAT 1
/*#undef TB_CONFIG_FORCE_UTF8*/
/*#undef TB_CONFIG_API_HAVE_DEPRECATED*/
/*#undef TB_CONFIG_EXCEPTION_ENABLE*/

// keywords
#define TB_CONFIG_KEYWORD_HAVE__thread 1
#define TB_CONFIG_KEYWORD_HAVE_Thread_local 1

// features
#define TB_CONFIG_FEATURE_HAVE_ANONYMOUS_UNION 1

// modules
/*#undef TB_CONFIG_MODULE_HAVE_XML*/
/*#undef TB_CONFIG_MODULE_HAVE_ZIP*/
/*#undef TB_CONFIG_MODULE_HAVE_HASH*/
/*#undef TB_CONFIG_MODULE_HAVE_REGEX*/
/*#undef TB_CONFIG_MODULE_HAVE_OBJECT*/
/*#undef TB_CONFIG_MODULE_HAVE_CHARSET*/
/*#undef TB_CONFIG_MODULE_HAVE_DATABASE*/
/*#undef TB_CONFIG_MODULE_HAVE_COROUTINE*/

// packages
/*#undef TB_CONFIG_PACKAGE_HAVE_ZLIB*/
/*#undef TB_CONFIG_PACKAGE_HAVE_MYSQL*/
/*#undef TB_CONFIG_PACKAGE_HAVE_SQLITE3*/
/*#undef TB_CONFIG_PACKAGE_HAVE_OPENSSL*/
/*#undef TB_CONFIG_PACKAGE_HAVE_POLARSSL*/
/*#undef TB_CONFIG_PACKAGE_HAVE_MBEDTLS*/
/*#undef TB_CONFIG_PACKAGE_HAVE_PCRE2*/
/*#undef TB_CONFIG_PACKAGE_HAVE_PCRE*/

// libc functions
#define TB_CONFIG_LIBC_HAVE_MEMCPY 1
#define TB_CONFIG_LIBC_HAVE_MEMSET 1
#define TB_CONFIG_LIBC_HAVE_MEMMOVE 1
#define TB_CONFIG_LIBC_HAVE_MEMCMP 1
#define TB_CONFIG_LIBC_HAVE_MEMMEM 1
#define TB_CONFIG_LIBC_HAVE_STRCAT 1
#define TB_CONFIG_LIBC_HAVE_STRNCAT 1
#define TB_CONFIG_LIBC_HAVE_STRCPY 1
#define TB_CONFIG_LIBC_HAVE_STRNCPY 1
#define TB_CONFIG_LIBC_HAVE_STRLCPY 1
#define TB_CONFIG_LIBC_HAVE_STRLEN 1
#define TB_CONFIG_LIBC_HAVE_STRNLEN 1
#define TB_CONFIG_LIBC_HAVE_STRCHR 1
#define TB_CONFIG_LIBC_HAVE_STRRCHR 1
#define TB_CONFIG_LIBC_HAVE_STRSTR 1
#define TB_CONFIG_LIBC_HAVE_STRCASESTR 1
#define TB_CONFIG_LIBC_HAVE_STRCMP 1
#define TB_CONFIG_LIBC_HAVE_STRCASECMP 1
#define TB_CONFIG_LIBC_HAVE_STRNCMP 1
#define TB_CONFIG_LIBC_HAVE_STRNCASECMP 1

#define TB_CONFIG_LIBC_HAVE_WCSCAT 1
#define TB_CONFIG_LIBC_HAVE_WCSNCAT 1
#define TB_CONFIG_LIBC_HAVE_WCSCPY 1
#define TB_CONFIG_LIBC_HAVE_WCSNCPY 1
#define TB_CONFIG_LIBC_HAVE_WCSLCPY 1
#define TB_CONFIG_LIBC_HAVE_WCSLEN 1
#define TB_CONFIG_LIBC_HAVE_WCSNLEN 1
#define TB_CONFIG_LIBC_HAVE_WCSSTR 1
/*#undef TB_CONFIG_LIBC_HAVE_WCSCASESTR*/
#define TB_CONFIG_LIBC_HAVE_WCSCMP 1
#define TB_CONFIG_LIBC_HAVE_WCSCASECMP 1
#define TB_CONFIG_LIBC_HAVE_WCSNCMP 1
#define TB_CONFIG_LIBC_HAVE_WCSNCASECMP 1
#define TB_CONFIG_LIBC_HAVE_WCSTOMBS 1
#define TB_CONFIG_LIBC_HAVE_MBSTOWCS 1

#define TB_CONFIG_LIBC_HAVE_GMTIME 1
#define TB_CONFIG_LIBC_HAVE_MKTIME 1
#define TB_CONFIG_LIBC_HAVE_LOCALTIME 1
#define TB_CONFIG_LIBC_HAVE_GETTIMEOFDAY 1
#define TB_CONFIG_LIBC_HAVE_SIGNAL 1
#define TB_CONFIG_LIBC_HAVE_SETJMP 1
#define TB_CONFIG_LIBC_HAVE_SIGSETJMP 1
#define TB_CONFIG_LIBC_HAVE_KILL 1
/*#undef TB_CONFIG_LIBC_HAVE_BACKTRACE*/
#define TB_CONFIG_LIBC_HAVE_SETLOCALE 1
#define TB_CONFIG_LIBC_HAVE_FPUTC 1
#define TB_CONFIG_LIBC_HAVE_FGETC 1
#define TB_CONFIG_LIBC_HAVE_UNGETC 1
#define TB_CONFIG_LIBC_HAVE_FPUTS 1
#define TB_CONFIG_LIBC_HAVE_FGETS 1
#define TB_CONFIG_LIBC_HAVE_FREAD 1
#define TB_CONFIG_LIBC_HAVE_FWRITE 1
#define TB_CONFIG_LIBC_HAVE_SRANDOM 1
#define TB_CONFIG_LIBC_HAVE_RANDOM 1

// libm functions
#define TB_CONFIG_LIBM_HAVE_SINCOS 1
#define TB_CONFIG_LIBM_HAVE_SINCOSF 1
#define TB_CONFIG_LIBM_HAVE_LOG2 1
#define TB_CONFIG_LIBM_HAVE_LOG2F 1
#define TB_CONFIG_LIBM_HAVE_SQRT 1
#define TB_CONFIG_LIBM_HAVE_SQRTF 1
#define TB_CONFIG_LIBM_HAVE_ACOS 1
#define TB_CONFIG_LIBM_HAVE_ACOSF 1
#define TB_CONFIG_LIBM_HAVE_ASIN 1
#define TB_CONFIG_LIBM_HAVE_ASINF 1
#define TB_CONFIG_LIBM_HAVE_POW 1
#define TB_CONFIG_LIBM_HAVE_POWF 1
#define TB_CONFIG_LIBM_HAVE_FMOD 1
#define TB_CONFIG_LIBM_HAVE_FMODF 1
#define TB_CONFIG_LIBM_HAVE_TAN 1
#define TB_CONFIG_LIBM_HAVE_TANF 1
#define TB_CONFIG_LIBM_HAVE_ATAN 1
#define TB_CONFIG_LIBM_HAVE_ATANF 1
#define TB_CONFIG_LIBM_HAVE_ATAN2 1
#define TB_CONFIG_LIBM_HAVE_ATAN2F 1
#define TB_CONFIG_LIBM_HAVE_COS 1
#define TB_CONFIG_LIBM_HAVE_COSF 1
#define TB_CONFIG_LIBM_HAVE_SIN 1
#define TB_CONFIG_LIBM_HAVE_SINF 1
#define TB_CONFIG_LIBM_HAVE_EXP 1
#define TB_CONFIG_LIBM_HAVE_EXPF 1

// posix functions
#define TB_CONFIG_POSIX_HAVE_POLL 1
#define TB_CONFIG_POSIX_HAVE_SELECT 1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_MUTEX_INIT 1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_CREATE 1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_SETSPECIFIC 1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_GETSPECIFIC 1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_KEY_CREATE 1
#define TB_CONFIG_POSIX_HAVE_PTHREAD_KEY_DELETE 1
/*#undef TB_CONFIG_POSIX_HAVE_PTHREAD_SETAFFINITY_NP*/
#define TB_CONFIG_POSIX_HAVE_SOCKET 1
#define TB_CONFIG_POSIX_HAVE_OPENDIR 1
#define TB_CONFIG_POSIX_HAVE_DLOPEN 1
#define TB_CONFIG_POSIX_HAVE_OPEN 1
/*#undef TB_CONFIG_POSIX_HAVE_STAT64*/
/*#undef TB_CONFIG_POSIX_HAVE_LSTAT64*/
#define TB_CONFIG_POSIX_HAVE_GETHOSTNAME 1
#define TB_CONFIG_POSIX_HAVE_GETIFADDRS 1
#define TB_CONFIG_POSIX_HAVE_SEM_INIT 1
#define TB_CONFIG_POSIX_HAVE_GETPAGESIZE 1
#define TB_CONFIG_POSIX_HAVE_SYSCONF 1
#define TB_CONFIG_POSIX_HAVE_SCHED_YIELD 1
/*#undef TB_CONFIG_POSIX_HAVE_SCHED_SETAFFINITY*/
#define TB_CONFIG_POSIX_HAVE_REGCOMP 1
#define TB_CONFIG_POSIX_HAVE_REGEXEC 1
#define TB_CONFIG_POSIX_HAVE_READV 1
#define TB_CONFIG_POSIX_HAVE_WRITEV 1
/*#undef TB_CONFIG_POSIX_HAVE_PREADV*/
/*#undef TB_CONFIG_POSIX_HAVE_PWRITEV*/
/*#undef TB_CONFIG_POSIX_HAVE_PREAD64*/
/*#undef TB_CONFIG_POSIX_HAVE_PWRITE64*/
/*#undef TB_CONFIG_POSIX_HAVE_FDATASYNC*/
/*#undef TB_CONFIG_POSIX_HAVE_COPYFILE*/
/*#undef TB_CONFIG_POSIX_HAVE_SENDFILE*/
/*#undef TB_CONFIG_POSIX_HAVE_EPOLL_CREATE*/
/*#undef TB_CONFIG_POSIX_HAVE_EPOLL_WAIT*/
#define TB_CONFIG_POSIX_HAVE_POSIX_SPAWNP 1
#define TB_CONFIG_POSIX_HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR_NP 1
#if (defined(__MACH__) && __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ <= 101400)
#   undef TB_CONFIG_POSIX_HAVE_POSIX_SPAWN_FILE_ACTIONS_ADDCHDIR_NP // only for macOS >=10.15
#endif
#define TB_CONFIG_POSIX_HAVE_EXECVP 1
#define TB_CONFIG_POSIX_HAVE_EXECVPE 1
#define TB_CONFIG_POSIX_HAVE_FORK 1
#define TB_CONFIG_POSIX_HAVE_VFORK 1
#define TB_CONFIG_POSIX_HAVE_WAITPID 1
#define TB_CONFIG_POSIX_HAVE_GETDTABLESIZE 1
#define TB_CONFIG_POSIX_HAVE_GETRLIMIT 1
#define TB_CONFIG_POSIX_HAVE_GETADDRINFO 1
#define TB_CONFIG_POSIX_HAVE_GETNAMEINFO 1
#define TB_CONFIG_POSIX_HAVE_GETHOSTBYNAME 1
#define TB_CONFIG_POSIX_HAVE_GETHOSTBYADDR 1
#define TB_CONFIG_POSIX_HAVE_FCNTL 1
#define TB_CONFIG_POSIX_HAVE_PIPE 1
/*#undef TB_CONFIG_POSIX_HAVE_PIPE2*/
#define TB_CONFIG_POSIX_HAVE_MKFIFO 1
#define TB_CONFIG_POSIX_HAVE_MMAP 1
#define TB_CONFIG_POSIX_HAVE_FUTIMENS 1
#define TB_CONFIG_POSIX_HAVE_UTIMENSAT 1

// windows functions
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGE*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGE_NF*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGE_ACQ*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGE_REL*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGE8*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGE8_NF*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGE8_ACQ*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGE8_REL*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDOR8*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDOR8_NF*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDOR8_ACQ*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDOR8_REL*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGEADD*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGEADD_NF*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGEADD_ACQ*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGEADD_REL*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGEADD64*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGEADD64_NF*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGEADD64_ACQ*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDEXCHANGEADD64_REL*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDCOMPAREEXCHANGE*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDCOMPAREEXCHANGE_NF*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDCOMPAREEXCHANGE_ACQ*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDCOMPAREEXCHANGE_REL*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDCOMPAREEXCHANGE64*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDCOMPAREEXCHANGE64_NF*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDCOMPAREEXCHANGE64_ACQ*/
/*#undef TB_CONFIG_WINDOWS_HAVE__INTERLOCKEDCOMPAREEXCHANGE64_REL*/

// bsd functions
#define TB_CONFIG_BSD_HAVE_FLOCK 1

// systemv functions
#define TB_CONFIG_SYSTEMV_HAVE_SEMGET 1
/*#undef TB_CONFIG_SYSTEMV_HAVE_SEMTIMEDOP*/

// linux functions
/*#undef TB_CONFIG_LINUX_HAVE_INOTIFY_INIT*/

// valgrind functions
/*#undef TB_CONFIG_VALGRIND_HAVE_VALGRIND_STACK_REGISTER*/

#endif
