/*
** EPITECH PROJECT, 2021
** myDefender
** File description:
** framebuffer_create
*/

#include <stdlib.h>
#include "defender.h"

framebuffer_t *framebuffer_create(void)
{
    framebuffer_t *fb;

    fb = malloc(sizeof(framebuffer_t));
    if (!fb) return (NULL);
    fb->width = WIDTH;
    fb->height = HEIGHT;
    fb->pixels = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    if (!fb->pixels) {
        free(fb);
        return (NULL);
    }
    return (fb);
}
