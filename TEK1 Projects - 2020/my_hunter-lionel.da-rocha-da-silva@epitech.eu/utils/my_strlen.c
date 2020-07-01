/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** counts the length of the string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return (i);
}
