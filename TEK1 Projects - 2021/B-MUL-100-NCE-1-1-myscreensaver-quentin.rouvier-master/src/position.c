/*
** EPITECH PROJECT, 2020
** position.c
** File description:
** screensavers
*/

#include "../include/framebuffer.h"

sfVector2i random_pos(void)
{
    sfVector2i pos;
    long int r = rand();
    long int k = rand();

    pos.x = 201 + r % 1619;
    pos.y = 201 + k % 679;
    return (pos);
}

int get_limit(sfVector2i center)
{
    int k = center.x;
    int n = center.y;

    if (k > 960)
        k = 1920 - k;
    if (n > 540)
        n = 1080 - n;
    if (k < n)
        return (k);
    else
        return (n);
}

sfVector2i *get_pos(float i)
{
    sfVector2i *pos = malloc(sizeof(sfVector2i) * 4);
    int n = 1;

    for (int k = 0; k < 4; k = k + 2) {
        pos[k].x = 960 + 860 * cos(i);
        pos[k].y = 510 + 400 * sin(i * i * i) * n;
        n = n * -1;
    }
    for (int k = 1; k < 4; k = k + 2) {
        pos[k].x = 960 - 860 * cos(i);
        pos[k].y = 510 - 400 * sin(i * i * i) * n;
        n = n * -1;
    }
    return (pos);
}

void my_move_rosace(framebuffer_t *framebuffer, int a, int k, sfColor color)
{
    sfVector2i pos1;
    sfVector2i pos2;

    pos1.x = 960 + 195 * cos(a*M_PI/180);
    pos1.y = 510 + 195 * sin(a*M_PI/180);
    pos2.x = pos1.x - 195 * cos(k * a * M_PI / 180);
    pos2.y = pos1.y - 195 * sin(k * a * M_PI / 180);
    my_draw_circle(framebuffer, pos2, 10, color);
}
