#include <libchessviz/board.h>
#include <libchessviz/checks.h>
#include <libchessviz/move.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 20

void make_movements(
        int board[BOARD_SIZE][BOARD_SIZE], char** game_arr, int cnt_line)
{
    // game_arr[cnt_line][MAX_LINE_LEN]
    // input format: "N. Pw-Pw Pb-Pb"

    char* p_dot = NULL;

    for (int line = 0; line < cnt_line; line++) {
        if (game_arr[line][0] == '\0' || strlen(game_arr[line]) == 0)
            break;

        long step = strtol(game_arr[line], &p_dot, 10);
        printf("Step: %ld\n", step);
        printf("Str: %s\n", p_dot + 1);

        char* p_Pw = p_dot + 1 + (p_dot[1] == ' ' ? 1 : 0);
        printf("p_Pw: %s\n", p_Pw);
        putchar(*(p_Pw + 0));

        int idx_Pw = 0;
        move_figure(
                board,
                p_Pw[idx_Pw],
                p_Pw[idx_Pw + 1],
                p_Pw[idx_Pw + 3],
                p_Pw[idx_Pw + 4]);

        char* p_Pb = p_Pw + 5 + (p_Pw[5] == ' ' ? 1 : 0);
        int idx_Pb = 0;
        move_figure(
                board,
                p_Pb[idx_Pb],
                p_Pb[idx_Pb + 1],
                p_Pb[idx_Pb + 3],
                p_Pb[idx_Pb + 4]);

        print_board(board);
    }
}

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
