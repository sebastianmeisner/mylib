#ifndef STDENV_H_INCLUDED
#define STDENV_H_INCLUDED

/*
 * This include file echoes information about your compiler environment.
 * It tries to cover all standardized defines.
 * Not usable with Microsoft compilers as they don't support the #warning statement.
 */

#if __STDC_HOSTED__ == 1
    #warning "Compiling for a hosted C ennvironment"
#else
    #warning "Compiling for a freestanding C ennvironment"
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ < 199409L)
    #warning "Compiling C89"
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199409L)
    #warning "Compiling C95"
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 199901L)
    #warning "Compiling C99"
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L)
    #warning "Compiling C11"
#endif

#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201710L)
    #warning "Compiling C17"
#endif


#endif // STDENV_H_INCLUDED
