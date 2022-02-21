/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCE-1-1-navy-mathis.vinay
** File description:
** fnc for getting a file ctn
*/

#include "../include/files.h"

char *my_get_file_ctn(char const *filepath)
{
    if (!my_is_file_valid(filepath))
        return NULL;
    int file = open(filepath, 'r');
    char *buff = malloc(BUFSIZ + 1);
    int offset = 0;
    int len;
    while ((len = read(file, buff + offset , BUFSIZ - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    close(file);
    return buff;
}