/*
** EPITECH PROJECT, 2020
** B-CPE-110-NCE-1-1-BSQ-mathis.vinay
** File description:
** a function who prints the result of a bool
*/

#include <stdbool.h>

int my_putstr(char const *str);

void my_put_bool(bool b)
{
    if (b == true)
        my_putstr("true");
    else
        my_putstr("false");
}