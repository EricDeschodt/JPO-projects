/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Displays the number given as a parameter.
*/

#include "my.h"

char *my_put_nbr(int nb, char *str)
{
    int i = 0;
    while (nb > 0) {
        str[i] = (nb % 10 + '0');
        nb = nb / 10;
        i++;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}
