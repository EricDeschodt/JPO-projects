/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** top_score
*/

#include "my.h"

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