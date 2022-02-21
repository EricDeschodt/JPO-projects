/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** copies a string
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    str = malloc(my_strlen(src) + 1);
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

char *my_strdupn(char const *src, int limit)
{
    char *str;
    int i = 0;

    str = malloc(my_strlen(src) + 1);
    while (src[i] != '\0' && i < limit) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}