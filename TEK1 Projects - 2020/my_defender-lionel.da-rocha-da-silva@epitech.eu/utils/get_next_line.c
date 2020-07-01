/*
** EPITECH PROJECT, 2019
** get next line
** File description:
** get next line
*/

#include "get_next_line.h"

char *read_end(int i, char *buffer)
{
    if (i != 0) {
        buffer[i] = '\0';
        return (buffer);
    }
    else
        return (NULL);
}

char *read_line(int fd, char *buff, char *buffer, int i)
{
    static int k = 0, len = 0;
    if (k == 0) {
        if ((len = read(fd, buff, READ_SIZE)) > 0);
        else
            return (read_end(i, buffer));
    }
    while (k < len) {
        if (buff[k] == '\n') {
            buffer[i] = '\0';
            k++, i = 0;
            return (buffer);
        }
        buffer[i++] = buff[k++];
    }
    k = 0, len = 0;
    return (read_line(fd, buff, buffer, i));
}

char *get_next_line(int fd)
{
    static int i = 0;
    static char buff[READ_SIZE];
    char *buffer = malloc(256);

    if (buffer == NULL)
        return (NULL);
    if (fd < 0 || fd > 1024 || READ_SIZE == 0)
        return (NULL);
    if ((buffer = read_line(fd, buff, buffer, i)) == NULL) {
        free(buffer);
        return (NULL);
    }
    return (buffer);
}
