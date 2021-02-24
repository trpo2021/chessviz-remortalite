#include <stdio.h>

#define PAWN 112
#define BISHOP 98
#define KNIGHT 110
#define ROOK 114
#define QUEEN 113
#define KING 107

void printBoard(int board[8][8])
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j])
                printf("%c ", board[i][j]);
            else
                printf("%c ", ' ');
        }
        putchar('\n');
    }
}

int makeFigure(int figure, int isWhite)
{
    return figure - isWhite * 32;
}

void makeBoard(int board[8][8])
{
    board[0][0] = makeFigure(ROOK, 0);
    board[0][1] = makeFigure(KNIGHT, 0);
    board[0][2] = makeFigure(BISHOP, 0);
    board[0][3] = makeFigure(QUEEN, 0);
    board[0][4] = makeFigure(KING, 0);
    board[0][5] = makeFigure(BISHOP, 0);
    board[0][6] = makeFigure(KNIGHT, 0);
    board[0][7] = makeFigure(ROOK, 0);

    board[1][0] = makeFigure(PAWN, 0);
    board[1][1] = makeFigure(PAWN, 0);
    board[1][2] = makeFigure(PAWN, 0);
    board[1][3] = makeFigure(PAWN, 0);
    board[1][4] = makeFigure(PAWN, 0);
    board[1][5] = makeFigure(PAWN, 0);
    board[1][6] = makeFigure(PAWN, 0);
    board[1][7] = makeFigure(PAWN, 0);

    board[7][0] = makeFigure(ROOK, 1);
    board[7][1] = makeFigure(KNIGHT, 1);
    board[7][2] = makeFigure(BISHOP, 1);
    board[7][3] = makeFigure(QUEEN, 1);
    board[7][4] = makeFigure(KING, 1);
    board[7][5] = makeFigure(BISHOP, 1);
    board[7][6] = makeFigure(KNIGHT, 1);
    board[7][7] = makeFigure(ROOK, 1);

    board[6][0] = makeFigure(PAWN, 1);
    board[6][1] = makeFigure(PAWN, 1);
    board[6][2] = makeFigure(PAWN, 1);
    board[6][3] = makeFigure(PAWN, 1);
    board[6][4] = makeFigure(PAWN, 1);
    board[6][5] = makeFigure(PAWN, 1);
    board[6][6] = makeFigure(PAWN, 1);
    board[6][7] = makeFigure(PAWN, 1);
}

int main()
{
    int board[8][8] = {};
    makeBoard(board);
    printBoard(board);
}
