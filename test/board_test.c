#include <libchessviz/board.h>
#include <libchessviz/constants.h>

#include <ctest.h>

#define CTEST_SEGFAULT

CTEST(suite_board, make_figure_test)
{
    int figure;
    int figure_res;
    int figure_exp;
    int is_white;

    figure = 'p';
    is_white = 0;
    figure_exp = 'p';
    figure_res = make_figure(figure, is_white);
    ASSERT_EQUAL(figure_exp, figure_res);

    figure = 'k';
    is_white = 1;
    figure_exp = 'K';
    figure_res = make_figure(figure, is_white);
    ASSERT_EQUAL(figure_exp, figure_res);

    figure = 'n';
    is_white = 0;
    figure_exp = 'n';
    figure_res = make_figure(figure, is_white);
    ASSERT_EQUAL(figure_exp, figure_res);
}

CTEST(suite_board, check_figure_type_test)
{
    char c;
    int res;
    int exp;

    c = 'd';
    exp = PAWN;
    res = check_figure_type(c);
    ASSERT_EQUAL(exp, res);

    c = '0';
    exp = KING;
    res = check_figure_type(c);
    ASSERT_EQUAL(exp, res);

    c = 'Q';
    exp = QUEEN;
    res = check_figure_type(c);
    ASSERT_EQUAL(exp, res);

    c = 'k';
    exp = 0;
    res = check_figure_type(c);
    ASSERT_EQUAL(exp, res);
}
