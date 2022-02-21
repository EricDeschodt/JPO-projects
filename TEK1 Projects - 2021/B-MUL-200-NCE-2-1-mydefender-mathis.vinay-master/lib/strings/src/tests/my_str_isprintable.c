/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** jsp
*/

int my_char_isprintable(char c)
{
    if (32 <= c && c <= 255)
        return 1;
    return 0;
}

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_char_isprintable(str[i]))
            return 0;
    return 1;
}
