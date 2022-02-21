/*
** EPITECH PROJECT, 2020
** Project Name
** File description:
** [file description here]
*/

#include "../include/myhunter.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer;

    framebuffer = malloc(sizeof(framebuffer_t));
    if (!framebuffer)
        return (NULL);
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(sizeof(sfUint8) * ((width * height * BPP)\
        / 8));
    if (!framebuffer->pixels)
        return (NULL);
    return (framebuffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    if (framebuffer) {
        free(framebuffer->pixels);
        free(framebuffer);
    }
    return;
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, \
    sfColor color)
{
    framebuffer->pixels[(y * framebuffer->width + x) * 4] = color.r;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 1] = color.g;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 2] = color.b;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 3] = color.a;
    return;
}