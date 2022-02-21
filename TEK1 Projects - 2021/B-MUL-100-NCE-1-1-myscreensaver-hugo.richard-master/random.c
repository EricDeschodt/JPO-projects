/*
** EPITECH PROJECT, 2020
** random.c
** File description:
** random function
*/

#include "include/my.h"

int random_x(void)
{
    int x = rand();

    while (x > 800)
        x = rand();
    return (x);
}

int random_y(void)
{
    int y = rand();

    while (y > 600)
        y = rand();
    return (y);
}

sfColor random_color(void)
{
    sfColor color = sfColor_fromRGB(rand()% 255, rand()% 255, rand()% 255);

    return (color);
}