#include <stdio.h>

#define BOARD_SIZE 8

enum Figures {
    PAWN = 112,
    BISHOP = 98,
    KNIGHT = 110,
    ROOK = 114,
    QUEEN = 113,
    KING = 107,
};

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j])
                printf("%c ", board[i][j]);
            else
                printf("%c ", ' ');
        }
        putchar('\n');
    }
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

    board[1][0] = make_figure(PAWN, 0);
    board[1][1] = make_figure(PAWN, 0);
    board[1][2] = make_figure(PAWN, 0);
    board[1][3] = make_figure(PAWN, 0);
    board[1][4] = make_figure(PAWN, 0);
    board[1][5] = make_figure(PAWN, 0);
    board[1][6] = make_figure(PAWN, 0);
    board[1][7] = make_figure(PAWN, 0);

    board[7][0] = make_figure(ROOK, 1);
    board[7][1] = make_figure(KNIGHT, 1);
    board[7][2] = make_figure(BISHOP, 1);
    board[7][3] = make_figure(QUEEN, 1);
    board[7][4] = make_figure(KING, 1);
    board[7][5] = make_figure(BISHOP, 1);
    board[7][6] = make_figure(KNIGHT, 1);
    board[7][7] = make_figure(ROOK, 1);

    board[6][0] = make_figure(PAWN, 1);
    board[6][1] = make_figure(PAWN, 1);
    board[6][2] = make_figure(PAWN, 1);
    board[6][3] = make_figure(PAWN, 1);
    board[6][4] = make_figure(PAWN, 1);
    board[6][5] = make_figure(PAWN, 1);
    board[6][6] = make_figure(PAWN, 1);
    board[6][7] = make_figure(PAWN, 1);
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {};
    make_board(board);
    print_board(board);
}
