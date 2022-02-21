/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    for(; str[i] != '\0'; i++);
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0'; i++);
    return (s1[i] - s2[i]);
}

int print_usage(void)
{
    write(1, "animation rendering in a CSFML window.\n\n", 40);
    write(1, "USAGE\n", 6);
    write(1, " ./my_screensaver\t[OPTIONS] animation_id\n", 41);
    write(1, " animation_id\t\tID of the animation to process", 45);
    write(1, " (between 1 and 5).\n\nOPTIONS\n", 29);
    write(1, " -d\t\t\tprint the description of all the animations", 49);
    write(1, " and quit.\n -h\t\t\tprint the usage and quit.\n\n", 44);
    write(1, "USER INTERACTIONS\n LEFT_ARROW\t\tswitch to the", 44);
    write(1, " previous animation.\n RIGHT_ARROW\t\tswitch to", 44);
    write(1, " the next animation.\n", 21);
    write(1, " SCREEN 4:\n\tUP/DOWN_ARROW\tchanges wind.\n", 42);
    write(1, "\tLSHIFT\t\tsummon lightning (flash alert)!\n", 41);
    write(1, " SCREEN 5:\n\tUP/DOWN_ARROW\tincrease/decrease", 43);
    write(1, " angular factor.\n", 17);
    return (0);
}

int print_index(void)
{
    write(1, "1: pulsing circles.\n", 20);
    write(1, "2: trigonometric movement and reflections.\n", 43);
    write(1, "3: color-changing rotating crosses with shadow effect.\n", 55);
    write(1, "4: a stormy night (risk of lightning) [INTERACTIVE].\n", 53);
    write(1, "5: rosette with variable k factor [INTERACTIVE].\n", 49);
    return (0);
}

int main(int ac, char* av[])
{
    if (ac != 2)
        return(84);
    if (my_strcmp(av[1], "-h") == 0)
        return (print_usage());
    if (my_strcmp(av[1], "-d") == 0)
        return (print_index());
    if (my_strlen(av[1]) == 1)
        if (av[1][0] < 54 && av[1][0] > 48) {
            screensavers(av[1][0]);
            return (0);
        }
    return (84);
}
