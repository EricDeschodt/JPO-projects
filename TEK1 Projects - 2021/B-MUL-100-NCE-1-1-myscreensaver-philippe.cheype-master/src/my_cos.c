/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** my_cos
*/

#include "my.h"

double my_cos(double x)
{
    double res = 0;
    x *= 3.14159 / 180.0;

    for (int i = 2; i <= 8; i += 2)
        res += (my_compute_power_rec(x, i) / my_compute_factorial_rec(i));
    res -= 1.0;
    return (res);
}
