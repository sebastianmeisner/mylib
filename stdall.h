#ifdef __STDC_HOSTED__
// If not hosted only <float.h>, <iso646.h>, <limits.h>, <stdalign.h>, <stdarg.h>, <stdbool.h>, <stddef.h>, <stdint.h>, and <stdnoreturn.h> are allowed.
#endif // __STDC_HOSTED__

#if __STDC__ == 1 //C89
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#endif

#if defined(__STDC_VERISON__) && (__STDC_VERSION__ >= 199409L) // C95
#include <iso646.h>
#include <wchar.h>
#include <wctype.h>
#endif // __STDC_VERSION__

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L //C99
#include <complex.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
#endif // __STDC_VERSION__

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
#include <stdalign.h>
#include <stdatomic.h>
#include <stdnoreturn.h>
#if !defined(__STDC_NO_THREADS__)
    //#include <threads.h>
#endif
//#include <uchar.h>
#endif // __STDC_VERSION__

#if __STDC_VERSION__ >= 201710L //C17
// no new include files for this C standard revision
#endif // __STDC_VERSION__





















