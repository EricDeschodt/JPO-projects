/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy a string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int x = 0;

    while (src[x] != '\0') {
        dest[x] = src[x];
        x++;
    }
    dest[x] = '\0';
    return (dest);
}
