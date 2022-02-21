/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** print the given str
*/

#include <unistd.h>

unsigned long long my_strlen(char const *str);

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}
