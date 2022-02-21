/*
** EPITECH PROJECT, 2020
** my_screensaver (Workspace)
** File description:
** effect_index
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "errors.h"
#include "struct.h"
#include "my.h"

void random_squares(framebuffer_t *fb);

void random_circles(framebuffer_t *fb);

void moving_circle(framebuffer_t *fb, utils_t *c);

void moving_square(framebuffer_t *fb, utils_t *u);

void effect_index(framebuffer_t *fb, char *effect, vars_t *va, utils_t *u)
{
    (my_strcmp(effect, "1") == 0) ? (random_squares(fb)) :      \
    (my_strcmp(effect, "2") == 0) ? (random_circles(fb)) :      \
    (my_strcmp(effect, "3") == 0) ? (moving_circle(fb, u)) :    \
    (my_strcmp(effect, "4") == 0) ? (moving_square(fb, u)) :    \
    (BAD_EFFECT, sfRenderWindow_close(va->window));
    return;
}
