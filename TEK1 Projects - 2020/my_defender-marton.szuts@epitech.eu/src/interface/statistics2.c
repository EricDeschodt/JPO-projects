/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** statistics2
*/

#include "defender.h"
#include "utils.h"

void write_statistics(all_t *s_all)
{
    int fd = open("statistics/stats", O_RDWR);
    if (fd < 0)
        return;
    char *str = malloc(sizeof(char) * 100);
    str[0] = '\0';
    my_strcat(str, strnbr(s_all->s_stats.coins)), my_strcat(str, "\n");
    my_strcat(str, strnbr(s_all->s_stats.killed)), my_strcat(str, "\n");
    my_strcat(str, strnbr(s_all->s_stats.passed)), my_strcat(str, "\n");
    my_strcat(str, strnbr(s_all->s_stats.defeated)), my_strcat(str, "\n");
    my_strcat(str, strnbr(s_all->s_stats.score)), my_strcat(str, "\n");
    my_strcat(str, strnbr(s_all->s_stats.built)), my_strcat(str, "\n");
    my_strcat(str, strnbr(s_all->s_stats.sold)), my_strcat(str, "\n");
    my_strcat(str, strnbr(s_all->s_stats.started));
    write(fd, str, my_strlen(str));
    close(fd);
    free(str);
}