/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** jsp
*/

int my_char_islower(char c)
{
    if ('a' <= c && c <= 'z')
        return 1;
    return 0;
}

int my_str_islower(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_char_islower(str[i]))
            return 0;
    return 1;
}
