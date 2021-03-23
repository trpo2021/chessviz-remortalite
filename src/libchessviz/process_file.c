#include <libchessviz/checks.h>
#include <libchessviz/constants.h>
#include <libchessviz/move.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_file(int board[BOARD_SIZE][BOARD_SIZE], const char* path_to_file)
{
    FILE* fp = fopen(path_to_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot process the file %s\n", path_to_file);
        exit(ERROR_FILE_PROCESSING);
    }

    int cnt_line = 8;
    char** game_arr = (char**)malloc(cnt_line * sizeof(char*));
    if (game_arr == NULL) {
        fprintf(stderr, "Cannot allocate memory!\n");
        exit(ERROR_MEMORY_ALLOCATION);
    }

    int i;
    for (i = 0; 1; i++) {
        int j = 0;

        // reallocate game_arr if i >= cnt_line
        if (i >= cnt_line) {
            cnt_line *= 2;
            game_arr = realloc(game_arr, cnt_line * sizeof(char*));
            if (game_arr == NULL) {
                fprintf(stderr, "Cannot allocate memory!\n");
                exit(ERROR_MEMORY_ALLOCATION);
            }
        }

        // allocate memory for lines
        game_arr[i] = malloc(MAX_LINE_LEN);
        if (game_arr[i] == NULL) {
            fprintf(stderr, "Cannot allocate memory!\n");
            exit(ERROR_MEMORY_ALLOCATION);
        }

        // fill game_arr with lines
        if (fgets(game_arr[i], MAX_LINE_LEN - 1, fp) == NULL)
            break;

        // remove \n, \r and spaces at the end of lines, add \0 symbol
        for (j = strlen(game_arr[i]) - 1; j >= 0; j--) {
            if ((game_arr[i][j] != '\n') && (game_arr[i][j] != '\r'))
                break;
        }
        game_arr[i][j + 1] = '\0';
    }
    fclose(fp);
    /*
        for (int k = 0; k < i; k++)
            printf("%s\n", game_arr[k]);
    */
    make_movements(board, game_arr, cnt_line);
}
