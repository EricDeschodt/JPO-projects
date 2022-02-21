/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Main for screensaver
*/

#include "include/my.h"

int main(int ac, char **av)
{
    int param = 0;

    if (error_gestion(ac, av) == 1)
        return (84);
    param = my_getnbr(av[1]);
    if (param < 1 || param > 5) {
        my_putstr("Invalid animation id\n");
        return (84);
    }
    which_anim(param);
}
