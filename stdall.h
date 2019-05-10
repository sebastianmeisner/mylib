#if __STDC_HOSTED__ == 1
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
        #if !defined(__STDC_NO_COMPLEX__)
            #include <complex.h>
        #endif
        #include <fenv.h>
        #include <inttypes.h>
        #include <stdbool.h>
        #include <stdint.h>
        #include <tgmath.h>
    #endif // __STDC_VERSION__

    #if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
        #include <stdalign.h>
        #if !defined(__STDC_NO_ATOMICS__)
            #include <stdatomic.h>
        #endif
        #include <stdnoreturn.h>
        #if !defined(__STDC_NO_THREADS__)
            //#include <threads.h>
        #endif
        #include <uchar.h>
    #endif // __STDC_VERSION__

    #if __STDC_VERSION__ >= 201710L //C17
    // no new include files for this C standard revision
    #endif // __STDC_VERSION__
#else
    #include <float.h>
    #include <iso646.h>
    #include <limits.h>
    #include <stdalign.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdint.h>
    #include <stdnoreturn.h>
#endif // __STDC_HOSTED__




















