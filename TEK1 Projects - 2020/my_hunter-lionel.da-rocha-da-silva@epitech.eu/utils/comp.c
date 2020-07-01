/*
** EPITECH PROJECT, 2019
** comp
** File description:
** comp
*/

#include "my.h"
#include <stdlib.h>

int comp(char *str1, char *str2)
{
    int i = 0;
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    while (i < len1 && i < len2) {
        if (str1[i] > str2[i])
            return (1);
        if (str1[i] < str2[i])
            return (-1);
        i++;
    }
    return (0);
}
