/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** framebuffer_create
*/

#include <stdlib.h>
#include "struct.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(sizeof(sfUint8) * (width * height * 4));
    return (framebuffer);
}
