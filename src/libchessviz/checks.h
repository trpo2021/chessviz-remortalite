#ifndef CHECKS_H
#define CHECKS_H

enum Errors {
    ERROR_FILE_PROCESSING,
    ERROR_MEMORY_ALLOCATION,
    ERROR_WRONG_CELL,
    ERROR_NO_FIGURE,
    ERROR_NOT_ON_BOARD,
};

void check_is_exist(
        int (*)[BOARD_SIZE],
        int figure_code,
        int num,
        int lit); // ERROR_NO_FIGURE

void check_range_of_fields(char num, char lit); // ERROR_NOT_ON_BOARD

void check_if_file_exists(const char*);

#endif
