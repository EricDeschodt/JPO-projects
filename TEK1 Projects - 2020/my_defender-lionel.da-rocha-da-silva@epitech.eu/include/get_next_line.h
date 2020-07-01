/*
** EPITECH PROJECT, 2019
** get next line header
** File description:
** get next line header
*/

#ifndef READ_SIZE
#define READ_SIZE (256)

#endif

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char *read_end(int i, char *buffer);
char *read_line(int fd, char *buff, char *buffer, int i);
char *get_next_line(int fd);

#endif
