/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** jsp
*/

int my_char_isupper(char c)
{
    if ('A' <= c && c <= 'Z')
        return 1;
    return 0;
}

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_char_isupper(str[i]))
            return 0;
    return 1;
}
