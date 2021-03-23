#ifndef MOVE_H
#define MOVE_H

#include <libchessviz/constants.h>

void make_movements(int board[BOARD_SIZE][BOARD_SIZE], char**, int);

void move_figure(int board[BOARD_SIZE][BOARD_SIZE], char, char, char, char);

#endif
