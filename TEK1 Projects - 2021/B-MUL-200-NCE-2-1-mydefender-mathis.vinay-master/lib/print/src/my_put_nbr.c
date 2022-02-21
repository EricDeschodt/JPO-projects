/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print the given number
*/

#include <stdbool.h>

void my_putchar(char c);

int put_digit(int div, int *n, bool printed)
{
    if ((*n / div < 0) || printed) {
        printed = true;
        my_putchar((char)(-(*n / div) + 48));
        *n = *n % div;
    }
    return printed;
}

int my_put_nbr(int n)
{
    int div = 1000000000;
    bool printed = false;
    if (n > 0)
        n = - n;
    else if (n == 0)
        my_putchar('0');
    else
        my_putchar('-');
    while (div != 0) {
        printed = put_digit(div, &n, printed);
        div = (div != 1) ? div / 10 : 0;
    }
    return 0;
}