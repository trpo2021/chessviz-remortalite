#include <board.h>

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {};
    make_board(board);
    print_board(board);
}
