/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** Write a char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
