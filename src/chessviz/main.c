#include <libchessviz/board.h>
#include <libchessviz/checks.h>
#include <libchessviz/move.h>
#include <libchessviz/process_file.h>

#include <stdio.h>
#include <stdlib.h>

#define PATH_TO_FILE "./game.txt"

int main(int argc, char** argv)
{
    int board[BOARD_SIZE][BOARD_SIZE] = {};
    make_board(board);
    print_board(board);

    const char* path = (argc > 1) ? argv[1] : PATH_TO_FILE;

    check_if_file_exists(path);
    printf("Using %s file...\n\n", path);

    process_file(board, path);
    puts("Final:");
    print_board(board);

    return 0;
}
