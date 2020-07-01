/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"
#include <stdlib.h>

char *inf_add(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *result;
    char *res = "-";
    int len = (len1 >= len2) ? len1 : len2;
    char *new_res = malloc(sizeof(char) * len + 1);
    if (str1[0] != '-' && str2[0] != '-') {
        new_res = add(str1, str2);
    }
    else if (str1[0] == '-' && str2[0] == '-') {
        result =  add(str1 + 1, str2 + 1);
        my_strcpy(new_res, res);
        my_strcat(new_res, result);
        free(result);
    } else {
        if (str1[0] == '-')
        new_res = first_neg(str1, str2, len1, len2);
        if (str2[0] == '-')
        new_res = secnd_neg(str1, str2, len1, len2);
    }
    return (new_res);
}
