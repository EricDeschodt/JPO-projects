/*
** EPITECH PROJECT, 2020
** my putstr
** File description:
** print every caracter in a char using my put char
*/

#include "print.h"

unsigned long long convert_octal(unsigned long long nb)
{
    unsigned long long ret = 0;
    unsigned long long oct = 0;
    unsigned long long dec = 1;

    while (nb) {
        ret = nb % 8;
        oct += ret * dec;
        nb /= 8;
        dec *= 10;
    }
    return oct;
}

void my_put_octal(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 32 || str[i] >= 127) {
            my_putchar('\\');
            if (convert_octal(str[i]) < 10 && convert_octal(str[i]) > 0)
                my_putstr("00");
            else if (convert_octal(str[i]) < 100 && convert_octal(str[i]) >= 0)
                my_putchar('0');
            my_put_nbr((int)convert_octal(str[i]));
            i++;
        }
        my_putchar(str[i]);
    }
}

void my_put_unsigned_octal(unsigned nb)
{
    my_put_ll_unsigned_nbr(convert_octal(nb));
}