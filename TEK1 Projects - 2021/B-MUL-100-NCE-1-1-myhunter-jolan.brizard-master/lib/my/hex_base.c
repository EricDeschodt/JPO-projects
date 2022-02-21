/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-jolan.brizard
** File description:
** Putstr en hexadecimal
*/

#include "print.h"

char *convert_hex(void *ptr, char *str)
{
    unsigned long long nb = (long long)ptr;
    int i = 0;
    char rem;

    while (nb) {
        rem = nb % 16;
        if (rem > 9) {
            str[i] = rem + 87;
        } else if (rem <= 9) {
            str[i] = rem + 48;
        }
        nb /= 16;
        i++;
    }
    str[i] = '\0';
    return (my_revstr(str));
}

void my_show_ptr(void *ptr)
{
    char *save = malloc(64);
    my_putstr(my_strcat("0x", convert_hex(ptr, save)));
    free(save);
}

void my_put_hexa_cap(void *ptr)
{
    char *save = malloc(64);
    my_putstr(my_strupcase(convert_hex(ptr, save)));
    free(save);
}

void my_put_hexa_low(void *ptr)
{
    char *save = malloc(64);
    my_putstr(convert_hex(ptr, save));
    free(save);
}