/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** chaine
*/

#include "../../include/include.h"

void my_putchar(char a)
{
    write(1, &a, 1);
}

int my_putstr(char const *str)
{
    for (int n = 0; str[n]; n++)
        my_putchar(str[n]);
    return (0);
}