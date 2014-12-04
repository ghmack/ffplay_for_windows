// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

/* The ISO C99 standard specifies that these macros must only be
   defined if explicitly requested.  */
#if !defined __cplusplus || defined __STDC_FORMAT_MACROS

# if __WORDSIZE == 64
#  define __PRI64_PREFIX    "l"
#  define __PRIPTR_PREFIX   "l"
# else
#  define __PRI64_PREFIX    "ll"
#  define __PRIPTR_PREFIX
# endif

/* Macros for printing format specifiers.  */

/* Decimal notation.  */
# define PRId8      "d"
# define PRId16     "d"
# define PRId32     "d"
# define PRId64     __PRI64_PREFIX "d"


#endif

// TODO: 在此处引用程序需要的其他头文件
