/*
** EPITECH PROJECT, 2020
** My_putchar
** File description:
** Print char
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
