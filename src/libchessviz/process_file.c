#include <libchessviz/board.h>
#include <libchessviz/move.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 20
#define PATH_TO_FILE "./game.txt"

void make_movements(int board[BOARD_SIZE][BOARD_SIZE], char** game_arr, int cnt_line) {
	// game_arr[cnt_line][MAX_LINE_LEN]
	// input format: "N. Pw-Pw Pb-Pb"
	char c;

	int j = 0;
	int idx_dot = 0;

	int line = 0;
	while ((c = game_arr[line][j++]) != '\0') {
		if (c == '.') {
			idx_dot = j-1;	
		}
	}
	
	int idx_Pw = idx_dot;
	while ((game_arr[line][idx_Pw] < 'a') || 
			(game_arr[line][idx_Pw] > 'h')) idx_Pw++;

	printf("idx_Pw: %d\n", idx_Pw);
	move_figure(board, game_arr[line][idx_Pw], game_arr[line][idx_Pw+1], 
			game_arr[line][idx_Pw+3], game_arr[line][idx_Pw+4]);
	
	cnt_line *= 1;
	printf("idx_dot = %d\n", idx_dot);
}

void process_file(int board[BOARD_SIZE][BOARD_SIZE])
{
    FILE* fp = fopen(PATH_TO_FILE, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot process the file %s\n", PATH_TO_FILE);
        exit(1);
    }

    int cnt_line = 8;
    char** game_arr = (char**)malloc(cnt_line * sizeof(char*));
    if (game_arr == NULL) {
        fprintf(stderr, "Cannot allocate memory!\n");
        exit(2);
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
                exit(3);
            }
        }

        // allocate memory for lines
        game_arr[i] = malloc(MAX_LINE_LEN);
        if (game_arr[i] == NULL) {
            fprintf(stderr, "Cannot allocate memory!\n");
            exit(4);
        }

        // fill game_arr with lines
        if (fgets(game_arr[i], MAX_LINE_LEN - 1, fp) == NULL)
            break;

		// remove \n, \r and spaces at the end of lines, add \0 symbol
        for (j = strlen(game_arr[i]) - 1; j >= 0; j--) {
            if ((game_arr[i][j] != '\n') && (game_arr[i][j] != '\r')
                && (game_arr[i][i] != ' '))
                break;
        }
        game_arr[i][j + 1] = '\0';
    }
    fclose(fp);

    for (int k = 0; k < i; k++)
        printf("%s\n", game_arr[k]);

    make_movements(board, game_arr, cnt_line);
}
