/*
** EPITECH PROJECT, 2020
** My Put String
** File description:
** Decomposes String Characters one-by-one
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    return (write(1, str, my_strlen(str)));
}
