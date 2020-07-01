/*
** EPITECH PROJECT, 2019
** sub
** File description:
** sub
*/

#include <stdlib.h>
#include "my.h"

char *sub(char *str1, char *str2)
{
    int carry = 0;
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int len = len1 >= len2 ? len1 : len2;
    char *res = malloc(sizeof(char) * len + 1);
    res[len] = 0;
    res = sub_calc(str1, str2, carry, len);

    my_revstr(res);
    char *tmp = res;

    if (tmp[0] == '0') {
        while (tmp[0] == '0') {
            tmp++;
        }
    }
    return (tmp);
}
