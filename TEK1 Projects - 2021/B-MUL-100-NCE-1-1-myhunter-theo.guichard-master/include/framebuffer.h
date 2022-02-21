/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** Framebuffer header
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>
#include <stdlib.h>

#define BPP 32

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
}framebuffer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void framebuffer_destroy(framebuffer_t *framebuffer);

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, \
    sfColor color);

#endif    /* FRAMEBUFFER_H_ */


