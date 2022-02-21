/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lib
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void my_putchar(char const c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;
    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_getnbr(char const *str, int i)
{
    int k = 0;
    int result = 0;
    int j = 1;

    if (str[i] == '-') {
        i++;
        j = -1;
    }
    for (i; str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'); i++) {
        if ((result == 214748364 && str[i] - 48 > '7')
            || result > 214748346 || k > 10)
            return (0);
        result = (str[i] - 48) + result * 10;
        k++;
    }
    return (j * result);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] == s2[i] && s1[i] != '\0') && (s2[i] != '\0')) {
        i++;
    }
    return (s1[i] - s2[i]);
}
