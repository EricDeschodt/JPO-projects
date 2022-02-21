/*
** EPITECH PROJECT, 2020
** my put char function
** File description:
** print a char
*/

#include "../include/print.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}