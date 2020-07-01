/*
** EPITECH PROJECT, 2020
** gnl
** File description:
** gnl
*/

#include "../../include/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int my_strlen(char *str)
{
    int len = 0;
    for (len = 0; str[len] != '\0'; len++);
    return (len);
}

char *add_to_str(char *str, char *add, int pos, int error)
{
    int i = 0;
    char *buffer;

    for (i = 0; str[i] != '\0'; i++);
    buffer = malloc(sizeof(char) * (i + READ_SIZE - pos + 1));
    for (i = 0; str[i] != '\0'; i++)
        buffer[i] = str[i];
    for (int o = pos; o < READ_SIZE; o++)
        buffer[o - pos + i] = add[o];
    buffer[i + READ_SIZE - pos - READ_SIZE + error] = '\0';
    free(str);
    str = buffer;
    return (str);
}

char *get_fin(char *str)
{
    int l1 = 0;
    int l2 = 0;
    char *buffer;

    if (str[0] == '\0')
        return (NULL);
    for (l1 = 0; str[l1] != '\0'; l1++);
    for (l2 = 0; str[l2] != '\0' && str[l2] != '\n'; l2++);
    buffer = malloc(sizeof(char) * (l1 - (l1 - l2) + 1));
    for (l1 = 0; str[l1] != '\n' && str[l1] != '\0'; l1++)
        buffer[l1] = str[l1];
    buffer[l1] = '\0';
    free(str);
    str = buffer;
    return (str);
}

int get_pos(char *buf, int pos)
{
    int nb = 0;

    for (nb = pos; buf[nb] != '\n' && buf[nb] != '\0' && nb < READ_SIZE; nb++);
    return (nb);
}

char *get_next_line(int fd)
{
    int error, fin = 0;
    char *str = malloc(sizeof(char) * 1);
    static char buf[READ_SIZE];
    static int pos;

    if (fd < 0 || fd > 256 || READ_SIZE <= 0 || str == NULL)
        return (NULL);
    str[0] = '\0';
    error = (buf[0] == 0 || pos == READ_SIZE - 1) ? read(fd, buf, READ_SIZE): 0;
    pos = (pos && pos != READ_SIZE - 1) ? pos : 0;
    while (fin != 1 && error != 0) {
        str = add_to_str(str, buf, pos, error);
        for (int i = pos; i < READ_SIZE; i++)
            (buf[i] == '\n' || buf[i] == '\0') ? fin = 1: 0;
        error = (fin != 1) ? read(fd, buf, READ_SIZE): 0;
        (fin != 1) ? pos = 0: 0;
    }
    str = get_fin(str);
    pos = get_pos(buf, pos);
    return (str);
}