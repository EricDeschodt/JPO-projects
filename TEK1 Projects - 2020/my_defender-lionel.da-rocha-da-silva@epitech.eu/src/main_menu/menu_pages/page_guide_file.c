/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** open_file.c
*/

#include "stdlib.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "defender.h"

int open_file(char *path)
{
    return open(path, O_RDONLY);
}

void read_guide(s_game *g)
{
    char *str = malloc(sizeof(char) * 3092);
    int fd = open_file("res/guide");
    g->guide = malloc(sizeof(char) * 3092);
    g->guide[0] = '\0';
    str[0] = '\0';
    char *s = get_next_line(fd);
    while (s) {
        my_strcat(g->guide, s);
        my_strcat(g->guide, "\n");
        free(s);
        s = get_next_line(fd);
    }
    free(s);
}