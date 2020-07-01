/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** manual
*/

#include "my.h"

void manual2(void)
{
    my_putstr("  Replace empty spaces with numbers of your choice\n\n");
    my_putstr("      - 0 = low skull (points)\n");
    my_putstr("      - 1 = basic zombie (random size)\n");
    my_putstr("      - 2 = flying zombie\n");
    my_putstr("      - 3 = rotating axe1\n");
    my_putstr("      - 4 = rotating spiky ball\n");
    my_putstr("      - 5 = saw\n");
    my_putstr("      - 6 = rotating axe2\n");
    my_putstr("      - 7 = END OF MAP (only at the end of your level !)\n");
    my_putstr("      - 0 = spikes\n");
    my_putstr("      - 0 = high skill (points)\n\n");
}

void manual(void)
{
    my_putstr("\n                             MY RUNNER\n\n");
    my_putstr("  Reach the end to win, skulls multiply by 2 your score each "
                "time you pick one up, \nblue zombies need to be hit two time "
                "to die, the second hit can only be done in his upper part.\n");
    my_putstr("\n                             CONTROLS\n\n");
    my_putstr("      - Arrow down to crouch\n");
    my_putstr("      - Arrow up to jump\n");
    my_putstr("      - Arrow right to hit\n");
    my_putstr("      - Space to throw your hat\n");
    my_putstr("      - You can hit or throw your hat while jumping or "
                "crouching\n\n");
    my_putstr("                            MAP CREATOR\n\n");
    my_putstr("  You can create your map using the my_map file in the maps "
                "directory\n");
    manual2();
}