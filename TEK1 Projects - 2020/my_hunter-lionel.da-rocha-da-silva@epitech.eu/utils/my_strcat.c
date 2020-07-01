/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *rdest = dest;

    while (*dest) {
        dest++;
    }
    while (*dest++ = *src++) {
    }

    return rdest;
}
