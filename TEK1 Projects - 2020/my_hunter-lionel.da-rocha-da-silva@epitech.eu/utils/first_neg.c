/*
** EPITECH PROJECT, 2019
** first_neg
** File description:
** first_neg
*/

#include "my.h"

char *first_neg_a(char *str1, char *str2, int len1, int len2)
{
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);
    char *zero = "0";

    if (comp(str1 + 1, str2) > 0) {
        result = sub(str1 + 1, str2);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
        return (new_res);
    }
    else if (comp(str1 + 1, str2) < 0)
        result = sub(str2, str1 + 1);
    else {
        return (zero);
    }
    return (result);
}

char *first_neg(char *str1, char *str2, int len1, int len2)
{
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);

    if (len1 - 1 > len2) {
        result = sub(str1 + 1, str2);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
        return (new_res);
    }
    else if (len1 - 1 < len2)
        result = sub(str2, str1 + 1);
    else
        result = first_neg_a(str1, str2, len1, len2);
    return (result);
}
