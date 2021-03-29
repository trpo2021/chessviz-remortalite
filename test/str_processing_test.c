#include <libchessviz/constants.h>
#include <libchessviz/str_processing.h>

#include <ctest.h>
#include <stdlib.h>
#include <string.h>

CTEST(suite_str, strip_beg_test)
{
    char* result_str = calloc(MAX_LINE_LEN, sizeof(char));
    char* expect_str = calloc(MAX_LINE_LEN, sizeof(char));

    strcpy(result_str, "   1. e2-e4");
    strcpy(expect_str, "1. e2-e4");
    strip_beg(&result_str);
    ASSERT_STR(expect_str, result_str);

    strcpy(result_str, "       ");
    strcpy(expect_str, "");
    strip_beg(&result_str);
    ASSERT_STR(expect_str, result_str);

    strcpy(result_str, "");
    strcpy(expect_str, "");
    strip_beg(&result_str);
    ASSERT_STR(expect_str, result_str);

    free(result_str);
    free(expect_str);
}

CTEST(suite_str, get_group_test)
{
    char* input_str = calloc(MAX_LINE_LEN, sizeof(char));
    char* result_str = calloc(MAX_LINE_LEN, sizeof(char));
    char* expect_str = calloc(MAX_LINE_LEN, sizeof(char));

    strcpy(input_str, "e2-e4");
    strcpy(expect_str, "e2-e4");
    get_group(input_str, &result_str);
    ASSERT_STR(expect_str, result_str);

    strcpy(input_str, "e2 e4");
    strcpy(expect_str, "e2");
    get_group(input_str, &result_str);
    ASSERT_STR(expect_str, result_str);

    strcpy(input_str, "Qh5xf7#");
    strcpy(expect_str, "Qh5xf7#");
    get_group(input_str, &result_str);
    ASSERT_STR(expect_str, result_str);

    strcpy(input_str, "e2-e4+ e5-e6");
    strcpy(expect_str, "e2-e4+");
    get_group(input_str, &result_str);
    ASSERT_STR(expect_str, result_str);

    strcpy(input_str, "");
    strcpy(expect_str, "");
    get_group(input_str, &result_str);
    ASSERT_STR(expect_str, result_str);

    free(input_str);
    free(result_str);
    free(expect_str);
}
