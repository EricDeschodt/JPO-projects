/*
** EPITECH PROJECT, 2021
** myDefender
** File description:
** radar_end
*/

#include <stdlib.h>
#include "defender.h"

void screen_end(framebuffer_t *fb, vars_t *va)
{
    if (va->sprite) sfSprite_destroy(va->sprite);
    if (va->texture) sfTexture_destroy(va->texture);
    if (va->window) sfRenderWindow_destroy(va->window);
    if (fb->pixels) free(fb->pixels);
    if (fb) free(fb);
    if (va) free(va);
}
