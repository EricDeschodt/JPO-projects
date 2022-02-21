/*
** EPITECH PROJECT, 2020
** My Rev Syt
** File description:
** Reverses Strings
*/

char *my_revstr(char *str)
{
    char mem;
    int i;

    for (i = 0; str[i]; i++);
    i--;
    for (int n = 0; n < i; n++, i--) {
        mem = str[n];
        str[n] = str[i];
        str[i] = mem;
    }
    return (str);
}
