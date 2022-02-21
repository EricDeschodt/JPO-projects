/*
** EPITECH PROJECT, 2020
** strup case
** File description:
** strup
*/

#include "../include/print.h"

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
        i++;
    }
    str[i] = '\0';
    return (str);
}
