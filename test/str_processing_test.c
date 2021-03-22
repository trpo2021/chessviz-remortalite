#include <libchessviz/constants.h>
#include <libchessviz/str_processing.h>

#include <ctest.h>
#include <stdlib.h>

CTEST(suite_str, strip_beg_test)
{
    char* result_str = calloc(MAX_LINE_LEN, sizeof(char));
    char* expect_str = calloc(MAX_LINE_LEN, sizeof(char));

    result_str = "   1. e2-e4";
    expect_str = "1. e2-e4";
    strip_beg(&result_str);
    ASSERT_STR(expect_str, result_str);

    result_str = "       ";
    expect_str = "";
    strip_beg(&result_str);
    ASSERT_STR(expect_str, result_str);

    result_str = "";
    expect_str = "";
    strip_beg(&result_str);
    ASSERT_STR(expect_str, result_str);
}

CTEST(suite_str, get_group_test)
{
    char* input_str = calloc(MAX_LINE_LEN, sizeof(char));
    char* result_str = calloc(MAX_LINE_LEN, sizeof(char));
    char* expect_str = calloc(MAX_LINE_LEN, sizeof(char));

    input_str = "e2-e4";
    expect_str = "e2";
    get_group(input_str, &result_str);
    ASSERT_STR(expect_str, result_str);

    input_str = "e2 e4";
    expect_str = "e2";
    get_group(input_str, &result_str);
    ASSERT_STR(expect_str, result_str);

    input_str = "e2e4 e5-e6";
    expect_str = "e2e4";
    get_group(input_str, &result_str);
    ASSERT_STR(expect_str, result_str);

    input_str = "";
    expect_str = "";
    get_group(input_str, &result_str);
    ASSERT_STR(expect_str, result_str);
}
