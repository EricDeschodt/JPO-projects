/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** main code for the sokoban project
*/

#include "../include/libs.h"
#include "../include/elements.h"

int main(int argc, char **argv)
{
    if (flag_help(argc, argv,
                    "USAGE\n\t./my_defender [flags]\nFLAGS\n\t--help,"
    " -h : display this menu\nDESCRIPTION\n\tYou're protecting a tower from "
    "the enemies' attacks! Place turrets on strategic places, using your "
    "mouse, and upgrade them to defeat the enemies!")) return 0;
    element_t *e = elements_create();
    while (sfRenderWindow_isOpen(e->win)) {
        element_events_handling(e);
        elements_animate(e);
        elements_display(e);
    }
    elements_destroy(e);
    return 0;
}