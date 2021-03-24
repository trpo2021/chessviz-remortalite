#include <libchessviz/board.h>
#include <libchessviz/constants.h>
#include <libchessviz/move.h>

#include <ctest.h>
#include <stdlib.h>

#define CTEST_SEGFAULT

void make_zeros(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 0;
}

CTEST(suite_move, move_figure)
{
    int i, j;

    char prev_lit, prev_num, next_lit, next_num;
    int figure_code, en_passant;

    int board_res[BOARD_SIZE][BOARD_SIZE] = {0};
    make_board(board_res);
    int board_exp[BOARD_SIZE][BOARD_SIZE] = {0};
    make_board(board_exp);

    //
    // subtest 1
    //

    en_passant = 0;
    figure_code = 'P';
    prev_lit = 'a';
    prev_num = '2';
    next_lit = 'a';
    next_num = '4';

    move_figure(
            board_res,
            prev_lit,
            prev_num,
            next_lit,
            next_num,
            figure_code,
            en_passant);

    board_exp[4][0] = board_exp[6][0];
    board_exp[6][0] = 0;

    // can't use ASSERT_DATA
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            ASSERT_EQUAL(board_exp[i][j], board_res[i][j]);
        }
    }

    make_zeros(board_exp);
    make_zeros(board_res);

    //
    // subtest 2
    // test en_passant

    make_board(board_res);
    make_board(board_exp);

    board_res[1][1] = 0;
    board_res[3][1] = 'p';

    board_res[6][0] = 0;
    board_res[3][0] = 'P';

    en_passant = 1;
    figure_code = 'P';
    prev_lit = 'a';
    prev_num = '5';
    next_lit = 'b';
    next_num = '6';

    move_figure(
            board_res,
            prev_lit,
            prev_num,
            next_lit,
            next_num,
            figure_code,
            en_passant);

    board_exp[1][1] = 0;
    board_exp[6][0] = 0;
    board_exp[2][1] = 'P';

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            ASSERT_EQUAL(board_exp[i][j], board_res[i][j]);
        }
    }

    //
    // subtest 3
    //

    make_zeros(board_exp);
    make_zeros(board_res);
    make_board(board_exp);
    make_board(board_res);

    board_res[1][6] = 0;
    board_res[3][6] = 'p';

    board_res[6][7] = 0;
    board_res[3][7] = 'P';

    en_passant = 1;
    figure_code = 'P';
    prev_lit = 'h';
    prev_num = '5';
    next_lit = 'g';
    next_num = '6';

    move_figure(
            board_res,
            prev_lit,
            prev_num,
            next_lit,
            next_num,
            figure_code,
            en_passant);

    board_exp[1][6] = 0;
    board_exp[6][7] = 0;
    board_exp[2][6] = 'P';

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            ASSERT_EQUAL(board_exp[i][j], board_res[i][j]);
        }
    }

    //
    // subtes 4
    //

    make_zeros(board_exp);
    make_zeros(board_res);
    make_board(board_exp);
    make_board(board_res);

    board_res[1][3] = 0;
    board_res[4][3] = 'p';

    board_res[6][2] = 0;
    board_res[4][2] = 'P';

    en_passant = 1;
    figure_code = 'p';
    prev_lit = 'd';
    prev_num = '4';
    next_lit = 'c';
    next_num = '3';

    move_figure(
            board_res,
            prev_lit,
            prev_num,
            next_lit,
            next_num,
            figure_code,
            en_passant);

    board_exp[1][3] = 0;
    board_exp[6][2] = 0;
    board_exp[5][2] = 'p';

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            ASSERT_EQUAL(board_exp[i][j], board_res[i][j]);
        }
    }

    //
    // subtes 5
    //

    make_zeros(board_exp);
    make_zeros(board_res);
    make_board(board_exp);
    make_board(board_res);

    board_res[1][3] = 0;
    board_res[4][3] = 'p';

    board_res[6][4] = 0;
    board_res[4][4] = 'P';

    en_passant = 1;
    figure_code = 'p';
    prev_lit = 'd';
    prev_num = '4';
    next_lit = 'e';
    next_num = '3';

    move_figure(
            board_res,
            prev_lit,
            prev_num,
            next_lit,
            next_num,
            figure_code,
            en_passant);

    board_exp[1][3] = 0;
    board_exp[6][4] = 0;
    board_exp[5][4] = 'p';

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            ASSERT_EQUAL(board_exp[i][j], board_res[i][j]);
        }
    }
}
