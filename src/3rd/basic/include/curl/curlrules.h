#ifndef __CURL_CURLRULES_H
#define __CURL_CURLRULES_H

#ifndef CURL_SIZEOF_LONG
#  error "CURL_SIZEOF_LONG definition is missing!"
   Error Compilation_aborted_CURL_SIZEOF_LONG_is_missing
#endif

#ifndef CURL_TYPEOF_CURL_SOCKLEN_T
#  error "CURL_TYPEOF_CURL_SOCKLEN_T definition is missing!"
   Error Compilation_aborted_CURL_TYPEOF_CURL_SOCKLEN_T_is_missing
#endif

#ifndef CURL_SIZEOF_CURL_SOCKLEN_T
#  error "CURL_SIZEOF_CURL_SOCKLEN_T definition is missing!"
   Error Compilation_aborted_CURL_SIZEOF_CURL_SOCKLEN_T_is_missing
#endif

#ifndef CURL_TYPEOF_CURL_OFF_T
#  error "CURL_TYPEOF_CURL_OFF_T definition is missing!"
   Error Compilation_aborted_CURL_TYPEOF_CURL_OFF_T_is_missing
#endif

#ifndef CURL_FORMAT_CURL_OFF_T
#  error "CURL_FORMAT_CURL_OFF_T definition is missing!"
   Error Compilation_aborted_CURL_FORMAT_CURL_OFF_T_is_missing
#endif

#ifndef CURL_FORMAT_CURL_OFF_TU
#  error "CURL_FORMAT_CURL_OFF_TU definition is missing!"
   Error Compilation_aborted_CURL_FORMAT_CURL_OFF_TU_is_missing
#endif

#ifndef CURL_FORMAT_OFF_T
#  error "CURL_FORMAT_OFF_T definition is missing!"
   Error Compilation_aborted_CURL_FORMAT_OFF_T_is_missing
#endif

#ifndef CURL_SIZEOF_CURL_OFF_T
#  error "CURL_SIZEOF_CURL_OFF_T definition is missing!"
   Error Compilation_aborted_CURL_SIZEOF_CURL_OFF_T_is_missing
#endif

#ifndef CURL_SUFFIX_CURL_OFF_T
#  error "CURL_SUFFIX_CURL_OFF_T definition is missing!"
   Error Compilation_aborted_CURL_SUFFIX_CURL_OFF_T_is_missing
#endif

#ifndef CURL_SUFFIX_CURL_OFF_TU
#  error "CURL_SUFFIX_CURL_OFF_TU definition is missing!"
   Error Compilation_aborted_CURL_SUFFIX_CURL_OFF_TU_is_missing
#endif

/*
 * Macros private to this header file.
 */

#define CurlchkszEQ(t, s) sizeof(t) == s ? 1 : -1

#define CurlchkszGE(t1, t2) sizeof(t1) >= sizeof(t2) ? 1 : -1

/*
 * Verify that the size previously defined and expected for long
 * is the same as the one reported by sizeof() at compile time.
 */

typedef char
  __curl_rule_01__
    [CurlchkszEQ(long, CURL_SIZEOF_LONG)];

/*
 * Verify that the size previously defined and expected for
 * curl_off_t is actually the the same as the one reported
 * by sizeof() at compile time.
 */

typedef char
  __curl_rule_02__
    [CurlchkszEQ(curl_off_t, CURL_SIZEOF_CURL_OFF_T)];

/*
 * Verify at compile time that the size of curl_off_t as reported
 * by sizeof() is greater or equal than the one reported for long
 * for the current compilation.
 */

typedef char
  __curl_rule_03__
    [CurlchkszGE(curl_off_t, long)];

/*
 * Verify that the size previously defined and expected for
 * curl_socklen_t is actually the the same as the one reported
 * by sizeof() at compile time.
 */

typedef char
  __curl_rule_04__
    [CurlchkszEQ(curl_socklen_t, CURL_SIZEOF_CURL_SOCKLEN_T)];

/*
 * Verify at compile time that the size of curl_socklen_t as reported
 * by sizeof() is greater or equal than the one reported for int for
 * the current compilation.
 */

typedef char
  __curl_rule_05__
    [CurlchkszGE(curl_socklen_t, int)];

/* ================================================================ */
/*          EXTERNALLY AND INTERNALLY VISIBLE DEFINITIONS           */
/* ================================================================ */

/*
 * CURL_ISOCPP and CURL_OFF_T_C definitions are done here in order to allow
 * these to be visible and exported by the external libcurl interface API,
 * while also making them visible to the library internals, simply including
 * curl_setup.h, without actually needing to include curl.h internally.
 * If some day this section would grow big enough, all this should be moved
 * to its own header file.
 */

/*
 * Figure out if we can use the ## preprocessor operator, which is supported
 * by ISO/ANSI C and C++. Some compilers support it without setting __STDC__
 * or  __cplusplus so we need to carefully check for them too.
 */

#if defined(__STDC__) || defined(_MSC_VER) || defined(__cplusplus) || \
  defined(__HP_aCC) || defined(__BORLANDC__) || defined(__LCC__) || \
  defined(__POCC__) || defined(__SALFORDC__) || defined(__HIGHC__) || \
  defined(__ILEC400__)
  /* This compiler is believed to have an ISO compatible preprocessor */
#define CURL_ISOCPP
#else
  /* This compiler is believed NOT to have an ISO compatible preprocessor */
#undef CURL_ISOCPP
#endif

/*
 * Macros for minimum-width signed and unsigned curl_off_t integer constants.
 */

#if defined(__BORLANDC__) && (__BORLANDC__ == 0x0551)
#  define __CURL_OFF_T_C_HLPR2(x) x
#  define __CURL_OFF_T_C_HLPR1(x) __CURL_OFF_T_C_HLPR2(x)
#  define CURL_OFF_T_C(Val)  __CURL_OFF_T_C_HLPR1(Val) ## \
                             __CURL_OFF_T_C_HLPR1(CURL_SUFFIX_CURL_OFF_T)
#  define CURL_OFF_TU_C(Val) __CURL_OFF_T_C_HLPR1(Val) ## \
                             __CURL_OFF_T_C_HLPR1(CURL_SUFFIX_CURL_OFF_TU)
#else
#  ifdef CURL_ISOCPP
#    define __CURL_OFF_T_C_HLPR2(Val,Suffix) Val ## Suffix
#  else
#    define __CURL_OFF_T_C_HLPR2(Val,Suffix) Val/**/Suffix
#  endif
#  define __CURL_OFF_T_C_HLPR1(Val,Suffix) __CURL_OFF_T_C_HLPR2(Val,Suffix)
#  define CURL_OFF_T_C(Val)  __CURL_OFF_T_C_HLPR1(Val,CURL_SUFFIX_CURL_OFF_T)
#  define CURL_OFF_TU_C(Val) __CURL_OFF_T_C_HLPR1(Val,CURL_SUFFIX_CURL_OFF_TU)
#endif

/*
 * Get rid of macros private to this header file.
 */

#undef CurlchkszEQ
#undef CurlchkszGE

/*
 * Get rid of macros not intended to exist beyond this point.
 */

#undef CURL_PULL_WS2TCPIP_H
#undef CURL_PULL_SYS_TYPES_H
#undef CURL_PULL_SYS_SOCKET_H
#undef CURL_PULL_SYS_POLL_H
#undef CURL_PULL_STDINT_H
#undef CURL_PULL_INTTYPES_H

#undef CURL_TYPEOF_CURL_SOCKLEN_T
#undef CURL_TYPEOF_CURL_OFF_T

#ifdef CURL_NO_OLDIES
#undef CURL_FORMAT_OFF_T /* not required since 7.19.0 - obsoleted in 7.20.0 */
#endif

#endif /* __CURL_CURLRULES_H */
