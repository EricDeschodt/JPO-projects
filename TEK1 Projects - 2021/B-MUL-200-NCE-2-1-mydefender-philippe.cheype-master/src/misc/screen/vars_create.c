/*
** EPITECH PROJECT, 2021
** myDefender
** File description:
** vars_create
*/

#include <stdlib.h>
#include "defender.h"

vars_t *vars_create(framebuffer_t *fb)
{
    vars_t *va;

    va = malloc(sizeof(*va));
    if (!va) return (NULL);
    va->mode.width = fb->width;
    va->mode.height = fb->height;
    va->mode.bitsPerPixel = PIXELS;
    va->window = sfRenderWindow_create(va->mode, "My Defender", sfClose, NULL);
    va->texture = sfTexture_create(fb->width, fb->height);
    va->sprite = sfSprite_create();
    return (va);
}
