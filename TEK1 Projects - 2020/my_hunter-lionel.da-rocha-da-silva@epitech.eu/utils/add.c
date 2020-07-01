/*
** EPITECH PROJECT, 2019
** add
** File description:
** add
*/

#include "my.h"

char *add(char *str1, char *str2)
{
    int carry = 0;
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    int len = len1 >= len2 ? len1 : len2;
    char *res = malloc(sizeof(char) * len + 1);

    res = add_calc(str1, str2, carry, len);
    my_revstr(res);
    return (res);
}
