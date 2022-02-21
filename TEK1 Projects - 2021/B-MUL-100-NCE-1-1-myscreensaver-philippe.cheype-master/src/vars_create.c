/*
** EPITECH PROJECT, 2020
** my_screensaver (Workspace)
** File description:
** vars_create
*/

#include <stdlib.h>
#include "struct.h"

vars_t *vars_create(framebuffer_t *fb, unsigned int pixels)
{
    vars_t *va = malloc(sizeof(vars_t));

    va->mode.width = fb->width;
    va->mode.height = fb->height;
    va->mode.bitsPerPixel = pixels;
    va->window = sfRenderWindow_create(va->mode, "window", sfClose, NULL);
    va->texture = sfTexture_create(fb->width, fb->height);
    va->sprite = sfSprite_create();
    return (va);
}
