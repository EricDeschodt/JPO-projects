/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** return a neg value, 0 or a pos value, if s1 < s2, s1 = s2 or s1 > s2
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}
