/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** bad_params
*/

#include <stdlib.h>
#include "struct.h"
#include "my.h"

void bad_params(int args)
{
    my_putstr("./my_screensaver: bad arguments: ");
    my_putnbr(args - 1);
    my_putstr(" given but 1 is required\nretry with -h\n");
}
