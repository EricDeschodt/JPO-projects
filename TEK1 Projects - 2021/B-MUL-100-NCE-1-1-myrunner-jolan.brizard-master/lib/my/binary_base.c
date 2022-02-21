/*
** EPITECH PROJECT, 2020
** test
** File description:
** binary base
*/

#include "../include/print.h"

char *binary(int nb, char *str)
{
    if (nb < 0)
        nb *= -1;
    int i = 0;
    char rem = 0;

    while (nb) {
        rem = nb % 2;
        if (rem == -1)
            str[i] = rem + 50;
        else
            str[i] = rem + 48;
        nb /= 2;
        i++;
    }
    str[i] = '\0';
    return my_revstr(str);
}

void my_put_binary(int nb)
{
    char *string = malloc(64);
    my_putstr(binary(nb, string));
    free(string);
}