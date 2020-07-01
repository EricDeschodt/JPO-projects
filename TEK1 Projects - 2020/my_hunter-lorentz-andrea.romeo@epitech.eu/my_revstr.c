/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** Reverses a string
*/

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    char tmp;
    int len = 0;
    int k = 0;
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
