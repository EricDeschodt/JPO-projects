/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Task05
*/

#include "../include/my.h"

static int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int sign = 1;
    int i = 0;
    int nb = 0;
    int nb_char = 0;
    for (i; str[i] != '\0' && (str[i] <= '0' || str[i] > '9'); i++) {
        if (str[i] == '-')
            sign *= -1;
    }
    if (str[i] == '\0')
        return (0);
    for (i; is_num(str[i]) == 0; i++);
    for (i; is_num(str[i]) == 1; i++) {
        if ((nb == 214748364 && str[i] > '7') || nb_char > 10)
            return (0);
        if ((nb == 214748364 && str[i] > '7') || nb_char > 10 && sign == -1)
            return (0);
        nb = nb * 10 + (str[i] - '0');
        nb_char++;
    }
    return (nb * sign);
}
