/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** my_put_pixel
*/

#include "struct.h"

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,       \
                                            unsigned int y, sfColor color)
{
    int n = ((framebuffer->width * y * 4) + (x * 4));

    framebuffer->pixels[n] = color.r;
    framebuffer->pixels[n + 1] = color.g;
    framebuffer->pixels[n + 2] = color.b;
    framebuffer->pixels[n + 3] = color.a;
    return;
}
