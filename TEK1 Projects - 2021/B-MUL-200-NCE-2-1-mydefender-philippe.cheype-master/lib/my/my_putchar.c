/*
** EPITECH PROJECT, 2020
** My Put Char
** File description:
** Uses function write
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
