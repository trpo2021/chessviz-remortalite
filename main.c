#include <stdio.h>

#define PAWN 112
#define BISHOP 98
#define KNIGHT 110
#define ROOK 114
#define QUEEN 113
#define KING 107

void makeFigure(int figure, int isWhite)
{
    putchar(figure - isWhite * 32);
    putchar(' ');
}

void makeBoard()
{
    makeFigure(ROOK, 0);
    makeFigure(KNIGHT, 0);
    makeFigure(BISHOP, 0);
    makeFigure(QUEEN, 0);
    makeFigure(KING, 0);
    makeFigure(BISHOP, 0);
    makeFigure(KNIGHT, 0);
    makeFigure(ROOK, 0);

    putchar('\n');

    makeFigure(PAWN, 0);
    makeFigure(PAWN, 0);
    makeFigure(PAWN, 0);
    makeFigure(PAWN, 0);
    makeFigure(PAWN, 0);
    makeFigure(PAWN, 0);
    makeFigure(PAWN, 0);
    makeFigure(PAWN, 0);

    putchar('\n');
    putchar('\n');
    putchar('\n');
    putchar('\n');
    putchar('\n');

    makeFigure(PAWN, 1);
    makeFigure(PAWN, 1);
    makeFigure(PAWN, 1);
    makeFigure(PAWN, 1);
    makeFigure(PAWN, 1);
    makeFigure(PAWN, 1);
    makeFigure(PAWN, 1);
    makeFigure(PAWN, 1);

    putchar('\n');

    makeFigure(ROOK, 1);
    makeFigure(KNIGHT, 1);
    makeFigure(BISHOP, 1);
    makeFigure(QUEEN, 1);
    makeFigure(KING, 1);
    makeFigure(BISHOP, 1);
    makeFigure(KNIGHT, 1);
    makeFigure(ROOK, 1);

    putchar('\n');
}

int main()
{
    makeBoard();
}

