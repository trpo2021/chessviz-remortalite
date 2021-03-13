#include <libchessviz/board.h>
#include <libchessviz/move.h>
#include <libchessviz/process_file.h>

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {};
    make_board(board);
    print_board(board);
    process_file(board);
    print_board(board);

    return 0;
}
