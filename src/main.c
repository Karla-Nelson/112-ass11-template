#include <stdio.h>
#include "unity.h"
#include "code.h"

/* Unity requires these two functions. They are intentionally empty:
 * each test creates everything it needs inside the test itself. */
void setUp(void) { }
void tearDown(void) { }

int main(void)
{
    UNITY_BEGIN();


    /* PART 1: Text and numbers */
    RUN_TEST(test_strlen_basic);
    RUN_TEST(test_strlen_edge_cases);
    RUN_TEST(test_strcmp_signs);
    RUN_TEST(test_atoi_valid);
    RUN_TEST(test_atoi_partial_and_invalid);
    RUN_TEST(test_atol);
    RUN_TEST(test_atof);

    /* PART 2: Math */
    RUN_TEST(test_sqrt);
    RUN_TEST(test_pow);
    RUN_TEST(test_floor);
    RUN_TEST(test_ceil);
    RUN_TEST(test_round);
    RUN_TEST(test_fmod);
    RUN_TEST(test_floor_ceil_round_relation);

    /* PART 3: Memory, strings and formatting */
    RUN_TEST(test_memcpy_int_array);
    RUN_TEST(test_memcpy_string_and_zero_bytes);
    RUN_TEST(test_memset_and_memcmp);
    RUN_TEST(test_strcpy_strcat);
    RUN_TEST(test_strchr);
    RUN_TEST(test_sprintf_integers);
    RUN_TEST(test_sprintf_strings_and_doubles);
    RUN_TEST(test_sprintf_return_matches_strlen);

    /* PART 4: qsort and integration */
    RUN_TEST(test_qsort_ints);
    RUN_TEST(test_qsort_chars);
    RUN_TEST(test_qsort_strings);
    RUN_TEST(test_roundtrip_sprintf_atoi_atof);
    RUN_TEST(test_anagram_with_qsort);

    return UNITY_END();   /* the number of failed tests: 0 means success */
}
