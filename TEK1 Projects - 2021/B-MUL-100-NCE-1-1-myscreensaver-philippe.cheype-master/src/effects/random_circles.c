/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** radiant_generator
*/

#include <stdlib.h>
#include <time.h>
#include "../struct.h"

void random_circles(framebuffer_t *fb)
{
    time_t t;
    srand(time(&t));
    sfVector2i p = {rand() % 50 * 16 - 2, rand() % 50 * 25};
    sfColor color = my_rand_color(255);
    unsigned int pos = rand() % 50 * 10;

    while (pos + p.x > WIDTH || pos + p.y > HEIGHT) {
        p.x = rand() % 50 * 16 - 2;
        p.y = rand() % 50 * 25;
        pos = rand() % 50 * 10;
    }
    my_draw_circle(fb, p, pos, color);
}
