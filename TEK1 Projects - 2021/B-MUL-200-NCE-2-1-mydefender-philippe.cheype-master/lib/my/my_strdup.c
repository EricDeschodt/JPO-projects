/*
** EPITECH PROJECT, 2020
** My Str Dup
** File description:
** Allocates memory and writes string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;
    int n = 0;

    str = malloc(my_strlen(src) + 1);
    for (; src[n] != '\0'; n++)
        str[n] = src[n];
    str[n] = '\0';
    return (str);
}
