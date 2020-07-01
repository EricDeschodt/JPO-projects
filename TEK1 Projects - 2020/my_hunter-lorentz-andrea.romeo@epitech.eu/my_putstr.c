/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** Displays, one-by-one, the characters of a string.
*/

#include "my.h"

int my_putstr(char const *str)
{
    while (*str) {
        my_putchar(*str);
        str++;
    }
    return (0);
}
