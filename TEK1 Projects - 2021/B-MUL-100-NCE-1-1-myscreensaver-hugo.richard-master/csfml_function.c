/*
** EPITECH PROJECT, 2020
** csfml_function.c
** File description:
** csfml fonction
*/

#include "include/my.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));
    if (framebuffer == NULL)
        return (NULL);
    framebuffer->height = height;
    framebuffer->width = width;
    framebuffer->pixels = malloc(sizeof(sfUint8) * (32 * width * height / 8));
    if (framebuffer->pixels == NULL)
        return (NULL);
    return (framebuffer);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,
unsigned int y, sfColor color)
{
    framebuffer->pixels[(y * framebuffer->width + x) * 4] = color.r;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 1] = color.g;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 2] = color.b;
    framebuffer->pixels[(y * framebuffer->width + x) * 4 + 3] = color.a;
}

void my_draw_square(framebuffer_t *buffer, sfVector2u position,
unsigned int size, sfColor color)
{
    for (unsigned int i = position.x; i != position.x + size; i++)
        for (unsigned int j = position.y; j != position.y + size; j++)
            my_put_pixel(buffer, i, j, color);
}