#include <libchessviz/board.h>
#include <libchessviz/constants.h>

#include <stdio.h>

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    puts("------------------");
    puts("   a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j])
                printf("%c ", board[i][j]);
            else
                printf("%c ", ' ');
        }
        putchar('\n');
    }
    puts("------------------");
    putchar('\n');
}

int make_figure(int figure, int isWhite)
{
    return figure - isWhite * 32;
}

void make_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    board[0][0] = make_figure(ROOK, 0);
    board[0][1] = make_figure(KNIGHT, 0);
    board[0][2] = make_figure(BISHOP, 0);
    board[0][3] = make_figure(QUEEN, 0);
    board[0][4] = make_figure(KING, 0);
    board[0][5] = make_figure(BISHOP, 0);
    board[0][6] = make_figure(KNIGHT, 0);
    board[0][7] = make_figure(ROOK, 0);

    for (int i = 0; i < BOARD_SIZE; i++)
        board[1][i] = make_figure(PAWN, 0);

    board[7][0] = make_figure(ROOK, 1);
    board[7][1] = make_figure(KNIGHT, 1);
    board[7][2] = make_figure(BISHOP, 1);
    board[7][3] = make_figure(QUEEN, 1);
    board[7][4] = make_figure(KING, 1);
    board[7][5] = make_figure(BISHOP, 1);
    board[7][6] = make_figure(KNIGHT, 1);
    board[7][7] = make_figure(ROOK, 1);

    for (int i = 0; i < BOARD_SIZE; i++)
        board[6][i] = make_figure(PAWN, 1);
}
