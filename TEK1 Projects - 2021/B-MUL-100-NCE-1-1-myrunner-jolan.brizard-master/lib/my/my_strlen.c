/*
** EPITECH PROJECT, 2020
** y_strlen
** File description:
** lol
*/

#include "../include/print.h"

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}