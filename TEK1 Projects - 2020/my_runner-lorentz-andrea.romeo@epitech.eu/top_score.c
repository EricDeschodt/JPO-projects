/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** top_score
*/

#include "my.h"

void hit_box_stat(all_t *all)
{
    if (all->my_int.level == 0)
        all->my_int.reset = 1;
    else
        all->my_int.menu = 5;
}

void print_top_score(all_t *all)
{
    if (all->my_int.skull > my_atoi(all->write.top_score)) {
        open_write(my_put_nbr(all->my_int.skull, all->write.skull));
        sfText_setString(all->write.text, all->write.skull);
    }
}

char *open_read(void)
{
    char buff;
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    int fd = open("top_score/score.txt", O_RDONLY);
    read(fd, &buff, 1);
    for (; buff != '\n'; i++) {
        str[i] = buff;
        read(fd, &buff, 1);
    }
    str[i] = '\0';
    return (str);
}

void open_write(char *str)
{
    int fd = open("top_score/score.txt", O_WRONLY);
    write(fd, str, my_strlen(str));
    write(fd, "\n", 1);
}
