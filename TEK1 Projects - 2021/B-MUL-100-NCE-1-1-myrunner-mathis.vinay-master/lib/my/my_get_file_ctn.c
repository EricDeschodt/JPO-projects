/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCE-1-1-navy-mathis.vinay
** File description:
** fnc for getting a file ctn
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

unsigned long long my_strlen(char const *);

int my_get_nb_char_in_str(char c, char const *str);

char *my_get_file_ctn(char const *file_adress)
{
    int file = open(file_adress, O_RDONLY);
    if (file == -1)
        return NULL;
    int bufsize = 1126;
    char *ctn = malloc(bufsize);
    read(file, ctn, bufsize);
    close(file);
    if (my_strlen(ctn) != 1126 || my_get_nb_char_in_str('\n', ctn) != 6) {
        free(ctn);
        return NULL;
    }
    return ctn;
}