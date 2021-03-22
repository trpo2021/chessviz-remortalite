#include <libchessviz/board.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void strip_beg(char** str)
{
    char* line = calloc(MAX_LINE_LEN, sizeof(char));
    int i, start_idx = 0;
    for (i = 0; i < MAX_LINE_LEN && (*str)[i] != '\0'; i++) {
        if ((*str)[i] == ' ' || (*str)[i] == '\n')
            start_idx++;
        else
            break;
    }
    for (i = start_idx; i < MAX_LINE_LEN && (*str)[i] != '\0'; i++) {
        line[i - start_idx] = (*str)[i];
    }
    *str = line;
}

void get_group(char* str, char** p_new_str)
{
    char* line = calloc(MAX_LINE_LEN, sizeof(char));
    int i, end_idx = 0;
    for (i = 0; i < MAX_LINE_LEN && str[i] != '\0'; i++) {
        char c = str[i];
        if (isalpha(c) || isdigit(c))
            end_idx++;
        else
            break;
    }
    for (i = 0; i < end_idx; i++) {
        line[i] = str[i];
    }
    line[end_idx + 1] = '\0';
    *p_new_str = line;
}
