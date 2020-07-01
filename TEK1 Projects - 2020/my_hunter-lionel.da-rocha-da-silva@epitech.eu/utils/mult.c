/*
** EPITECH PROJECT, 2019
** mult.c
** File description:
** mult.c
*/

#include "my.h"

char *mult(char *str1, char *str2, char *new_res)
{
    char *zero = "0";
    char *res = "-";

    if (str1[1] == '0' && str1[2] == '\0')
        return (zero);
    if (str2[0] == '0' && str2[1] == '\0')
        return (zero);
    else {
        char *result = mul_calc(str1 + 1, str2);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
        return (new_res);
    }
}

char *mult1(char *str1, char *str2, char *new_res)
{
    char *zero = "0";
    char *res = "-";

    if (str1[0] == '0' && str1[1] == '\0')
        return (zero);
    if (str2[1] == '0' && str2[2] == '\0')
        return (zero);
    else {
        char *result = mul_calc(str1, str2 + 1);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
        return (new_res);
    }
}

char *mult2(char *str1, char *str2)
{
    char *zero = "0";

    if (str1[0] == '0' && str1[1] == '\0')
        return (zero);
    if (str2[0] == '0' && str2[1] == '\0')
        return (zero);
    else
        return (mul_calc(str1, str2));
}
