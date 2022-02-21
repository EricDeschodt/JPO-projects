/*
** EPITECH PROJECT, 2020
** my putstr
** File description:
** print every caracter in a char using my put char
*/

#include "print.h"

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return (1);

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}