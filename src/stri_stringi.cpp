/* This file is part of the 'stringi' package for R.
 * Copyright (c) 2013-2018, Marek Gagolewski and other contributors.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
 * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "stri_stringi.h"
#include <cstring>
#include <cstdlib>
#include <unicode/uclean.h>

#ifndef STRI_ICU_FOUND
#include "uconfig_local.h"
#endif


#define STRI__MK_CALL(symb, name, args) \
   {symb, (DL_FUNC)&name, args}


/**
 * List of functions available via .Call() in R
 *
 * Form:
 * \code{\{"method_name", (DL_FUNC)pointer, number_of_args\}} -
 * this is generated by the STRI__MAKE_CALL_METHOD macro.
 */
const R_CallMethodDef cCallMethods[] = {

//   STRI__MK_CALL("C_stri_charcategories",             stri_charcategories,             0),  // TO BE >= 0.6
//   STRI__MK_CALL("C_stri_chartype",                   stri_chartype,                   1),  // TO BE >= 0.6
// STRI__MK_CALL("C_stri_c_posixst",                    stri_c_posixst,                  1),  // internal
   STRI__MK_CALL("C_stri_cmp_eq",                       stri_cmp_eq,                     2),
   STRI__MK_CALL("C_stri_cmp_neq",                      stri_cmp_neq,                    2),
   STRI__MK_CALL("C_stri_cmp",                          stri_cmp,                        3),
   STRI__MK_CALL("C_stri_cmp_lt",                       stri_cmp_lt,                     3),
   STRI__MK_CALL("C_stri_cmp_le",                       stri_cmp_le,                     3),
   STRI__MK_CALL("C_stri_cmp_gt",                       stri_cmp_gt,                     3),
   STRI__MK_CALL("C_stri_cmp_ge",                       stri_cmp_ge,                     3),
   STRI__MK_CALL("C_stri_cmp_equiv",                    stri_cmp_equiv,                  3),
   STRI__MK_CALL("C_stri_cmp_nequiv",                   stri_cmp_nequiv,                 3),
   STRI__MK_CALL("C_stri_count_boundaries",             stri_count_boundaries,           2),
   STRI__MK_CALL("C_stri_count_charclass",              stri_count_charclass,            2),
   STRI__MK_CALL("C_stri_count_fixed",                  stri_count_fixed,                3),
   STRI__MK_CALL("C_stri_count_coll",                   stri_count_coll,                 3),
   STRI__MK_CALL("C_stri_count_regex",                  stri_count_regex,                3),
   STRI__MK_CALL("C_stri_datetime_symbols",             stri_datetime_symbols,           3),
   STRI__MK_CALL("C_stri_datetime_fields",              stri_datetime_fields,            3),
   STRI__MK_CALL("C_stri_datetime_now",                 stri_datetime_now,               0),
   STRI__MK_CALL("C_stri_datetime_create",              stri_datetime_create,            9),
   STRI__MK_CALL("C_stri_datetime_format",              stri_datetime_format,            4),
   STRI__MK_CALL("C_stri_datetime_parse",               stri_datetime_parse,             5),
   STRI__MK_CALL("C_stri_datetime_add",                 stri_datetime_add,               5),
   STRI__MK_CALL("C_stri_detect_charclass",             stri_detect_charclass,           3),
   STRI__MK_CALL("C_stri_detect_coll",                  stri_detect_coll,                4),
   STRI__MK_CALL("C_stri_detect_fixed",                 stri_detect_fixed,               4),
   STRI__MK_CALL("C_stri_detect_regex",                 stri_detect_regex,               4),
   STRI__MK_CALL("C_stri_dup",                          stri_dup,                        2),
   STRI__MK_CALL("C_stri_duplicated",                   stri_duplicated,                 3),
   STRI__MK_CALL("C_stri_duplicated_any",               stri_duplicated_any,             3),
   STRI__MK_CALL("C_stri_enc_detect",                   stri_enc_detect,                 2),
   STRI__MK_CALL("C_stri_enc_detect2",                  stri_enc_detect2,                2),
   STRI__MK_CALL("C_stri_enc_isutf8",                   stri_enc_isutf8,                 1),
   STRI__MK_CALL("C_stri_enc_isutf16le",                stri_enc_isutf16le,              1),
   STRI__MK_CALL("C_stri_enc_isutf16be",                stri_enc_isutf16be,              1),
   STRI__MK_CALL("C_stri_enc_isutf32le",                stri_enc_isutf32le,              1),
   STRI__MK_CALL("C_stri_enc_isutf32be",                stri_enc_isutf32be,              1),
   STRI__MK_CALL("C_stri_enc_isascii",                  stri_enc_isascii,                1),
   STRI__MK_CALL("C_stri_enc_info",                     stri_enc_info,                   1),
   STRI__MK_CALL("C_stri_enc_list",                     stri_enc_list,                   0),
   STRI__MK_CALL("C_stri_enc_mark",                     stri_enc_mark,                   1),
   STRI__MK_CALL("C_stri_enc_set",                      stri_enc_set,                    1),
   STRI__MK_CALL("C_stri_enc_fromutf32",                stri_enc_fromutf32,              1),
   STRI__MK_CALL("C_stri_enc_toascii",                  stri_enc_toascii,                1),
   STRI__MK_CALL("C_stri_enc_toutf8",                   stri_enc_toutf8,                 3),
   STRI__MK_CALL("C_stri_enc_toutf32",                  stri_enc_toutf32,                1),
   STRI__MK_CALL("C_stri_encode",                       stri_encode,                     4),
// STRI__MK_CALL("C_stri_encode_from_marked",           stri_encode_from_marked,         3), // internal
   STRI__MK_CALL("C_stri_endswith_charclass",           stri_endswith_charclass,         3),
   STRI__MK_CALL("C_stri_endswith_coll",                stri_endswith_coll,              4),
   STRI__MK_CALL("C_stri_endswith_fixed",               stri_endswith_fixed,             4),
   STRI__MK_CALL("C_stri_escape_unicode",               stri_escape_unicode,             1),
   STRI__MK_CALL("C_stri_extract_first_boundaries",     stri_extract_first_boundaries,   2),
   STRI__MK_CALL("C_stri_extract_last_boundaries",      stri_extract_last_boundaries,    2),
   STRI__MK_CALL("C_stri_extract_all_boundaries",       stri_extract_all_boundaries,     4),
   STRI__MK_CALL("C_stri_extract_first_charclass",      stri_extract_first_charclass,    2),
   STRI__MK_CALL("C_stri_extract_last_charclass",       stri_extract_last_charclass,     2),
   STRI__MK_CALL("C_stri_extract_all_charclass",        stri_extract_all_charclass,      5),
   STRI__MK_CALL("C_stri_extract_first_coll",           stri_extract_first_coll,         3),
   STRI__MK_CALL("C_stri_extract_last_coll",            stri_extract_last_coll,          3),
   STRI__MK_CALL("C_stri_extract_all_coll",             stri_extract_all_coll,           5),
   STRI__MK_CALL("C_stri_extract_first_fixed",          stri_extract_first_fixed,        3),
   STRI__MK_CALL("C_stri_extract_last_fixed",           stri_extract_last_fixed,         3),
   STRI__MK_CALL("C_stri_extract_all_fixed",            stri_extract_all_fixed,          5),
   STRI__MK_CALL("C_stri_extract_first_regex",          stri_extract_first_regex,        3),
   STRI__MK_CALL("C_stri_extract_last_regex",           stri_extract_last_regex,         3),
   STRI__MK_CALL("C_stri_extract_all_regex",            stri_extract_all_regex,          5),
   STRI__MK_CALL("C_stri_flatten",                      stri_flatten,                    2),
//   STRI__MK_CALL("C_stri_in_fixed",                   stri_in_fixed,                   3),  // TODO: version >= 0.6
   STRI__MK_CALL("C_stri_info",                         stri_info,                       0),
   STRI__MK_CALL("C_stri_isempty",                      stri_isempty,                    1),
   STRI__MK_CALL("C_stri_join",                         stri_join,                       4),
   STRI__MK_CALL("C_stri_join_list",                    stri_join_list,                  3),
   STRI__MK_CALL("C_stri_join2",                        stri_join2,                      2),
//   STRI__MK_CALL("C_stri_justify",                    stri_justify,                    2),  // TODO: version >= 0.6
   STRI__MK_CALL("C_stri_length",                       stri_length,                     1),
   STRI__MK_CALL("C_stri_list2matrix",                  stri_list2matrix,                4),
   STRI__MK_CALL("C_stri_locale_info",                  stri_locale_info,                1),
   STRI__MK_CALL("C_stri_locale_list",                  stri_locale_list,                0),
   STRI__MK_CALL("C_stri_locale_set",                   stri_locale_set,                 1),
   STRI__MK_CALL("C_stri_locate_all_boundaries",        stri_locate_all_boundaries,      3),
   STRI__MK_CALL("C_stri_locate_first_boundaries",      stri_locate_first_boundaries,    2),
   STRI__MK_CALL("C_stri_locate_last_boundaries",       stri_locate_last_boundaries,     2),
   STRI__MK_CALL("C_stri_locate_first_charclass",       stri_locate_first_charclass,     2),
   STRI__MK_CALL("C_stri_locate_last_charclass",        stri_locate_last_charclass,      2),
   STRI__MK_CALL("C_stri_locate_all_charclass",         stri_locate_all_charclass,       4),
   STRI__MK_CALL("C_stri_locate_last_fixed",            stri_locate_last_fixed,          3),
   STRI__MK_CALL("C_stri_locate_first_fixed",           stri_locate_first_fixed,         3),
   STRI__MK_CALL("C_stri_locate_all_fixed",             stri_locate_all_fixed,           4),
   STRI__MK_CALL("C_stri_locate_last_coll",             stri_locate_last_coll,           3),
   STRI__MK_CALL("C_stri_locate_first_coll",            stri_locate_first_coll,          3),
   STRI__MK_CALL("C_stri_locate_all_coll",              stri_locate_all_coll,            4),
   STRI__MK_CALL("C_stri_locate_all_regex",             stri_locate_all_regex,           4),
   STRI__MK_CALL("C_stri_locate_first_regex",           stri_locate_first_regex,         3),
   STRI__MK_CALL("C_stri_locate_last_regex",            stri_locate_last_regex,          3),
   STRI__MK_CALL("C_stri_match_first_regex",            stri_match_first_regex,          4),
   STRI__MK_CALL("C_stri_match_last_regex",             stri_match_last_regex,           4),
   STRI__MK_CALL("C_stri_match_all_regex",              stri_match_all_regex,            5),
   STRI__MK_CALL("C_stri_numbytes",                     stri_numbytes,                   1),
   STRI__MK_CALL("C_stri_order",                        stri_order,                      4),
   STRI__MK_CALL("C_stri_sort",                         stri_sort,                       4),
   STRI__MK_CALL("C_stri_pad",                          stri_pad,                        5),
   STRI__MK_CALL("C_stri_prepare_arg_string",           stri_prepare_arg_string,         2),
   STRI__MK_CALL("C_stri_prepare_arg_POSIXct",          stri_prepare_arg_POSIXct,        2),
   STRI__MK_CALL("C_stri_prepare_arg_double",           stri_prepare_arg_double,         2),
   STRI__MK_CALL("C_stri_prepare_arg_integer",          stri_prepare_arg_integer,        2),
   STRI__MK_CALL("C_stri_prepare_arg_logical",          stri_prepare_arg_logical,        2),
   STRI__MK_CALL("C_stri_prepare_arg_raw",              stri_prepare_arg_raw,            2),
   STRI__MK_CALL("C_stri_prepare_arg_string_1",         stri_prepare_arg_string_1,       2),
   STRI__MK_CALL("C_stri_prepare_arg_double_1",         stri_prepare_arg_double_1,       2),
   STRI__MK_CALL("C_stri_prepare_arg_integer_1",        stri_prepare_arg_integer_1,      2),
   STRI__MK_CALL("C_stri_prepare_arg_logical_1",        stri_prepare_arg_logical_1,      2),
   STRI__MK_CALL("C_stri_rand_shuffle",                 stri_rand_shuffle,               1),
   STRI__MK_CALL("C_stri_rand_strings",                 stri_rand_strings,               3),
   STRI__MK_CALL("C_stri_replace_na",                   stri_replace_na,                 2),
   STRI__MK_CALL("C_stri_replace_all_fixed",            stri_replace_all_fixed,          5),
   STRI__MK_CALL("C_stri_replace_first_fixed",          stri_replace_first_fixed,        4),
   STRI__MK_CALL("C_stri_replace_last_fixed",           stri_replace_last_fixed,         4),
   STRI__MK_CALL("C_stri_replace_all_coll",             stri_replace_all_coll,           5),
   STRI__MK_CALL("C_stri_replace_first_coll",           stri_replace_first_coll,         4),
   STRI__MK_CALL("C_stri_replace_last_coll",            stri_replace_last_coll,          4),
   STRI__MK_CALL("C_stri_replace_all_regex",            stri_replace_all_regex,          5),
   STRI__MK_CALL("C_stri_replace_first_regex",          stri_replace_first_regex,        4),
   STRI__MK_CALL("C_stri_replace_last_regex",           stri_replace_last_regex,         4),
   STRI__MK_CALL("C_stri_replace_all_charclass",        stri_replace_all_charclass,      5),
   STRI__MK_CALL("C_stri_replace_first_charclass",      stri_replace_first_charclass,    3),
   STRI__MK_CALL("C_stri_replace_last_charclass",       stri_replace_last_charclass,     3),
   STRI__MK_CALL("C_stri_reverse",                      stri_reverse,                    1),
   STRI__MK_CALL("C_stri_split_boundaries",             stri_split_boundaries,           5),
   STRI__MK_CALL("C_stri_split_charclass",              stri_split_charclass,            6),
   STRI__MK_CALL("C_stri_split_coll",                   stri_split_coll,                 7),
   STRI__MK_CALL("C_stri_split_fixed",                  stri_split_fixed,                7),
   STRI__MK_CALL("C_stri_split_lines",                  stri_split_lines,                2),
   STRI__MK_CALL("C_stri_split_lines1",                 stri_split_lines1,               1),
   STRI__MK_CALL("C_stri_split_regex",                  stri_split_regex,                7),
   STRI__MK_CALL("C_stri_startswith_charclass",         stri_startswith_charclass,       3),
   STRI__MK_CALL("C_stri_startswith_coll",              stri_startswith_coll,            4),
   STRI__MK_CALL("C_stri_startswith_fixed",             stri_startswith_fixed,           4),
   STRI__MK_CALL("C_stri_stats_general",                stri_stats_general,              1),
   STRI__MK_CALL("C_stri_stats_latex",                  stri_stats_latex,                1),
   STRI__MK_CALL("C_stri_sub",                          stri_sub,                        4),
   STRI__MK_CALL("C_stri_sub_replacement",              stri_sub_replacement,            6),
   STRI__MK_CALL("C_stri_subset_charclass",             stri_subset_charclass,           4),
   STRI__MK_CALL("C_stri_subset_coll",                  stri_subset_coll,                5),
   STRI__MK_CALL("C_stri_subset_fixed",                 stri_subset_fixed,               5),
   STRI__MK_CALL("C_stri_subset_regex",                 stri_subset_regex,               5),
   STRI__MK_CALL("C_stri_subset_charclass_replacement", stri_subset_charclass_replacement, 4),
   STRI__MK_CALL("C_stri_subset_coll_replacement",      stri_subset_coll_replacement,    5),
   STRI__MK_CALL("C_stri_subset_fixed_replacement",     stri_subset_fixed_replacement,   5),
   STRI__MK_CALL("C_stri_subset_regex_replacement",     stri_subset_regex_replacement,   5),
   STRI__MK_CALL("C_stri_test_Rmark",                   stri_test_Rmark,                 1),
   STRI__MK_CALL("C_stri_test_returnasis",              stri_test_returnasis,            1),
   STRI__MK_CALL("C_stri_test_UnicodeContainer16",      stri_test_UnicodeContainer16,    1),
   STRI__MK_CALL("C_stri_test_UnicodeContainer16b",     stri_test_UnicodeContainer16b,   1),
   STRI__MK_CALL("C_stri_test_UnicodeContainer8",       stri_test_UnicodeContainer8,     1),
   STRI__MK_CALL("C_stri_timezone_list",                stri_timezone_list,              2),
   STRI__MK_CALL("C_stri_timezone_set",                 stri_timezone_set,               1),
   STRI__MK_CALL("C_stri_timezone_info",                stri_timezone_info,              3),
   STRI__MK_CALL("C_stri_trans_char",                   stri_trans_char,                 3),
   STRI__MK_CALL("C_stri_trans_isnfc",                  stri_trans_isnfc,                1),
   STRI__MK_CALL("C_stri_trans_isnfd",                  stri_trans_isnfd,                1),
   STRI__MK_CALL("C_stri_trans_isnfkc",                 stri_trans_isnfkc,               1),
   STRI__MK_CALL("C_stri_trans_isnfkd",                 stri_trans_isnfkd,               1),
   STRI__MK_CALL("C_stri_trans_isnfkc_casefold",        stri_trans_isnfkc_casefold,      1),
   STRI__MK_CALL("C_stri_trans_general",                stri_trans_general,              2),
   STRI__MK_CALL("C_stri_trans_list",                   stri_trans_list,                 0),
   STRI__MK_CALL("C_stri_trans_nfc",                    stri_trans_nfc,                  1),
   STRI__MK_CALL("C_stri_trans_nfd",                    stri_trans_nfd,                  1),
   STRI__MK_CALL("C_stri_trans_nfkc",                   stri_trans_nfkc,                 1),
   STRI__MK_CALL("C_stri_trans_nfkd",                   stri_trans_nfkd,                 1),
   STRI__MK_CALL("C_stri_trans_nfkc_casefold",          stri_trans_nfkc_casefold,        1),
   STRI__MK_CALL("C_stri_trans_totitle",                stri_trans_totitle,              2),
   STRI__MK_CALL("C_stri_trans_tolower",                stri_trans_tolower,              2),
   STRI__MK_CALL("C_stri_trans_toupper",                stri_trans_toupper,              2),
   STRI__MK_CALL("C_stri_trim_both",                    stri_trim_both,                  2),
   STRI__MK_CALL("C_stri_trim_left",                    stri_trim_left,                  2),
   STRI__MK_CALL("C_stri_trim_right",                   stri_trim_right,                 2),
   STRI__MK_CALL("C_stri_unescape_unicode",             stri_unescape_unicode,           1),
   STRI__MK_CALL("C_stri_unique",                       stri_unique,                     2),
   STRI__MK_CALL("C_stri_width",                        stri_width,                      1),
   STRI__MK_CALL("C_stri_wrap",                         stri_wrap,                      10),
//   STRI__MK_CALL("C_stri_trim_double",                stri_trim_double,                3), // TODO: version >= 0.6

   // the list must be NULL-terminated:
   {NULL,                           NULL,                  0}

};


/** Sets ICU data dir
 *
 * @param libpath
 */
void stri_set_icu_data_directory(const char* libpath)
{
   // libpath == "...../libs"      -> "...../libs"
   // libpath == "...../libs/i386" -> "...../libs"
   // libpath == "...../libs/x64"  -> "...../libs"

   string dir(libpath);
   size_t idx = dir.rfind("libs");
   if (idx == string::npos) {
      // this shouldn't happen
      u_setDataDirectory(libpath); // just use the libpath
      return;
   }

   // idx+5 -> if the string is shorter, as many characters as possible are used
   dir = dir.substr(0, idx+4); // 4 == strlen("libs")
   u_setDataDirectory(dir.c_str());
// #ifndef NDEBUG
   // fprintf(stderr, "ICU data directory=%s\n", dir.c_str());
// #endif

   // anyway, if .dat file will not be found,
   // ICU will use system data (may be stub)


   // 1. Examine the contents of the default ICU data shared library.
   //    If it contains data, use that data.
   //    If the data library is empty, a stub library, proceed to the next step.
   // 2. Dynamically load (memory map, typically) a common format (.dat) file
   //    containing the default ICU data.
}


/**
 * Library initialization.
 *
 * R calls this automatically on lib load/attach.
 */
extern "C" void R_init_stringi(DllInfo* dll)
{
#if STRI_ICU_FOUND == 0
   stri_set_icu_data_directory((char*)*(char**)(dll) /* dll->path */);
#endif

/* BTW: u_init: It is OK to simply use ICU services and functions without
   first having initialized ICU by calling u_init().

   u_init() will attempt to load some part of ICU's data, and is useful
   as a test for configuration or installation problems that leave
   the ICU data inaccessible. A successful invocation of u_init() does not,
   however, guarantee that all ICU data is accessible.
*/
   UErrorCode status = U_ZERO_ERROR;
   u_init(&status);
   if (U_FAILURE(status))
      Rf_error("ICU init failed: %s", u_errorName(status));

   R_registerRoutines(dll, NULL, cCallMethods, NULL, NULL);
   R_useDynamicSymbols(dll, (Rboolean)FALSE);
#if defined(R_VERSION) && R_VERSION >= R_Version(3, 0, 0)
   R_forceSymbols(dll, (Rboolean)TRUE);
#endif

   const R_CallMethodDef* methods = cCallMethods;
   while (methods->name) {
      R_RegisterCCallable("stringi", methods->name, methods->fun);
      methods++;
   }

   if (!SUPPORT_UTF8) {
      /* Rconfig.h states that all R platforms supports that */
      Rf_error("R does not support UTF-8 encoding.");
   }


#ifndef NDEBUG
//    fprintf(stdout, "!NDEBUG: ************************************************\n");
//    fprintf(stdout, "!NDEBUG: Dynamic library `stringi` loaded\n");
//    fprintf(stdout, "!NDEBUG: Check out http://stringi.rexamine.com\n");
//    fprintf(stdout, "!NDEBUG: \n");
//    fprintf(stdout, "!NDEBUG: Please send bug reports to stringi@rexamine.com \n");
//    fprintf(stdout, "!NDEBUG: or at https://github.com/Rexamine/stringi/issues\n");
//    fprintf(stdout, "!NDEBUG: \n");
//    fprintf(stdout, "!NDEBUG: Have fun testing! :-)\n");
//    fprintf(stdout, "!NDEBUG: ************************************************\n");
#endif
}


#ifndef NDEBUG

#include <unicode/uclean.h>

/**
 * Library cleanup
 */
extern "C" void  R_unload_stringi(DllInfo*)
{
   // see http://bugs.icu-project.org/trac/ticket/10897
   // and https://github.com/Rexamine/stringi/issues/78
//   fprintf(stdout, "!NDEBUG: ************************************************\n");
//   fprintf(stdout, "!NDEBUG: Dynamic library 'stringi' unloaded.\n");
//   fprintf(stdout, "!NDEBUG: ************************************************\n");
   u_cleanup();
}

#endif
