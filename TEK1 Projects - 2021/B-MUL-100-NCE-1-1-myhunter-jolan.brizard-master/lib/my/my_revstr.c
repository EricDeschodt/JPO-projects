/*
** EPITECH PROJECT, 2020
** my revstr
** File description:
** lol
*/

#include "print.h"

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int o = my_strlen(str) - 1;

    while (i <= o) {
        char e = str[i];
        str[i] = str[o];
        str[o] = e;
        i++;
        o--;
    }
    return (str);
}