

/*
** EPITECH PROJECT, 2020
** draw.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    framebuffer->pixels[(y*framebuffer->width+x) * 4] = color.r;
    framebuffer->pixels[(y*framebuffer->width+x) * 4+1] = color.g;
    framebuffer->pixels[(y*framebuffer->width+x) * 4+2] = color.b;
    framebuffer->pixels[(y*framebuffer->width+x) * 4+3] = color.a;
}
