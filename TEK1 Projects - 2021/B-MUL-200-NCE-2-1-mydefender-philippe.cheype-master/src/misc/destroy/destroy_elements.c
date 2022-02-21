/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** destroy_elements
*/

#include <stdlib.h>
#include "defender.h"

void destroy_slider(slider_t *slider)
{
    if (slider->slider) sfRectangleShape_destroy(slider->slider);
    if (slider->b) free(slider->b);
    if (slider) free(slider);
}

void destroy_menu(menu_t *mn)
{
    if (mn->music) sfMusic_destroy(mn->music);
    if (mn->pos) free(mn->pos);
    if (mn->pos_onclick) free(mn->pos_onclick);
    if (mn->button) free(mn->button);
    if (mn->slide) destroy_slider(mn->slide);
    if (mn) free(mn);
}
