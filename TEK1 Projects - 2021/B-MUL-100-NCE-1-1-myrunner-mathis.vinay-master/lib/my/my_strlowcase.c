/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** lower()
*/

int is_upper_letter(char c)
{
    if ((65 <= c) && (c <= 90))
        return 1;
    else
        return 0;
}

char lower_this(char c)
{
    if (is_upper_letter(c) == 1)
        return c + 32;
    else
        return c;
}

char *my_strlowcase(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++)
        str[i] = lower_this(str[i]);
    return str;
}
