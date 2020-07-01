/*
** EPITECH PROJECT, 2019
** add_calc
** File description:
** add_calc
*/

#include "my.h"

char *add_calc(char *str1, char *str2, int carry, int len)
{
    char *res = malloc(sizeof(char) * len + 1);

    for (int i = 0; i < len; i++) {
        char a = get_value(str1, i);
        char b = get_value(str2, i);
        int add = a + b + carry;
        if (add < 10)
            carry = 0;
        if (add > 9) {
            carry = 1;
            add = add - 10;
        }
        res[i] = add + 48;
        res[i + 1] = '\0';
        if (carry == 1) {
            res[i + 1] = carry + 48;
            res[i + 2] = '\0';
        }
    }
    return (res);
}
