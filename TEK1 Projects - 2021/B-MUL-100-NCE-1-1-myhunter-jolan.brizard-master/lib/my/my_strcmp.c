/*
** EPITECH PROJECT, 2020
** mystring cmp
** File description:
** compare
*/

#include <stdio.h>
#include <string.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}