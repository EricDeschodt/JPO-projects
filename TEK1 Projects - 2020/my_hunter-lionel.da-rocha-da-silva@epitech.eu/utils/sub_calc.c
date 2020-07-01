/*
** EPITECH PROJECT, 2019
** sub_calc
** File description:
** sub_calc
*/

#include "my.h"

char *sub_calc(char *str1, char *str2, int carry, int len)
{
    char *res = malloc(sizeof(char) * len + 1);
    res[len] = 0;
    int i;

    for (i = 0; i < len; i++) {
        char a = get_value(str1, i);
        char b = get_value(str2, i);
        int sub = a - b - carry;
        if (sub >= 0)
            carry = 0;
        if (sub < 0) {
            sub = (a + 10) - b - carry;
            carry = 1;
        }
        res[i] = sub + 48;
        if (carry == 1)
            res[i + 1] = carry + 48;
    }
    return (res);
}
