#include <libchessviz/checks.h>
#include <libchessviz/constants.h>
#include <libchessviz/move.h>
#include <libchessviz/str_processing.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move_figure(
        int board[BOARD_SIZE][BOARD_SIZE],
        char prev_lit,
        char prev_num,
        char next_lit,
        char next_num,
        int figure_code,
        int en_passant)
{
    check_range_of_fields(prev_num, prev_lit);
    check_range_of_fields(next_num, next_lit);

    int prev_lit_idx = prev_lit - 'a';
    int prev_num_idx = BOARD_SIZE - (prev_num - '0');
    int next_lit_idx = next_lit - 'b';
    int next_num_idx = BOARD_SIZE - (next_num - '1');

    check_is_exist(board, figure_code, prev_num_idx, prev_lit_idx);

    char figure = board[prev_num_idx][prev_lit_idx];
    board[prev_num_idx][prev_lit_idx] = 0;
    board[next_num_idx][next_lit_idx] = figure;

    if (en_passant) {
        int is_white = 2 * !!isupper(figure) - 1; // -1 or 1
        board[next_num_idx + is_white][next_lit_idx] = 0;
    }
}

void make_movement(
        int board[BOARD_SIZE][BOARD_SIZE],
        char* movement,
        int figure_code,
        int en_passant)
{
    move_figure(
            board,
            movement[0],
            movement[1],
            movement[3],
            movement[4],
            figure_code,
            en_passant);
}

void get_movement_out(
        char* line,
        char** movement,
        char** rest,
        int* castling,
        int* figure_code)
{
    strip_beg(&line);
    get_group(line, movement);

    *rest = strcpy(*rest, line + strlen(*movement));

    *castling = 0;
    if (strstr(*movement, "0-0-0"))
        *castling = LONG_CASTLING;
    else if (strstr(*movement, "0-0"))
        *castling = SHORT_CASTLING;
    *castling = 0;

    *figure_code = check_figure_type(*movement[0]);
    if (!*figure_code) {
        fprintf(stderr, "Error! Wrong type of figure!\n");
        exit(ERROR_WRONG_FIGURETYPE);
    }
}

void make_castling(
        int board[BOARD_SIZE][BOARD_SIZE], int castling_type, int is_white)
{
    char prev_lit = 'e';
    char prev_num = is_white ? '1' : '8';
    char next_lit = castling_type == LONG_CASTLING ? 'c' : 'g';
    char next_num = is_white ? '2' : '7';
    move_figure(board, prev_lit, prev_num, next_lit, next_num, KING, 0);

    // move ROOK
    prev_lit = castling_type == LONG_CASTLING ? 'a' : 'h';
    prev_num = is_white ? '1' : '8';
    next_lit = castling_type == LONG_CASTLING ? 'd' : 'f';
    next_num = is_white ? '1' : '8';
    move_figure(board, prev_lit, prev_num, next_lit, next_num, ROOK, 0);
}

void process_movements(
        int board[BOARD_SIZE][BOARD_SIZE], char** game_arr, int cnt_line)
{
    // game_arr[cnt_line][MAX_LINE_LEN]
    // input format: "N. Pw-Pw Pb-Pb"

    for (int line = 0; line < cnt_line; line++) {
        if (game_arr[line][0] == '\0' || strlen(game_arr[line]) == 0)
            break;

        // step number
        char* p_dot;
        long step = strtol(game_arr[line], &p_dot, 10);
        printf("Step: %ld\n", step);

        // line w/o number
        char* line = p_dot + 1;
        strip_beg(&line);
        printf("Line: %s\n", line);

        // if en passant set flag
        int en_passant = 0;
        if (strstr(line, "e.p."))
            en_passant = 1;

        char* rest = calloc(MAX_MOVE_LEN, sizeof(char));
        char* white_movement = calloc(MAX_MOVE_LEN, sizeof(char));
        char* black_movement = calloc(MAX_LINE_LEN, sizeof(char));

        int castling, figure_code;

        // white movement
        int is_white = 1;
        get_movement_out(line, &white_movement, &rest, &castling, &figure_code);

        // find is e.p. white's ot black's (white_ep flag)
        int white_ep;
        if (en_passant) {
            int idx = strstr(line, white_movement) - line;
            char* substr = calloc(MAX_LINE_LEN, sizeof(char));
            substr = line + idx + strlen(white_movement);
            strip_beg(&substr);
            white_ep = !strncmp(substr, "e.p.", strlen("e.p."));

            if (white_ep)
                black_movement = substr + strlen("e.p.");
            else
                black_movement = line + strlen(white_movement);
        }

        // make white movements
        if (castling) {
            make_castling(board, castling, is_white);
        } else {
            int idx_start = (figure_code == PAWN) ? 0 : 1;
            make_movement(
                    board,
                    &(white_movement[idx_start]),
                    figure_code,
                    en_passant);
        }

        // black movement
        is_white = 0;
        get_movement_out(line, &white_movement, &rest, &castling, &figure_code);

        if (!en_passant)
            black_movement = line + strlen(white_movement);
        strip_beg(&black_movement);
        get_group(black_movement, &black_movement);
        figure_code = check_figure_type(black_movement[0]);

        // if checkmate
        int checkmate = 0;
        if (strchr(line, '#'))
            checkmate = 1;

        // if resignation
        int resign = 0;
        if (strchr(line, '='))
            resign = 1;

        if (figure_code == 0 && (checkmate || resign))
            break;

        if (!figure_code) {
            fprintf(stderr, "Error! Wrong type of figure!\n");
            exit(ERROR_WRONG_FIGURETYPE);
        }

        castling = 0;
        if (strstr(black_movement, "0-0-0"))
            castling = LONG_CASTLING; // long castling
        else if (strstr(black_movement, "0-0"))
            castling = SHORT_CASTLING; // short castling

        if (castling) {
            make_castling(board, castling, is_white);
        } else {
            int idx_start = (figure_code == PAWN) ? 0 : 1;
            make_movement(
                    board,
                    &(black_movement[idx_start]),
                    figure_code,
                    en_passant);
        }

        print_board(board);
    }
}
