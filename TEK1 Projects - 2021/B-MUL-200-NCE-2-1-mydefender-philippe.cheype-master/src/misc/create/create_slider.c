/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** create_slider
*/

#include <stdlib.h>
#include "defender.h"

slider_t *create_slider(sfFloatRect pos_size, char *string,  \
                        sfTexture *texture, sfTexture *slider_texture)
{
    sfVector2u temp = sfTexture_getSize(slider_texture);
    sfVector2f slider_size = { (float)temp.x, (float)temp.y };
    sfVector2f pos =         { pos_size.left, pos_size.top  };
    slider_t *slider;

    slider = malloc(sizeof(slider_t));
    slider->b = create_button(pos_size, string, texture);
    slider->slider = create_rectangle(pos, slider_size, slider_texture, sfTrue);
    return (slider);
}
