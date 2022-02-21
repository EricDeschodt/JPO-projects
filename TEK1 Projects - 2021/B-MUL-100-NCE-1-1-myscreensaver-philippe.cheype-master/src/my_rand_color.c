/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** my_rand_color
*/

#include <stdlib.h>
#include <time.h>
#include "struct.h"

sfColor my_rand_color(int alpha)
{
    if (alpha >= 0 && alpha <= 255) {
        sfColor color = {rand() % 50 * 5, rand() % 50 * 5,      \
                        rand() % 50 * 5, alpha};
        return (color);
    } else {
        sfColor color = {rand() % 50 * 5, rand() % 50 * 5,      \
                rand() % 50 * 5, rand() % 50 * 5};
        return (color);
    }
}
