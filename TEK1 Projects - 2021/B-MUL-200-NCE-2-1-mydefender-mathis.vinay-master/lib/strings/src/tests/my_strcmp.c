/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** ça fait comme le vré
*/

#include <stdbool.h>

int my_strcmp_check(char const *s1, char const *s2, int i)
{
    if ((s1[i] == '\0') && (s2[i] == '\0'))
        return 0;
    if (s1[i] == '\0')
        return -1;
    if (s2[i] == '\0')
        return 1;
    if (s1[i] == s2[i])
        return my_strcmp_check(s1, s2, i + 1);
    else
        return s1[i] - s2[i];
}

int my_strcmp(char const *s1, char const *s2)
{
    return my_strcmp_check(s1, s2, 0);
}

bool my_str_is_equal(char const *s1, char const *s2)
{
    int i = 0;
    for (; s1[i] && s2[i]; i++)
        if (s1[i] != s2[i]) return false;
    if (s1[i] != s2[i]) return false;
    return true;
}