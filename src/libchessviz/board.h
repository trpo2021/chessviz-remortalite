#ifndef BOARD_H
#define BOARD_H

#include <libchessviz/constants.h>

enum Figures {
    PAWN = 112,
    BISHOP = 98,
    KNIGHT = 110,
    ROOK = 114,
    QUEEN = 113,
    KING = 107,
};

void print_board(int (*)[BOARD_SIZE]);

int make_figure(int, int);

void make_board(int (*)[BOARD_SIZE]);

#endif
