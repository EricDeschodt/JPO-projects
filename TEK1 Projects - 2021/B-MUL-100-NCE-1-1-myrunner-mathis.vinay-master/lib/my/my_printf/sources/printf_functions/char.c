/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCE-1-1-myprintf-mathis.vinay
** File description:
** printf_char
*/

#include "../../include/my.h"
#include "../../include/printf_functions.h"

int pf_char(char c, char *format)
{
    my_putchar(c);
    return 1;
}