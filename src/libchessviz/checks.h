#ifndef CHECKS_H
#define CHECKS_H

enum Errors {
    ERROR_FILE_PROCESSING,
    ERROR_MEMORY_ALLOCATION,
    ERROR_WRONG_CELL,
    ERROR_NO_FIGURE,
};

int is_exist(int (*)[BOARD_SIZE], int figure_code, int num, int lit);

#endif
