/*
** EPITECH PROJECT, 2020
** my_is_char_in_str
** File description:
** search for a char in a str
*/

#include <stdbool.h>

bool my_is_char_in_str(char c, const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return true;
    return false;
}

bool my_is_char_in_strn(char c, const char *str, int limit)
{
    for (int i = 0; i < limit && str[i]; i++)
        if (str[i] == c)
            return true;
    return false;
}