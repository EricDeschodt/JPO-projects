/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** Reverses a string
*/

char *my_revstr(char *str)
{
    int a = 0, b = 0, len = 0, k = 0;
    char tmp;
    while (str[k] != '\0') {
        len++;
        b++;
        k++;
    }
    len--;
    b--;
    while (a <= len / 2) {
        tmp = str[b];
        str[b] = str[a];
        str[a] = tmp;
        a++;
        b--;
    }
    return (str);
}
