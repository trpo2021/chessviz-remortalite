#include <libchessviz/board.h>
#include <libchessviz/checks.h>
#include <stdio.h>
#include <stdlib.h>

void check_is_exist(
        int board[BOARD_SIZE][BOARD_SIZE],
        int figure_code,
        int num_idx,
        int lit_idx)
{
    if (board[num_idx][lit_idx] != make_figure(figure_code, 0)
        && board[num_idx][lit_idx] != make_figure(figure_code, 1)) {
        fprintf(stderr, "Error! No figure on the cell!\n");
        exit(ERROR_NO_FIGURE);
    }
}

void check_range_of_fields(char num, char lit)
{
    if (!(lit >= 'a' && lit <= 'h') || !(num >= '1' && num <= '8')) {
        fprintf(stderr,
                "Error! Wrong number(1-8) or letter(a-h) of the cell.\n");
        exit(ERROR_NOT_ON_BOARD);
    }
}
