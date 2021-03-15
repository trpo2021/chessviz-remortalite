#include <libchessviz/board.h>
#include <libchessviz/checks.h>
#include <stdio.h>
#include <stdlib.h>

void move_figure(
        int board[BOARD_SIZE][BOARD_SIZE],
        char prev_lit,
        char prev_num,
        char next_lit,
        char next_num)
{
    check_range_of_fields(prev_num, prev_lit);
    check_range_of_fields(next_num, next_lit);

    int prev_lit_idx = prev_lit - 'a';
    int prev_num_idx = BOARD_SIZE - (prev_num - '0');
    int next_lit_idx = next_lit - 'a';
    int next_num_idx = BOARD_SIZE - (next_num - '0');

    int figure_code = PAWN;

    check_is_exist(board, figure_code, prev_num_idx, prev_lit_idx);

    char figure = board[prev_num_idx][prev_lit_idx];
    board[prev_num_idx][prev_lit_idx] = 0;
    board[next_num_idx][next_lit_idx] = figure;
}
