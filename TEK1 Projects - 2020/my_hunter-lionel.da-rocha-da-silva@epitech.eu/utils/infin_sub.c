/*
** EPITECH PROJECT, 2019
** infin_sub
** File description:
** infin_sub
*/

#include "my.h"
#include <stdlib.h>

char *both_neg1(char *str1, char *str2, int len1, int len2)
{
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);
    char *zero = "0";

    if (comp(str1 + 1, str2 + 1) > 0) {
        result = sub(str1 + 1, str2 + 1);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
        return (new_res);
    }
    if (comp(str1 + 1, str2 + 1) < 0) {
        new_res = sub(str2 + 1, str1 + 1);
        return (new_res);
    }
    else
        return (zero);
}

char *both_pos1(char *str1, char *str2, int len1, int len2)
{
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);
    char *zero = "0";

    if (comp(str1, str2) > 0) {
        new_res = sub(str1, str2);
        return (new_res);
    }
    if (comp(str1, str2) < 0) {
        result = sub(str2, str1);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
        return (new_res);
    } else
        return (zero);
}

char *both_pos(char *str1, char *str2, int len1, int len2)
{
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);

    if (len1 > len2)
        new_res = sub(str1, str2);
    else if (len2 > len1) {
        result = sub(str2, str1);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
    } else {
        new_res = both_pos1(str1, str2, len1, len2);
    }
    return (new_res);
}

char *both_neg(char *str1, char *str2, int len1, int len2)
{
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);

    if (len1 > len2) {
        result = sub(str1 + 1, str2 + 1);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
    }
    else if (len2 > len1) {
        new_res = sub(str2 + 1, str1 + 1);
    } else {
        new_res = both_neg1(str1, str2, len1, len2);
    }
    return (new_res);
}

char *inf_sub(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);
    if (str1[0] != '-' && str2[0] != '-')
        new_res = both_pos(str1, str2, len1, len2);
    else if (str1[0] == '-' && str2[0] == '-') {
        new_res = both_neg(str1, str2, len1, len2);
    } else {
        if (str1[0] == '-') {
            result = add(str1 + 1, str2);
            my_strcpy(new_res, res);
            my_strcat(new_res, result);
        }
        else if (str2[0] == '-')
            new_res = add(str1, str2 + 1);
    }
    return (new_res);
}
