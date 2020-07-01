/*
** EPITECH PROJECT, 2020
** int_to_char
** File description:
** int
*/

#include "../../include/include.h"
#include <stdlib.h>
#include <unistd.h>

char *str_add(char *str1, char *str2, char *str3)
{
    int l_str1 = 0, l_str2 = 0, l_str3 = 0;

    for (; str1[l_str1] != '\0'; l_str1++);
    for (; str2[l_str2] != '\0'; l_str2++);
    for (; str2[l_str3] != '\0'; l_str3++);
    char *rsl = malloc(sizeof(char) * (l_str1 + l_str2 + l_str3 + 1));
    for (l_str1 = 0; str1[l_str1] != '\0'; l_str1++)
        rsl[l_str1] = str1[l_str1];
    for (l_str2 = 0; str2[l_str2] != '\0'; l_str2++)
        rsl[l_str2 + l_str1] = str2[l_str2];
    for (l_str3 = 0; str3[l_str3] != '\0'; l_str3++)
        rsl[l_str3 + l_str2 + l_str1] = str3[l_str3];
    rsl[l_str1 + l_str2 + l_str3] = '\0';
    return (rsl);
}

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str) - 1;
    int c;

    while (a < b) {
        c = str[a];
        str[a] = str[b];
        str[b] = c;
        a++;
        b--;
    }
    return (str);
}

char *int_to_char(int nb)
{
    char *rsl;
    int neg = 0, i = 0, o = 0;
    int tmp = nb;
    if (nb < 0) {
        nb = nb * -1;
        o = 1;
        neg = 1;
    }
    for (; tmp > 0; o++)
        tmp = tmp / 10;
    rsl = malloc(sizeof(char) * (o + 1));
    for (; nb > 9; i++) {
        rsl[i] = (nb % 10) + '0';
        nb = nb / 10;
    }
    rsl[i] = nb + '0';
    (neg == 1) ? rsl[i + 1] = '-' : 0;
    rsl[i + 1 + neg] = '\0';
    return (my_revstr(rsl));
}