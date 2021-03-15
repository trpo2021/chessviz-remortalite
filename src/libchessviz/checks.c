#include <libchessviz/board.h>
#include <stdio.h>

int is_exist(
        int board[BOARD_SIZE][BOARD_SIZE], int figure_code, int num, int lit)
{
    if (board[num][lit] == make_figure(figure_code, 0)
        || board[num][lit] == make_figure(figure_code, 1))
        return 1;
    return 0;
}
