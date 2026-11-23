#ifndef CODE_H
#define CODE_H

/*
 * CSCI 112 Assignment 11 - Unit Tests for the Standard Library
 *
 * In this assignment YOU write the unit tests. The functions below are test
 * functions: each one checks the behavior of some standard library functions
 * with Unity assertions. You write their bodies in code.c; the instructor's
 * main.c runs them.
 *
 * This header is complete. Do NOT change any signature or name - main.c calls
 * these functions. Each prototype is preceded by a description of what its
 * test must verify. The detailed hints are in code.c.
 *
 * A test PASSES when none of its assertions fails. A test that has not been
 * written yet FAILS on purpose with the message "Not implemented yet".
 *
 * Allowed assertions (all of them compare an expected value with an actual one):
 *   TEST_ASSERT_EQUAL_INT_MESSAGE(expected, actual, "message")
 *   TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(expected, actual, "message")
 *   TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, actual, "message")
 *   TEST_ASSERT_EQUAL_MEMORY_MESSAGE(expected, actual, number_of_bytes, "message")
 *   TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(expected, actual, number_of_elements, "message")
 *
 * Do not use setUp() or tearDown(): everything a test needs is created inside
 * the test itself.
 */

/* ======================================================================
 * Helper functions (not tests) used by the qsort tests of Part 4
 * ====================================================================== */

/*
 * STEP 0 (given): cmp_int
 * Comparator for an array of int, ascending. This one is already written for
 * you in code.c - read it, it is the pattern for the next three.
 */
int cmp_int(const void *a, const void *b);

/*
 * HELPER for test_qsort_chars: cmp_char
 * Comparator for an array of char, ascending. The pointers point to single
 * characters; compare them as unsigned char so that the order is by character
 * code.
 */
int cmp_char(const void *a, const void *b);

/*
 * HELPER for test_qsort_strings: cmp_strlen
 * Comparator for an array of char *, ordering the strings by LENGTH (shorter
 * first). Each element is a char *, so the pointers you receive point to a
 * char *. Use strlen().
 */
int cmp_strlen(const void *a, const void *b);

/*
 * HELPER for test_qsort_strings: cmp_str
 * Comparator for an array of char *, ordering the strings alphabetically
 * (strcmp, ascending). Each element is a char *.
 */
int cmp_str(const void *a, const void *b);

/*
 * HELPER for test_anagram_with_qsort: is_anagram
 * Returns 1 if the strings are anagrams and 0 otherwise. Suggested approach:
 * if the lengths differ (strlen) or are 63 or more, return 0. Copy both
 * strings (strcpy) into two local char arrays of 64, sort the characters of
 * each copy with qsort() and cmp_char, and compare the sorted copies with
 * strcmp().
 */
int is_anagram(const char *a, const char *b);

/* ======================================================================
 * PART 1: Text and numbers (every case is listed - just turn them into assertions)
 * ====================================================================== */

/*
 * STEP 1: test_strlen_basic
 * Verify strlen() on ordinary strings. Check that strlen("hello") is 5,
 * strlen("a") is 1, strlen("Hello, World!") is 13 and strlen("  x ") is 4
 * (spaces count). strlen() returns size_t, so cast the result to int before
 * you compare it.
 */
void test_strlen_basic(void);

/*
 * STEP 2: test_strlen_edge_cases
 * Verify the edge cases of strlen(). The empty string has length 0. For char
 * buf[10] = "abc"; strlen(buf) is 3 although sizeof(buf) is 10 (assert both
 * numbers). A string with a terminator inside, such as "ab\0cd", has length 2
 * because strlen() stops at the first '\0'. A string ending in a newline,
 * "line\n", has length 5.
 */
void test_strlen_edge_cases(void);

/*
 * STEP 3: test_strcmp_signs
 * strcmp() returns a negative number, zero or a positive number. Only the SIGN
 * is specified, so never compare the result with -1 or 1. Assert that
 * strcmp("same", "same") is exactly 0. Assert every other result by checking a
 * comparison: for example TEST_ASSERT_EQUAL_INT_MESSAGE(1, strcmp("apple",
 * "banana") < 0, ...). Check: "apple" < "banana"; "banana" > "apple"; a prefix
 * is smaller ("app" < "apple" and "apple" > "app"); uppercase comes before
 * lowercase ("Zebra" < "apple" and "a" > "A"); the empty string is smaller
 * than any other string ("" < "a").
 */
void test_strcmp_signs(void);

/*
 * STEP 4: test_atoi_valid
 * Verify atoi() on valid input. Check: "123" gives 123, "0" gives 0, "-45"
 * gives -45, "+7" gives 7, "  42" (leading spaces are skipped) gives 42, "007"
 * gives 7 and "2147483647" gives 2147483647.
 */
void test_atoi_valid(void);

/*
 * STEP 5: test_atoi_partial_and_invalid
 * Verify what atoi() does with text that is not a clean number. Check: "12abc"
 * gives 12 (it reads the digits and stops), "abc" gives 0, "" gives 0, "-"
 * gives 0, "3.9" gives 3 (the fraction is ignored) and "1 2" gives 1 (it stops
 * at the space).
 */
void test_atoi_partial_and_invalid(void);

/*
 * STEP 6: test_atol
 * Verify atol(). Check: "123456" gives 123456, "2000000000" gives 2000000000,
 * "-2000000000" gives -2000000000, "  -99" gives -99, "42xyz" gives 42 and "x"
 * gives 0. Keep all values within +-2,000,000,000: on a 32-bit system a long
 * has only 32 bits.
 */
void test_atol(void);

/*
 * STEP 7: test_atof
 * Verify atof(). Check: "3.5" gives 3.5, "-0.25" gives -0.25, "1e3" gives
 * 1000.0 (scientific notation), "  2.5xyz" gives 2.5, "abc" gives 0.0, ".5"
 * gives 0.5 and "42" gives 42.0.
 */
void test_atof(void);

/* ======================================================================
 * PART 2: Math (cases are listed; choose the right assertion)
 * ====================================================================== */

/*
 * STEP 8: test_sqrt
 * Verify sqrt(). Check: sqrt(0) is 0, sqrt(1) is 1, sqrt(16) is 4, sqrt(144)
 * is 12, sqrt(0.25) is 0.5, sqrt(1000000) is 1000 and sqrt(2) is
 * 1.4142135623730951.
 */
void test_sqrt(void);

/*
 * STEP 9: test_pow
 * Verify pow(). Check: pow(2, 10) is 1024; pow(5, 0) is 1; pow(0, 0) is 1;
 * pow(2, -1) is 0.5 (negative exponent); pow(-2, 3) is -8 and pow(-2, 2) is 4
 * (negative base); pow(9, 0.5) is 3 (fractional exponent); pow(10, 2) is 100;
 * pow(1, 1000) is 1.
 */
void test_pow(void);

/*
 * STEP 10: test_floor
 * Verify floor(), which rounds DOWN. Check: floor(2.7) is 2, floor(2.0) is 2,
 * floor(0.5) is 0, floor(-2.1) is -3, floor(-2.0) is -2 and floor(-0.5) is -1.
 * The negative numbers are the interesting part: down means toward minus
 * infinity, not toward zero.
 */
void test_floor(void);

/*
 * STEP 11: test_ceil
 * Verify ceil(), which rounds UP. Check: ceil(2.1) is 3, ceil(2.0) is 2,
 * ceil(0.5) is 1, ceil(-2.7) is -2, ceil(-2.0) is -2 and ceil(5.0) is 5. A
 * value that is already an integer must stay unchanged.
 */
void test_ceil(void);

/*
 * STEP 12: test_round
 * Verify round(), which rounds to the NEAREST integer, with halves going AWAY
 * from zero. Check: round(2.4) is 2, round(2.5) is 3, round(2.6) is 3,
 * round(-2.4) is -2, round(-2.5) is -3, round(-2.6) is -3, round(0.0) is 0 and
 * round(7.0) is 7.
 */
void test_round(void);

/*
 * STEP 13: test_fmod
 * Verify fmod(), the remainder of a floating point division. Check: fmod(7.5,
 * 2) is 1.5; fmod(10, 3) is 1; fmod(9, 3) is 0; fmod(-7.5, 2) is -1.5 and
 * fmod(7.5, -2) is 1.5 (the result has the sign of the FIRST argument);
 * fmod(2, 5) is 2.
 */
void test_fmod(void);

/*
 * STEP 14: test_floor_ceil_round_relation
 * Combine floor(), ceil() and round() in one test, using loops over arrays.
 * For every value of {0.1, 2.5, -2.5, -0.9, 100.99, -100.01} check that
 * ceil(x) - floor(x) is exactly 1, that floor(x) <= x, that x <= ceil(x), and
 * that round(x) lies between floor(x) and ceil(x). For every value of {-3.0,
 * 0.0, 8.0} check that floor(x), ceil(x) and round(x) all equal x.
 */
void test_floor_ceil_round_relation(void);

/* ======================================================================
 * PART 3: Memory, strings and formatting
 * ====================================================================== */

/*
 * STEP 15: test_memcpy_int_array
 * Verify memcpy() on an int array. Copy int src[5] = {1, 2, 3, 4, -1} into a
 * zeroed int dest[5] with memcpy(dest, src, sizeof src) and check that dest
 * equals src. Check that memcpy() returns the destination pointer. Then copy
 * only the first 3 ints (3 * sizeof(int) bytes) into a freshly zeroed array
 * and check that the result is {1, 2, 3, 0, 0}.
 */
void test_memcpy_int_array(void);

/*
 * STEP 16: test_memcpy_string_and_zero_bytes
 * Verify memcpy() on text. Prepare char buf[10] with the first 9 bytes set to
 * 'X' (use memset) and the last byte set to '\0'. (1) memcpy(buf, "hello", 6)
 * copies the text and its terminator: buf must be the string "hello" and
 * buf[6] must still be 'X'. (2) Refill buf with 'X', copy only 5 bytes, and
 * check that the first 9 bytes are "helloXXXX" (no terminator was copied). (3)
 * Refill buf and copy 0 bytes: buf[0] must still be 'X'.
 */
void test_memcpy_string_and_zero_bytes(void);

/*
 * STEP 17: test_memset_and_memcmp
 * Verify memset() and memcmp(). With unsigned char buf[8]: memset(buf, 'A', 8)
 * must fill every byte (check the last one); memset(buf, 0, 8) must give 8
 * zero bytes (compare with an array of zeros); after memset(buf, 'B', 4) the
 * 4th byte is 'B' and the 5th byte is still 0. Then compare the strings a =
 * "abcdX" and b = "abcdY": memcmp(a, a, 5) is 0; memcmp(a, b, 4) is 0 (the
 * difference is outside the first 4 bytes); memcmp(a, b, 5) is negative and
 * memcmp(b, a, 5) is positive.
 */
void test_memset_and_memcmp(void);

/*
 * STEP 18: test_strcpy_strcat
 * Verify strcpy() and strcat(). Prepare char buf[20] with the first 19 bytes
 * set to 'X' and the last byte set to '\0'. strcpy(buf, "abc") must give the
 * string "abc", buf[3] must be '\0' (the terminator is copied), buf[4] must
 * still be 'X', and the function must return buf itself. strcat(buf, "def")
 * must give "abcdef" and return buf. strcat(buf, "") must change nothing.
 * strcat(buf, "!") must give "abcdef!", whose strlen() is 7.
 */
void test_strcpy_strcat(void);

/*
 * STEP 19: test_strchr
 * Verify strchr(). In s = "hello": the first 'l' is at index 2, 'h' is at
 * index 0 and 'o' is at index 4. A character that does not occur ('z') gives
 * NULL. The terminator can be searched for too: strchr(s, '\0') points to
 * index 5. In an empty string nothing is found: strchr("", 'a') is NULL.
 */
void test_strchr(void);

/*
 * STEP 20: test_sprintf_integers
 * Verify sprintf() with integer formats, using char buf[64]. Check the text
 * produced and, for the first two calls, also the return value (the number of
 * characters written): "%d" of 42 gives "42" (returns 2); "%d" of -7 gives
 * "-7" (returns 2); "%05d" of 42 gives "00042"; "%5d" of 42 gives "   42";
 * "%-5d|" of 42 gives "42   |"; "%x" of 255 gives "ff"; "%X" of 255 gives
 * "FF"; "%o" of 8 gives "10"; "%+d" of 5 gives "+5".
 */
void test_sprintf_integers(void);

/*
 * STEP 21: test_sprintf_strings_and_doubles
 * Verify sprintf() with text and floating point formats, using char buf[64].
 * "%s" of "abc" gives "abc"; "%c" of 'Z' gives "Z"; "%-6s|" of "ab" gives "ab
 * |"; "%6s" of "ab" gives "    ab"; "%.2s" of "abcdef" gives "ab"; "%.2f" of
 * 3.14159 gives "3.14"; "%.3f" of 2.0 gives "2.000"; "%8.2f" of 3.14159 gives
 * "    3.14"; "%f" of 0.5 gives "0.500000"; and the format "100%%" gives
 * "100%".
 */
void test_sprintf_strings_and_doubles(void);

/*
 * STEP 22: test_sprintf_return_matches_strlen
 * sprintf() returns the number of characters it wrote (not counting the
 * terminator). For each of these calls assert the expected return value AND
 * that it equals strlen(buf): "%d" of 12345 (5); "%s-%s" of "ab" and "cd" (5);
 * "%5.2f" of 3.14159 (5); "%s" of "" (0 - and the buffer must be the empty
 * string); "%s: %s, %s: %d" of "Name", "Ann", "Age", 21, which writes "Name:
 * Ann, Age: 21" (18 characters).
 */
void test_sprintf_return_matches_strlen(void);

/* ======================================================================
 * PART 4: qsort and integration (you choose the inputs - the checklist tells you what must be covered)
 * ====================================================================== */

/*
 * STEP 23: test_qsort_ints
 * Verify qsort() on int arrays, sorted ascending with the given comparator
 * cmp_int. Your test must cover: an unsorted array {5, 2, 9, 1, 7} (becomes
 * {1, 2, 5, 7, 9}); a reversed array; an already sorted array (stays
 * unchanged); an array with duplicates {3, 1, 3, 1}; an array with negative
 * numbers; an array whose SMALLEST element is the LAST one (for example {9, 8,
 * 7, 0}); an array with a single element; and count 0, which must not touch
 * the array (use an array you can check afterwards).
 */
void test_qsort_ints(void);

/*
 * STEP 24: test_qsort_chars
 * Verify qsort() on the characters of a string, using the comparator cmp_char
 * that you write (see below) and strlen() to get the count. Your test must
 * cover: "hello" (becomes "ehllo"); "dcba" (becomes "abcd"); an already sorted
 * string "abc"; a string of equal letters "zzz"; and the empty string ""
 * (stays empty). Sort a char array (not a string literal - literals are read-
 * only).
 */
void test_qsort_chars(void);

/*
 * STEP 25: test_qsort_strings
 * Verify qsort() on an array of strings (char * elements), using the
 * comparators cmp_strlen and cmp_str that you write (see below). Sort {"ccc",
 * "a", "dddd", "bb"} by length: the result is "a", "bb", "ccc", "dddd". Sort
 * {"pear", "apple", "Zed", "app"} alphabetically with strcmp(): the result is
 * "Zed", "app", "apple", "pear" (uppercase first, and a prefix comes before
 * the longer word). Check every element of both results.
 */
void test_qsort_strings(void);

/*
 * STEP 26: test_roundtrip_sprintf_atoi_atof
 * A round trip: format a number with sprintf(), parse the text back, and
 * expect the original number. For the ints {0, 7, -15, 1234567, -2000000000}
 * use "%d" and check that the text has the expected length (1, 1, 3, 7, 11),
 * that atoi() gives the number back and that atol() gives it back. For the
 * doubles {0.5, -2.25, 100.75, 3.0} use "%.2f" and check that atof() gives the
 * number back. Use loops over arrays.
 */
void test_roundtrip_sprintf_atoi_atof(void);

/*
 * STEP 27: test_anagram_with_qsort
 * Write the helper is_anagram(a, b) (see below), then test it. Two strings are
 * anagrams if they contain the same letters in a different order. Your test
 * must cover: "listen" and "silent" (yes); "hello" and "world" (no); "abc" and
 * "abcd" (no - different lengths); "" and "" (yes); "aab" and "abb" (no - same
 * length, different letters); "Listen" and "silent" (no - case matters); "a"
 * and "a" (yes).
 */
void test_anagram_with_qsort(void);

#endif
