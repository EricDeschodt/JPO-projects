/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** jsp
*/

int my_char_isnum(char c)
{
    if ('0' <= c && c <= '9')
        return 1;
    return 0;
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_char_isnum(str[i]))
            return 0;
    if (str[0])
        return 1;
    return 0;
}
