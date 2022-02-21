/*
** EPITECH PROJECT, 2020
** my_screensaver
** File description:
** moving_square
*/

#include "../struct.h"

void moving_square(framebuffer_t *fb, utils_t *u)
{
    my_draw_square(fb, u->u, 100, sfBlack);
    if (u->u.x + u->m.x + 100 > WIDTH)
        u->m.x *= -1;
    if (u->u.y + u->m.y + 100 > HEIGHT)
        u->m.y *= -1;
    if (u->u.x < 8)
        u->m.x *= -1;
    if (u->u.y < 8)
        u->m.y *= -1;
    u->u.x += u->m.x;
    u->u.y += u->m.y;
    my_draw_square(fb, u->u, 100, sfBlue);
    return;
}
