#include <libchessviz/board.h>
#include <libchessviz/move.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 20
#define PATH_TO_FILE "./game.txt"

void make_movements(
        int board[BOARD_SIZE][BOARD_SIZE], char** game_arr, int cnt_line)
{
    // game_arr[cnt_line][MAX_LINE_LEN]
    // input format: "N. Pw-Pw Pb-Pb"

    int idx_dot = 0;

    for (int line = 0; line < cnt_line; line++) {
        if (game_arr[line][0] == '\0' || strlen(game_arr[line]) == 0)
            break;

        idx_dot = strchr(game_arr[line], '.') - game_arr[line];

        int idx_Pw = idx_dot;
        while (((game_arr[line][idx_Pw] < 'a')
                || (game_arr[line][idx_Pw] > 'h'))
               && (game_arr[line][idx_Pw] != '\0'))
            idx_Pw++;

        puts(game_arr[line]);

        move_figure(
                board,
                game_arr[line][idx_Pw],
                game_arr[line][idx_Pw + 1],
                game_arr[line][idx_Pw + 3],
                game_arr[line][idx_Pw + 4]);

        int idx_Pb = idx_Pw + 6;
        move_figure(
                board,
                game_arr[line][idx_Pb],
                game_arr[line][idx_Pb + 1],
                game_arr[line][idx_Pb + 3],
                game_arr[line][idx_Pb + 4]);

        print_board(board);
    }
}

void process_file(int board[BOARD_SIZE][BOARD_SIZE])
{
    FILE* fp = fopen(PATH_TO_FILE, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot process the file %s\n", PATH_TO_FILE);
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

    for (int k = 0; k < i; k++)
        printf("%s\n", game_arr[k]);

    make_movements(board, game_arr, cnt_line);
}
