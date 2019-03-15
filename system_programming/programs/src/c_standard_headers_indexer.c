// List of standard headers was taken in http://en.cppreference.com/w/c/header

#include <assert.h> 	 // Conditionally compiled macro that compares its argument to zero
#include <ctype.h> 	     // Functions to determine the type contained in character data
#include <errno.h> 	     // Macros reporting error conditions
#include <float.h> 	     // Limits of float types
#include <limits.h> 	 // Sizes of basic types
#include <locale.h> 	 // Localization utilities
#include <math.h> 	     // Common mathematics functions
#include <setjmp.h> 	 // Nonlocal jumps
#include <signal.h> 	 // Signal handling
#include <stdarg.h> 	 // Variable arguments
#include <stddef.h> 	 // Common macro definitions
#include <stdio.h> 	     // Input/output
#include <string.h> 	 // String handling
#include <stdlib.h> 	 // General utilities: memory management, program utilities, string conversions, random numbers
#include <time.h>        // Time/date utilities
#include <iso646.h>      // (since C95) Alternative operator spellings
#include <wchar.h>       // (since C95) Extended multibyte and wide character utilities
#include <wctype.h>      // (since C95) Wide character classification and mapping utilities
#ifdef _STDC_C99
#include <complex.h>     // (since C99) Complex number arithmetic
#include <fenv.h>        // (since C99) Floating-point environment
#include <inttypes.h>    // (since C99) Format conversion of integer types
#include <stdbool.h>     // (since C99) Boolean type
#include <stdint.h>      // (since C99) Fixed-width integer types
#include <tgmath.h>      // (since C99) Type-generic math (macros wrapping math.h and complex.h)
#endif
#ifdef _STDC_C11
#include <stdalign.h>    // (since C11) alignas and alignof convenience macros
#include <stdatomic.h>   // (since C11) Atomic types
#include <stdnoreturn.h> // (since C11) noreturn convenience macros
#include <threads.h>     // (since C11) Thread library
#include <uchar.h>       // (since C11) UTF-16 and UTF-32 character utilities
#endif
