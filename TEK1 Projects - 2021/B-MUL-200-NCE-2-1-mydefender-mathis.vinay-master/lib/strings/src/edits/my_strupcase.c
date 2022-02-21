/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** upper en gros
*/

int is_lower_letter(char c)
{
    if ((97 <= c) && (c <= 122))
        return 1;
    else
        return 0;
}

char upper_this(char c)
{
    if (is_lower_letter(c) == 1)
        return c - 32;
    else
        return c;
}

char *my_strupcase(char *str)
{
    for (int i = 0 ; str[i] != '\0' ; i++)
        str[i] = upper_this(str[i]);
    return str;
}