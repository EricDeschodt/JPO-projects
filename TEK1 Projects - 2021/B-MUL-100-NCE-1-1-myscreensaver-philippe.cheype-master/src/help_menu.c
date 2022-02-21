/*
** EPITECH PROJECT, 2020
** my_screensaver (Workspace)
** File description:
** help_menu
*/

#include <stdlib.h>
#include "my.h"

void help_menu(void)
{
    my_putstr("animation rendering in a CSFML window.\n");
    my_putstr("\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_screensaver [OPTIONS] animation_id\n");
    my_putstr("    animation_id   ID of the animation");
    my_putstr(" to process (between 1 and 20).\n");
    my_putstr("\n");
    my_putstr("OPTIONS\n");
    my_putstr("   -d              print the description");
    my_putstr(" f all the animations and quit.\n");
    my_putstr("   -h              print the usage and quit.\n");
    my_putstr("\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  LEFT_ARROW       switch to the previous animation.\n");
    my_putstr("  RIGHT_ARROW      switch to the next animation.\n");
}
