/*
** EPITECH PROJECT, 2020
** My_putstr
** File description:
** My_putstr
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
