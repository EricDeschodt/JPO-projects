/*
** EPITECH PROJECT, 2019
** get_value
** File description:
** get_value
*/

#include "my.h"
#include <stdlib.h>

int get_value(char *str, int index)
{
    if (index < my_strlen(str)) {
        return (str[my_strlen(str) - index - 1] - 48);
    }
    return (0);
}
