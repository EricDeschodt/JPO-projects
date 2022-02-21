/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** displays N if integer is <0 and displays P if positive or null
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    my_putchar('\n');
    return (0);
}