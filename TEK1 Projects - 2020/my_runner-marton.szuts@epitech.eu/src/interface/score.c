/*
** EPITECH PROJECT, 2019
** score
** File description:
** write score in file
*/

#include "runner.h"

int get_score(void)
{
    int fd = open("scores.txt", O_RDWR);
    int best = 0;
    char c;

    for (; read(fd, &c, 1) == 1 && c != ';';)
        best = best * 10 + (c - 48);
    close(fd);
    return (best);
}

void write_score(controll_t *s_controll)
{
    int size = my_strlen(s_controll->s_interface.end.strscore);
    int best = get_score();
    int fd = open("scores.txt", O_RDWR);

    if (s_controll->s_interface.end.score_int > best) {
        write(fd, s_controll->s_interface.end.strscore, size);
        write(fd, ";", 1);
    }
    close(fd);
}