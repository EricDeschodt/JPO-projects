/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** reverse the str that's all folks
*/

int my_str_len(char const *str)
{
    int i;
    i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_revstr(char *str)
{
    char a;

    int i = 0;
    while (i < my_str_len(str) / 2) {
        a = str[i];
        str[i] = str[my_str_len(str) - 1 - i];
        str[my_str_len(str) - 1 - i] = a;
        i++;
    }
    return str;
}
