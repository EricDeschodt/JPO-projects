/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** jsp
*/

int my_char_isalpha(char const c)
{
    if (65 <= c && c <= 90)
        return 1;
    if (97 <= c && c <= 122)
        return 1;
    return 0;
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_char_isalpha(str[i]))
            return 0;
    return 1;
}
