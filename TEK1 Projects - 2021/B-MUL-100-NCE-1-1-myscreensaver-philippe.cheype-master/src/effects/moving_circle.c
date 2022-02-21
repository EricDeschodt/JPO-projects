/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** moving_circle
*/

#include "../struct.h"

void moving_circle(framebuffer_t *fb, utils_t *u)
{
    my_draw_circle(fb, u->p, 75, my_rand_color(150));
    my_draw_circle(fb, u->p, 69, my_rand_color(0));
    if (u->p.x + u->m.x + 75 > WIDTH)
        u->m.x *= -1;
    if (u->p.y + u->m.y + 75  > HEIGHT)
        u->m.y *= -1;
    if (u->p.x + u->m.x - 75 < 0)
        u->m.x *= -1;
    if (u->p.y + u->m.y - 75 < 0)
        u->m.y *= -1;
    u->p.x += u->m.x;
    u->p.y += u->m.y;
    my_draw_circle(fb, u->p, 75, sfWhite);
    my_draw_circle(fb, u->p, 50, my_rand_color(70));
    my_draw_circle(fb, u->p, 25, sfWhite);
    return;
}
