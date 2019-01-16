/*
    2    Copyright (c) 2001, 2016, Oracle and/or its affiliates. All rights reserved.
    3
    4    This program is free software; you can redistribute it and/or modify
    5    it under the terms of the GNU General Public License as published by
    6    the Free Software Foundation; version 2 of the License.
    7
    8    This program is distributed in the hope that it will be useful,
    9    but WITHOUT ANY WARRANTY; without even the implied warranty of
   10    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   11    GNU General Public License for more details.
   12
   13    You should have received a copy of the GNU General Public License
   14    along with this program; if not, write to the Free Software
   15    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */
   16
   17// #ifndef MY_GLOBAL_INCLUDED
   18 //#define MY_GLOBAL_INCLUDED
   19
   20 /**
   21   @file include/my_global.h
   22   This include file should be included first in every header file.
   23
   24   This makes sure my_config.h is included to get platform specific
   25   symbols defined and it makes sure a lot of platform/compiler
   26   differences are mitigated.
   27 */
   28
   29 #include "my_config.h"
   30
   31 #define __STDC_LIMIT_MACROS     /* Enable C99 limit macros */
   32 #define __STDC_FORMAT_MACROS    /* Enable C99 printf format macros */
   33 #define _USE_MATH_DEFINES       /* Get access to M_PI, M_E, etc. in math.h */
   34
   35 #ifdef _WIN32
   36 /* Include common headers.*/
   37 # include <winsock2.h>
   38 # include <ws2tcpip.h> /* SOCKET */
   39 # include <io.h>       /* access(), chmod() */
   40 #endif
   41
   42 #include <stdio.h>
   43 #include <stdarg.h>
   44 #include <stdlib.h>
   45 #include <stddef.h>
   46 #include <math.h>
   47 #include <limits.h>
   48 #include <float.h>
   49 #include <fcntl.h>
   50 #include <time.h>
   51 #include <errno.h>                              /* Recommended by debian */
   52 #include <sys/types.h>
   53
   54 #ifdef HAVE_SYS_SOCKET_H
   55 #include <sys/socket.h>
   56 #endif
   57 #if !defined(_WIN32)
   58 #include <netdb.h>
   59 #endif
   60 #ifdef MY_MSCRT_DEBUG
   61 #include <crtdbg.h>
   62 #endif
   63
   64 /*
   65   A lot of our programs uses asserts, so better to always include it
   66   This also fixes a problem when people uses DBUG_ASSERT without including
   67   assert.h
   68 */
   69 #include <assert.h>
   70
   71 /* Include standard definitions of operator new and delete. */
   72 #ifdef __cplusplus
   73 # include <new>
   74 #endif
   75
   76 #include "my_compiler.h"
   77 #include "my_dbug.h"
   78
   79 /* Macros to make switching between C and C++ mode easier */
   80 #ifdef __cplusplus
   81 #define C_MODE_START    extern "C" {
   82 #define C_MODE_END      }
   83 #else
   84 #define C_MODE_START
   85 #define C_MODE_END
   86 #endif
   87
   88 #ifdef WITH_PERFSCHEMA_STORAGE_ENGINE
   89 #ifdef EMBEDDED_LIBRARY
   90
   91 #ifndef DISABLE_PSI_THREAD
   92 #define DISABLE_PSI_THREAD
   93 #endif
   94
   95 #ifndef DISABLE_PSI_MUTEX
   96 #define DISABLE_PSI_MUTEX
   97 #endif
   98
   99 #ifndef DISABLE_PSI_RWLOCK
  100 #define DISABLE_PSI_RWLOCK
  101 #endif
  102
  103 #ifndef DISABLE_PSI_COND
  104 #define DISABLE_PSI_COND
  105 #endif
  106
  107 #ifndef DISABLE_PSI_FILE
  108 #define DISABLE_PSI_FILE
  109 #endif
  110
  111 #ifndef DISABLE_PSI_TABLE
  112 #define DISABLE_PSI_TABLE
  113 #endif
  114
  115 #ifndef DISABLE_PSI_SOCKET
  116 #define DISABLE_PSI_SOCKET
  117 #endif
  118
  119 #ifndef DISABLE_PSI_STAGE
  120 #define DISABLE_PSI_STAGE
  121 #endif
  122
  123 #ifndef DISABLE_PSI_STATEMENT
  124 #define DISABLE_PSI_STATEMENT
  125 #endif
  126
  127 #ifndef DISABLE_PSI_SP
  128 #define DISABLE_PSI_SP
  129 #endif
  130
  131 #ifndef DISABLE_PSI_PS
  132 #define DISABLE_PSI_PS
  133 #endif
  134
  135 #ifndef DISABLE_PSI_ERROR
  136 #define DISABLE_PSI_ERROR
  137 #endif
  138
  139 #ifndef DISABLE_PSI_IDLE
  140 #define DISABLE_PSI_IDLE
  141 #endif
  142
  143 #ifndef DISABLE_PSI_STATEMENT_DIGEST
  144 #define DISABLE_PSI_STATEMENT_DIGEST
  145 #endif
  146
  147 #ifndef DISABLE_PSI_METADATA
  148 #define DISABLE_PSI_METADATA
  149 #endif
  150
  151 #ifndef DISABLE_PSI_MEMORY
  152 #define DISABLE_PSI_MEMORY
  153 #endif
  154
  155 #ifndef DISABLE_PSI_TRANSACTION
  156 #define DISABLE_PSI_TRANSACTION
  157 #endif
  158
  159 #endif /* EMBEDDED_LIBRARY */
  160 #endif /* WITH_PERFSCHEMA_STORAGE_ENGINE */
  161
  162 #ifdef WITH_PERFSCHEMA_STORAGE_ENGINE
  163 #define HAVE_PSI_INTERFACE
  164 #endif /* WITH_PERFSCHEMA_STORAGE_ENGINE */
  165
  166 #ifdef HAVE_PSI_INTERFACE
  167
  168  /**
  169   @def DISABLE_PSI_MUTEX
  170   Compiling option to disable the mutex instrumentation.
  171   This option is mostly intended to be used during development,
  172   when doing special builds with only a subset of the performance schema instrumentation,
  173   for code analysis / profiling / performance tuning of a specific instrumentation alone.
  174   @sa DISABLE_PSI_RWLOCK
  175   @sa DISABLE_PSI_COND
  176   @sa DISABLE_PSI_FILE
  177   @sa DISABLE_PSI_THREAD
  178   @sa DISABLE_PSI_TABLE
  179   @sa DISABLE_PSI_STAGE
  180   @sa DISABLE_PSI_STATEMENT
  181   @sa DISABLE_PSI_SP
  182   @sa DISABLE_PSI_PS
  183   @sa DISABLE_PSI_STATEMENT_DIGEST
  184   @sa DISABLE_PSI_SOCKET
  185   @sa DISABLE_PSI_MEMORY
  186   @sa DISABLE_PSI_ERROR
  187   @sa DISABLE_PSI_IDLE
  188   @sa DISABLE_PSI_METADATA
  189   @sa DISABLE_PSI_TRANSACTION
  190 */
  191
  192 #ifndef DISABLE_PSI_MUTEX
  193 #define HAVE_PSI_MUTEX_INTERFACE
  194 #endif /* DISABLE_PSI_MUTEX */
  195
  196 /**
  197   @def DISABLE_PSI_RWLOCK
  198   Compiling option to disable the rwlock instrumentation.
  199   @sa DISABLE_PSI_MUTEX
  200 */
  201
  202 #ifndef DISABLE_PSI_RWLOCK
  203 #define HAVE_PSI_RWLOCK_INTERFACE
  204 #endif /* DISABLE_PSI_RWLOCK */
  205
  206 /**
  207   @def DISABLE_PSI_COND
  208   Compiling option to disable the cond instrumentation.
  209   @sa DISABLE_PSI_MUTEX
  210 */
  211
  212 #ifndef DISABLE_PSI_COND
  213 #define HAVE_PSI_COND_INTERFACE
  214 #endif /* DISABLE_PSI_COND */
  215
  216 /**
  217   @def DISABLE_PSI_FILE
  218   Compiling option to disable the file instrumentation.
  219   @sa DISABLE_PSI_MUTEX
  220 */
  221
  222 #ifndef DISABLE_PSI_FILE
  223 #define HAVE_PSI_FILE_INTERFACE
  224 #endif /* DISABLE_PSI_FILE */
  225
  226 /**
  227   @def DISABLE_PSI_THREAD
  228   Compiling option to disable the thread instrumentation.
  229   @sa DISABLE_PSI_MUTEX
  230 */
  231
  232 #ifndef DISABLE_PSI_THREAD
  233 #define HAVE_PSI_THREAD_INTERFACE
  234 #endif /* DISABLE_PSI_THREAD */
  235
  236 /**
  237   @def DISABLE_PSI_TABLE
  238   Compiling option to disable the table instrumentation.
  239   @sa DISABLE_PSI_MUTEX
  240 */
  241
  242 #ifndef DISABLE_PSI_TABLE
  243 #define HAVE_PSI_TABLE_INTERFACE
  244 #endif /* DISABLE_PSI_TABLE */
  245
  246 /**
  247   @def DISABLE_PSI_STAGE
  248   Compiling option to disable the stage instrumentation.
  249   @sa DISABLE_PSI_MUTEX
  250 */
  251
  252 #ifndef DISABLE_PSI_STAGE
  253 #define HAVE_PSI_STAGE_INTERFACE
  254 #endif /* DISABLE_PSI_STAGE */
  255
  256 /**
  257   @def DISABLE_PSI_STATEMENT
  258   Compiling option to disable the statement instrumentation.
  259   @sa DISABLE_PSI_MUTEX
  260 */
  261
  262 #ifndef DISABLE_PSI_STATEMENT
  263 #define HAVE_PSI_STATEMENT_INTERFACE
  264 #endif /* DISABLE_PSI_STATEMENT */
  265
  266 /**
  267   @def DISABLE_PSI_SP
  268   Compiling option to disable the stored program instrumentation.
  269   @sa DISABLE_PSI_MUTEX
  270 */
  271
  272 #ifndef DISABLE_PSI_SP
  273 #define HAVE_PSI_SP_INTERFACE
  274 #endif /* DISABLE_PSI_SP */
  275
  276 /**
  277   @def DISABLE_PSI_PS
  278   Compiling option to disable the prepared statement instrumentation.
  279   @sa DISABLE_PSI_MUTEX
  280 */
  281
  282 #ifndef DISABLE_PSI_STATEMENT
  283 #ifndef DISABLE_PSI_PS
  284 #define HAVE_PSI_PS_INTERFACE
  285 #endif /* DISABLE_PSI_PS */
  286 #endif /* DISABLE_PSI_STATEMENT */
  287
  288 /**
  289   @def DISABLE_PSI_STATEMENT_DIGEST
  290   Compiling option to disable the statement digest instrumentation.
  291 */
  292
  293 #ifndef DISABLE_PSI_STATEMENT
  294 #ifndef DISABLE_PSI_STATEMENT_DIGEST
  295 #define HAVE_PSI_STATEMENT_DIGEST_INTERFACE
  296 #endif /* DISABLE_PSI_STATEMENT_DIGEST */
  297 #endif /* DISABLE_PSI_STATEMENT */
  298
  299 /**
  300   @def DISABLE_PSI_TRANSACTION
  301   Compiling option to disable the transaction instrumentation.
  302   @sa DISABLE_PSI_MUTEX
  303 */
  304
  305 #ifndef DISABLE_PSI_TRANSACTION
  306 #define HAVE_PSI_TRANSACTION_INTERFACE
  307 #endif /* DISABLE_PSI_TRANSACTION */
  308
  309 /**
  310   @def DISABLE_PSI_SOCKET
  311   Compiling option to disable the statement instrumentation.
  312   @sa DISABLE_PSI_MUTEX
  313 */
  314
  315 #ifndef DISABLE_PSI_SOCKET
  316 #define HAVE_PSI_SOCKET_INTERFACE
  317 #endif /* DISABLE_PSI_SOCKET */
  318
  319 /**
  320   @def DISABLE_PSI_MEMORY
  321   Compiling option to disable the memory instrumentation.
  322   @sa DISABLE_PSI_MUTEX
  323 */
  324
  325 #ifndef DISABLE_PSI_MEMORY
  326 #define HAVE_PSI_MEMORY_INTERFACE
  327 #endif /* DISABLE_PSI_MEMORY */
  328
  329 /**
  330   @def DISABLE_PSI_ERROR
  331   Compiling option to disable the error instrumentation.
  332   @sa DISABLE_PSI_MUTEX
  333 */
  334
  335 #ifndef DISABLE_PSI_ERROR
  336 #define HAVE_PSI_ERROR_INTERFACE
  337 #endif /* DISABLE_PSI_ERROR */
  338
  339 /**
  340   @def DISABLE_PSI_IDLE
  341   Compiling option to disable the idle instrumentation.
  342   @sa DISABLE_PSI_MUTEX
  343 */
  344
  345 #ifndef DISABLE_PSI_IDLE
  346 #define HAVE_PSI_IDLE_INTERFACE
  347 #endif /* DISABLE_PSI_IDLE */
  348
  349 /**
  350   @def DISABLE_PSI_METADATA
  351   Compiling option to disable the metadata instrumentation.
  352   @sa DISABLE_PSI_MUTEX
  353 */
  354
  355 #ifndef DISABLE_PSI_METADATA
  356 #define HAVE_PSI_METADATA_INTERFACE
  357 #endif /* DISABLE_PSI_METADATA */
  358
  359 #endif /* HAVE_PSI_INTERFACE */
  360
  361 /* Make it easier to add conditional code in _expressions_ */
  362 #ifdef _WIN32
  363 #define IF_WIN(A,B) A
  364 #else
  365 #define IF_WIN(A,B) B
  366 #endif
  367
  368 #if defined (_WIN32)
  369 /*
  370  off_t is 32 bit long. We do not use C runtime functions
  371  with off_t but native Win32 file IO APIs, that work with
  372  64 bit offsets.
  373 */
  374 #undef SIZEOF_OFF_T
  375 #define SIZEOF_OFF_T 8
  376
  377 static inline void sleep(unsigned long seconds)
  378 {
  379   Sleep(seconds * 1000);
  380 }
  381
  382 /* Define missing access() modes. */
  383 #define F_OK 0
  384 #define W_OK 2
  385 #define R_OK 4                        /* Test for read permission.  */
  386
  387 /* Define missing file locking constants. */
  388 #define F_RDLCK 1
  389 #define F_WRLCK 2
  390 #define F_UNLCK 3
  391 #define F_TO_EOF 0x3FFFFFFF
  392
  393 #define O_NONBLOCK 1    /* For emulation of fcntl() */
  394
  395 /*
  396   SHUT_RDWR is called SD_BOTH in windows and
  397   is defined to 2 in winsock2.h
  398   #define SD_BOTH 0x02
  399 */
  400 #define SHUT_RDWR 0x02
  401
  402 /* Shared memory and named pipe connections are supported. */
  403 #define shared_memory_buffer_length 16000
  404 #define default_shared_memory_base_name "MYSQL"
  405 #endif /* _WIN32*/
  406
  407 /* an assert that works at compile-time. only for constant expression */
  408 #define compile_time_assert(X)                                              \
  409   do                                                                        \
  410   {                                                                         \
  411     typedef char compile_time_assert[(X) ? 1 : -1] MY_ATTRIBUTE((unused)); \
  412   } while(0)
  413
  414 /*
  415   Two levels of macros are needed to stringify the
  416   result of expansion of a macro argument.
  417 */
  418 #define QUOTE_ARG(x)            #x      /* Quote argument (before cpp) */
  419 #define STRINGIFY_ARG(x) QUOTE_ARG(x)   /* Quote argument, after cpp */
  420
  421 #if !defined(HAVE_UINT)
  422 typedef unsigned int uint;
  423 typedef unsigned short ushort;
  424 #endif
  425
  426 #define MY_TEST(a)              ((a) ? 1 : 0)
  427 #define MY_MAX(a, b)    ((a) > (b) ? (a) : (b))
  428 #define MY_MIN(a, b)    ((a) < (b) ? (a) : (b))
  429 #define set_if_bigger(a,b)  do { if ((a) < (b)) (a)=(b); } while(0)
  430 #define set_if_smaller(a,b) do { if ((a) > (b)) (a)=(b); } while(0)
  431 #define test_all_bits(a,b) (((a) & (b)) == (b))
  432 #define array_elements(A) ((uint) (sizeof(A)/sizeof(A[0])))
  433
  434 /* Define some general constants */
  435 #ifndef TRUE
  436 #define TRUE            (1)     /* Logical true */
  437 #define FALSE           (0)     /* Logical false */
  438 #endif
  439
  440 /* Some types that is different between systems */
  441
  442 typedef int     File;           /* File descriptor */
  443 #ifdef _WIN32
  444 typedef SOCKET my_socket;
  445 #else
  446 typedef int     my_socket;      /* File descriptor for sockets */
  447 #define INVALID_SOCKET -1
  448 #endif
  449 #if defined(__GNUC__)
  450 typedef char    pchar;          /* Mixed prototypes can take char */
  451 typedef char    pbool;          /* Mixed prototypes can take char */
  452 #else
  453 typedef int     pchar;          /* Mixed prototypes can't take char */
  454 typedef int     pbool;          /* Mixed prototypes can't take char */
  455 #endif
  456 #ifdef _WIN32
  457 typedef int       socket_len_t;
  458 typedef int       sigset_t;
  459 typedef int       mode_t;
  460 typedef SSIZE_T   ssize_t;
  461 #else
  462 typedef socklen_t socket_len_t;
  463 #endif
  464
  465 /* file create flags */
  466
  467 #ifdef _WIN32
  468 /* Only for my_fopen() - _O_BINARY is set by default for my_open() */
  469 #define MY_FOPEN_BINARY _O_BINARY
  470 #else
  471 #define MY_FOPEN_BINARY 0       /* Ignore on non-Windows */
  472 #endif
  473
  474 #ifdef HAVE_FCNTL
  475 #define F_TO_EOF        0L      /* Param to lockf() to lock rest of file */
  476 #endif
  477
  478 #ifdef _WIN32
  479 #define O_NOFOLLOW      0       /* Ignore on Windows */
  480 #endif
  481
  482 /* additional file share flags for win32 */
  483 #ifdef _WIN32
  484 #define _SH_DENYRWD     0x110    /* deny read/write mode & delete */
  485 #define _SH_DENYWRD     0x120    /* deny write mode & delete      */
  486 #define _SH_DENYRDD     0x130    /* deny read mode & delete       */
  487 #define _SH_DENYDEL     0x140    /* deny delete only              */
  488 #endif /* _WIN32 */
  489
  490
  491 /* General constants */
  492 #define FN_LEN          256     /* Max file name len */
  493 #define FN_HEADLEN      253     /* Max length of filepart of file name */
  494 #define FN_EXTLEN       20      /* Max length of extension (part of FN_LEN) */
  495 #define FN_REFLEN       512     /* Max length of full path-name */
  496 #define FN_REFLEN_SE    4000    /* Max length of full path-name in SE */
  497 #define FN_EXTCHAR      '.'
  498 #define FN_HOMELIB      '~'     /* ~/ is used as abbrev for home dir */
  499 #define FN_CURLIB       '.'     /* ./ is used as abbrev for current dir */
  500 #define FN_PARENTDIR    ".."    /* Parent directory; Must be a string */
  501
  502 #ifdef _WIN32
  503 #define FN_LIBCHAR      '\\'
  504 #define FN_LIBCHAR2     '/'
  505 #define FN_DIRSEP       "/\\"               /* Valid directory separators */
  506 #define FN_EXEEXT   ".exe"
  507 #define FN_SOEXT    ".dll"
  508 #define FN_ROOTDIR      "\\"
  509 #define FN_DEVCHAR      ':'
  510 #define FN_NETWORK_DRIVES       /* Uses \\ to indicate network drives */
  511 #else
  512 #define FN_LIBCHAR      '/'
  513 /*
  514   FN_LIBCHAR2 is not defined on !Windows. Use is_directory_separator().
  515 */
  516 #define FN_DIRSEP       "/"     /* Valid directory separators */
  517 #define FN_EXEEXT   ""
  518 #define FN_SOEXT    ".so"
  519 #define FN_ROOTDIR      "/"
  520 #endif
  521
  522 static inline int is_directory_separator(char c)
  523 {
  524 #ifdef _WIN32
  525   return c == FN_LIBCHAR || c == FN_LIBCHAR2;
  526 #else
  527   return c == FN_LIBCHAR;
  528 #endif
  529 }
  530
  531 /*
  532   MY_FILE_MIN is  Windows speciality and is used to quickly detect
  533   the mismatch of CRT and mysys file IO usage on Windows at runtime.
  534   CRT file descriptors can be in the range 0-2047, whereas descriptors returned
  535   by my_open() will start with 2048. If a file descriptor with value less then
  536   MY_FILE_MIN is passed to mysys IO function, chances are it stemms from
  537   open()/fileno() and not my_open()/my_fileno.
  538
  539   For Posix,  mysys functions are light wrappers around libc, and MY_FILE_MIN
  540   is logically 0.
  541 */
  542
  543 #ifdef _WIN32
  544 #define MY_FILE_MIN  2048
  545 #else
  546 #define MY_FILE_MIN  0
  547 #endif
  548
  549 /*
  550   MY_NFILE is the default size of my_file_info array.
  551
  552   It is larger on Windows, because it all file handles are stored in my_file_info
  553   Default size is 16384 and this should be enough for most cases.If it is not
  554   enough, --max-open-files with larger value can be used.
  555
  556   For Posix , my_file_info array is only used to store filenames for
  557   error reporting and its size is not a limitation for number of open files.
  558 */
  559 #ifdef _WIN32
  560 #define MY_NFILE (16384 + MY_FILE_MIN)
  561 #else
  562 #define MY_NFILE 64
  563 #endif
  564
  565 #define OS_FILE_LIMIT   UINT_MAX
  566
  567 /*
  568   Io buffer size; Must be a power of 2 and a multiple of 512. May be
  569   smaller what the disk page size. This influences the speed of the
  570   isam btree library. eg to big to slow.
  571 */
  572 #define IO_SIZE                 4096
  573 /*
  574   How much overhead does malloc have. The code often allocates
  575   something like 1024-MALLOC_OVERHEAD bytes
  576 */
  577 #define MALLOC_OVERHEAD 8
  578
  579         /* get memory in huncs */
  580 #define ONCE_ALLOC_INIT         (uint) (4096-MALLOC_OVERHEAD)
  581         /* Typical record cash */
  582 #define RECORD_CACHE_SIZE       (uint) (64*1024-MALLOC_OVERHEAD)
  583
  584
  585 /* Some defines of functions for portability */
  586
  587 #ifdef _WIN32
  588 #if !defined(_WIN64)
  589 inline double my_ulonglong2double(unsigned long long value)
  590 {
  591   long long nr=(long long) value;
  592   if (nr >= 0)
  593     return (double) nr;
  594   return (18446744073709551616.0 + (double) nr);
  595 }
  596 #define ulonglong2double my_ulonglong2double
  597 #define my_off_t2double  my_ulonglong2double
  598 #endif /* _WIN64 */
  599 inline unsigned long long my_double2ulonglong(double d)
  600 {
  601   double t= d - (double) 0x8000000000000000ULL;
  602
  603   if (t >= 0)
  604     return  ((unsigned long long) t) + 0x8000000000000000ULL;
  605   return (unsigned long long) d;
  606 }
  607 #define double2ulonglong my_double2ulonglong
  608 #endif /* _WIN32 */
  609
  610 #ifndef ulonglong2double
  611 #define ulonglong2double(A) ((double) (ulonglong) (A))
  612 #define my_off_t2double(A)  ((double) (my_off_t) (A))
  613 #endif
  614 #ifndef double2ulonglong
  615 #define double2ulonglong(A) ((ulonglong) (double) (A))
  616 #endif
  617
  618 #define INT_MIN64       (~0x7FFFFFFFFFFFFFFFLL)
  619 #define INT_MAX64       0x7FFFFFFFFFFFFFFFLL
  620 #define INT_MIN32       (~0x7FFFFFFFL)
  621 #define INT_MAX32       0x7FFFFFFFL
  622 #define UINT_MAX32      0xFFFFFFFFL
  623 #define INT_MIN24       (~0x007FFFFF)
  624 #define INT_MAX24       0x007FFFFF
  625 #define UINT_MAX24      0x00FFFFFF
  626 #define INT_MIN16       (~0x7FFF)
  627 #define INT_MAX16       0x7FFF
  628 #define UINT_MAX16      0xFFFF
  629 #define INT_MIN8        (~0x7F)
  630 #define INT_MAX8        0x7F
  631 #define UINT_MAX8       0xFF
  632
  633 #ifndef SIZE_T_MAX
  634 #define SIZE_T_MAX      (~((size_t) 0))
  635 #endif
  636
  637 #if defined(__cplusplus)
  638   /*
  639     For C++ use the new C++11 std functions rather than C99 macros.
  640     For C use C99 macros - see storage/myisam/rt_split.c
  641   */
  642   #define my_isfinite please_use_std_isfinite_rather_than_my_isfinite
  643   #define my_isnan(X) please_use_std_isnan_rather_than_my_isnan
  644   #define my_isinf(X) please_use_std_isinf_rather_than_my_isinf
  645 #endif /* __cplusplus */
  646
  647 /*
  648   Max size that must be added to a so that we know Size to make
  649   adressable obj.
  650 */
  651 #if SIZEOF_CHARP == 4
  652 typedef long            my_ptrdiff_t;
  653 #else
  654 typedef long long       my_ptrdiff_t;
  655 #endif
  656
  657 #define MY_ALIGN(A,L)   (((A) + (L) - 1) & ~((L) - 1))
  658 #define ALIGN_SIZE(A)   MY_ALIGN((A),sizeof(double))
  659 /* Size to make adressable obj. */
  660 #define ADD_TO_PTR(ptr,size,type) (type) ((uchar*) (ptr)+size)
  661 #define PTR_BYTE_DIFF(A,B) (my_ptrdiff_t) ((uchar*) (A) - (uchar*) (B))
  662
  663 /*
  664   Custom version of standard offsetof() macro which can be used to get
  665   offsets of members in class for non-POD types (according to the current
  666   version of C++ standard offsetof() macro can't be used in such cases and
  667   attempt to do so causes warnings to be emitted, OTOH in many cases it is
  668   still OK to assume that all instances of the class has the same offsets
  669   for the same members).
  670
  671   This is temporary solution which should be removed once File_parser class
  672   and related routines are refactored.
  673 */
  674
  675 #define my_offsetof(TYPE, MEMBER) \
  676         ((size_t)((char *)&(((TYPE *)0x10)->MEMBER) - (char*)0x10))
  677
  678 #define NullS           (char *) 0
  679
  680 #ifdef _WIN32
  681 #define STDCALL __stdcall
  682 #else
  683 #define STDCALL
  684 #endif
  685
  686 /* Typdefs for easyier portability */
  687
  688 typedef unsigned char   uchar;  /* Short for unsigned char */
  689 typedef signed char int8;       /* Signed integer >= 8  bits */
  690 typedef unsigned char uint8;    /* Unsigned integer >= 8  bits */
  691 typedef short int16;
  692 typedef unsigned short uint16;
  693 #if SIZEOF_INT == 4
  694 typedef int int32;
  695 typedef unsigned int uint32;
  696 #elif SIZEOF_LONG == 4
  697 typedef long int32;
  698 typedef unsigned long uint32;
  699 #else
  700 #error Neither int or long is of 4 bytes width
  701 #endif
  702
  703 #if !defined(HAVE_ULONG)
  704 typedef unsigned long   ulong;            /* Short for unsigned long */
  705 #endif
  706 /*
  707   Using [unsigned] long long is preferable as [u]longlong because we use
  708   [unsigned] long long unconditionally in many places,
  709   for example in constants with [U]LL suffix.
  710 */
  711 typedef unsigned long long int ulonglong; /* ulong or unsigned long long */
  712 typedef long long int   longlong;
  713 typedef longlong int64;
  714 typedef ulonglong uint64;
  715
  716 #if defined (_WIN32)
  717 typedef unsigned __int64 my_ulonglong;
  718 #else
  719 typedef unsigned long long my_ulonglong;
  720 #endif
  721
  722 #if SIZEOF_CHARP == SIZEOF_INT
  723 typedef int intptr;
  724 #elif SIZEOF_CHARP == SIZEOF_LONG
  725 typedef long intptr;
  726 #elif SIZEOF_CHARP == SIZEOF_LONG_LONG
  727 typedef long long intptr;
  728 #else
  729 #error sizeof(void *) is neither sizeof(int) nor sizeof(long) nor sizeof(long long)
  730 #endif
  731
  732 #if defined(_WIN32)
  733 typedef unsigned long long my_off_t;
  734 #else
  735 #if SIZEOF_OFF_T > 4
  736 typedef ulonglong my_off_t;
  737 #else
  738 typedef unsigned long my_off_t;
  739 #endif
  740 #endif /*_WIN32*/
  741 #define MY_FILEPOS_ERROR        (~(my_off_t) 0)
  742
  743 /*
  744   TODO Convert these to use Bitmap class.
  745  */
  746 typedef ulonglong table_map;          /* Used for table bits in join */
  747 typedef ulonglong nesting_map;  /* Used for flags of nesting constructs */
  748
  749 #if defined(_WIN32)
  750 #define socket_errno    WSAGetLastError()
  751 #define SOCKET_EINTR    WSAEINTR
  752 #define SOCKET_EAGAIN   WSAEINPROGRESS
  753 #define SOCKET_EWOULDBLOCK WSAEWOULDBLOCK
  754 #define SOCKET_EADDRINUSE WSAEADDRINUSE
  755 #define SOCKET_ETIMEDOUT WSAETIMEDOUT
  756 #define SOCKET_ECONNRESET WSAECONNRESET
  757 #define SOCKET_ENFILE   ENFILE
  758 #define SOCKET_EMFILE   EMFILE
  759 #else /* Unix */
  760 #define socket_errno    errno
  761 #define closesocket(A)  close(A)
  762 #define SOCKET_EINTR    EINTR
  763 #define SOCKET_EAGAIN   EAGAIN
  764 #define SOCKET_EWOULDBLOCK EWOULDBLOCK
  765 #define SOCKET_EADDRINUSE EADDRINUSE
  766 #define SOCKET_ETIMEDOUT ETIMEDOUT
  767 #define SOCKET_ECONNRESET ECONNRESET
  768 #define SOCKET_ENFILE   ENFILE
  769 #define SOCKET_EMFILE   EMFILE
  770 #endif
  771
  772 typedef int             myf;    /* Type of MyFlags in my_funcs */
  773 typedef char            my_bool; /* Small bool */
  774
  775 #if !defined(__cplusplus) && !defined(bool)
  776 #define bool In_C_you_should_use_my_bool_instead()
  777 #endif
  778
  779 /* Macros for converting *constants* to the right type */
  780 #define MYF(v)          (myf) (v)
  781
  782 #if defined(_WIN32)
  783 #define dlsym(lib, name) (void*)GetProcAddress((HMODULE)lib, name)
  784 #define dlopen(libname, unused) LoadLibraryEx(libname, NULL, 0)
  785 #define dlclose(lib) FreeLibrary((HMODULE)lib)
  786 #define DLERROR_GENERATE(errmsg, error_number) \
  787   char win_errormsg[2048]; \
  788   if(FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, \
  789                    0, error_number, 0, win_errormsg, 2048, NULL)) \
  790   { \
  791     char *ptr; \
  792     for (ptr= &win_errormsg[0] + strlen(win_errormsg) - 1; \
  793          ptr >= &win_errormsg[0] && strchr("\r\n\t\0x20", *ptr); \
  794          ptr--) \
  795       *ptr= 0; \
  796     errmsg= win_errormsg; \
  797   } \
  798   else \
  799     errmsg= ""
  800 #define dlerror() ""
  801 #define dlopen_errno GetLastError()
  802
  803 #else /* _WIN32 */
  804 #define DLERROR_GENERATE(errmsg, error_number) errmsg= dlerror()
  805 #define dlopen_errno errno
  806 #endif /* _WIN32 */
  807
  808 /* Length of decimal number represented by INT32. */
  809 #define MY_INT32_NUM_DECIMAL_DIGITS 11U
  810
  811 /* Length of decimal number represented by INT64. */
  812 #define MY_INT64_NUM_DECIMAL_DIGITS 21U
  813
  814 /*
  815   MYSQL_PLUGIN_IMPORT macro is used to export mysqld data
  816   (i.e variables) for usage in storage engine loadable plugins.
  817   Outside of Windows, it is dummy.
  818 */
  819 #if (defined(_WIN32) && defined(MYSQL_DYNAMIC_PLUGIN))
  820 #define MYSQL_PLUGIN_IMPORT __declspec(dllimport)
  821 #else
  822 #define MYSQL_PLUGIN_IMPORT
  823 #endif
  824
  825 #ifdef EMBEDDED_LIBRARY
  826 #define NO_EMBEDDED_ACCESS_CHECKS
  827 /* Things we don't need in the embedded version of MySQL */
  828 #undef HAVE_OPENSSL
  829 #endif /* EMBEDDED_LIBRARY */
  830
  831
  832 enum loglevel {
  833    ERROR_LEVEL=       0,
  834    WARNING_LEVEL=     1,
  835    INFORMATION_LEVEL= 2
  836 };
  837
  838
  839 #ifdef _WIN32
  840 /****************************************************************************
  841 ** Replacements for localtime_r and gmtime_r
  842 ****************************************************************************/
  843
  844 static inline struct tm *localtime_r(const time_t *timep, struct tm *tmp)
  845 {
  846   localtime_s(tmp, timep);
  847   return tmp;
  848 }
  849
  850 static inline struct tm *gmtime_r(const time_t *clock, struct tm *res)
  851 {
  852   gmtime_s(res, clock);
  853   return res;
  854 }
  855 #endif /* _WIN32 */
  856
  857 C_MODE_START
  858 ulonglong my_getsystime(void);
  859
  860 void set_timespec_nsec(struct timespec *abstime, ulonglong nsec);
  861
  862 void set_timespec(struct timespec *abstime, ulonglong sec);
  863 C_MODE_END
  864
  865 /**
  866    Compare two timespec structs.
  867
  868    @retval  1 If ts1 ends after ts2.
  869    @retval -1 If ts1 ends before ts2.
  870    @retval  0 If ts1 is equal to ts2.
  871 */
  872 static inline int cmp_timespec(struct timespec *ts1, struct timespec *ts2)
  873 {
  874   if (ts1->tv_sec > ts2->tv_sec ||
  875       (ts1->tv_sec == ts2->tv_sec && ts1->tv_nsec > ts2->tv_nsec))
  876     return 1;
  877   if (ts1->tv_sec < ts2->tv_sec ||
  878       (ts1->tv_sec == ts2->tv_sec && ts1->tv_nsec < ts2->tv_nsec))
  879     return -1;
  880   return 0;
  881 }
  882
  883 static inline ulonglong diff_timespec(struct timespec *ts1, struct timespec *ts2)
  884 {
  885   return (ts1->tv_sec - ts2->tv_sec) * 1000000000ULL +
  886     ts1->tv_nsec - ts2->tv_nsec;
  887 }
  888
  889 #ifdef _WIN32
  890 typedef int MY_MODE;
  891 #else
  892 typedef mode_t MY_MODE;
  893 #endif /* _WIN32 */
  894
  895 /* File permissions */
  896 #define USER_READ       (1L << 0)
  897 #define USER_WRITE      (1L << 1)
  898 #define USER_EXECUTE    (1L << 2)
  899 #define GROUP_READ      (1L << 3)
  900 #define GROUP_WRITE     (1L << 4)
  901 #define GROUP_EXECUTE   (1L << 5)
  902 #define OTHERS_READ     (1L << 6)
  903 #define OTHERS_WRITE    (1L << 7)
  904 #define OTHERS_EXECUTE  (1L << 8)
  905 #define USER_RWX        USER_READ | USER_WRITE | USER_EXECUTE
  906 #define GROUP_RWX       GROUP_READ | GROUP_WRITE | GROUP_EXECUTE
  907 #define OTHERS_RWX      OTHERS_READ | OTHERS_WRITE | OTHERS_EXECUTE
  908
  909 /* Defaults */
  910 #define DEFAULT_SSL_CA_CERT     "ca.pem"
  911 #define DEFAULT_SSL_CA_KEY      "ca-key.pem"
  912 #define DEFAULT_SSL_SERVER_CERT "server-cert.pem"
  913 #define DEFAULT_SSL_SERVER_KEY  "server-key.pem"
  914
  915 #ifdef __cplusplus
  916 /*
  917   Define rapidjson::SizeType to be std::size_t. See
  918   extra/rapidjson/include/rapidjson/rapidjson.h for more details.
  919 */
  920 namespace rapidjson { typedef ::std::size_t SizeType; }
  921 #endif
  922
  923 #endif  // MY_GLOBAL_INCLUDED
