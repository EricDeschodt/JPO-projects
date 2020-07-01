/*
** EPITECH PROJECT, 2019
** secnd_neg
** File description:
** secnd_neg
*/

#include "my.h"

char *secnd_neg_a(char *str1, char *str2, int len1, int len2)
{
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);
    char *zero = "0";

    if (comp(str1, str2 + 1) < 0) {
            result = sub(str2 + 1, str1);
            my_strcpy(new_res, res);
            my_strcat(new_res, result);
            return (new_res);
    }
    if (comp(str1, str2 + 1) > 0)
        result = sub(str1, str2 + 1);
    else {
        return (zero);
    }
    return (result);
}

char *secnd_neg(char *str1, char *str2, int len1, int len2)
{
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);

    if (len1 > len2 - 1)
        result = sub(str1, str2 + 1);
    else if (len1 < len2 - 1) {
        result = sub(str2 + 1, str1);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
        return (new_res);
    } else
        result = secnd_neg_a(str1, str2, len1, len2);
    return (result);
}
