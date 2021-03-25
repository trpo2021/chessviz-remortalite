#ifndef MOVE_H
#define MOVE_H

#include <libchessviz/constants.h>

void process_movements(int board[BOARD_SIZE][BOARD_SIZE], char**, int);

void make_movement(int board[BOARD_SIZE][BOARD_SIZE], char*, int, int);

void get_movement_out(char*, char**, char**, int*, int*);

void make_castling(int board[BOARD_SIZE][BOARD_SIZE], int, int);

void move_figure(
        int board[BOARD_SIZE][BOARD_SIZE], char, char, char, char, int, int);

#endif
