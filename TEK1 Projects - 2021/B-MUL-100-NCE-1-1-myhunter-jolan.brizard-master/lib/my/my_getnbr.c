/*
** EPITECH PROJECT, 2020
** my get nbr
** File description:
** get nbr
*/

#include "my.h"

t_bag *define_bag(t_bag *bag)
{
    bag->i = 0;
    bag->res = 0;
    bag->sign = 1;
    bag->max = 0;

    return (bag);
}

int my_getnbr(char const *str, t_bag *bag)
{
    bag = define_bag(bag);

    for (bag->i = 0; str[bag->i] != '\0' && (str[bag->i] < '1'
        || str[bag->i] > '9'); bag->i++) {
        if (str[bag->i] == '-')
            bag->sign *= -1;
    }
    if (str[bag->i] == '\0')
        return (0);
    while (str[bag->i] >= '0' && str[bag->i] <= '9') {
        if (bag->max > 10 || bag->res > 214748364
            || (str[bag->i] - 48 > 7 && bag->res == 214748364))
            return (0);
        bag->res = (str[bag->i] - 48) + bag->res * 10;
        bag->i++;
        bag->max++;
    }
    return (bag->sign * bag->res);
}