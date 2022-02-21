/*
** EPITECH PROJECT, 2020
** Get Str
** File description:
** My get str from int
*/

#include <stdlib.h>

char *my_get_str(int nb)
{
    int j = 0, i = nb, n = 1;

    for (i = 1; i > 0; i /= n) {
        i = nb;
        if (i == nb)
            n *= 10;
    }
    n /= 10;
    for (int m = n; m > 0; j++, m /= 10);
    char *str = malloc(sizeof(char) * (j + 1));
    for (j = 0; n > 0; j++, n /= 10)
        str[j] = nb / n % 10 + 48;
    str[j] = '\0';
    return (str);
}
