#include <libchessviz/checks.h>
#include <libchessviz/constants.h>
#include <libchessviz/move.h>
#include <libchessviz/str_processing.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void make_movements(
        int board[BOARD_SIZE][BOARD_SIZE], char** game_arr, int cnt_line)
{
    // game_arr[cnt_line][MAX_LINE_LEN]
    // input format: "N. Pw-Pw Pb-Pb"

    char* p_dot = NULL;

    for (int line = 0; line < cnt_line; line++) {
        if (game_arr[line][0] == '\0' || strlen(game_arr[line]) == 0)
            break;

        long step = strtol(game_arr[line], &p_dot, 10);
        printf("Step: %ld\n", step);

        char* p_Pw = p_dot + 1;
        strip_beg(&p_Pw);
        printf("p_Pw: %s\n", p_Pw);

        int idx_Pw = 0;
        move_figure(
                board,
                p_Pw[idx_Pw],
                p_Pw[idx_Pw + 1],
                p_Pw[idx_Pw + 3],
                p_Pw[idx_Pw + 4]);

        char* p_Pb = p_Pw + 5 + (p_Pw[5] == ' ' ? 1 : 0);
        int idx_Pb = 0;
        move_figure(
                board,
                p_Pb[idx_Pb],
                p_Pb[idx_Pb + 1],
                p_Pb[idx_Pb + 3],
                p_Pb[idx_Pb + 4]);

        print_board(board);
    }
}
