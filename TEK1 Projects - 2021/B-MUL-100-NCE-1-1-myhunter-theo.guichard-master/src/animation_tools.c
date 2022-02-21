/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** useful fonction for animation
*/

#include "../include/myhunter.h"

int move_dog_rect(sfIntRect *rect, int offset, int max_value, int step)
{
    if ((rect->left += offset) > max_value - offset)
        rect->left = 0;
    step++;
    return (step);
}

void move_dog_sprite(sfVector2f *pos, int step)
{
    if ((step % 4) > 0)
        pos->x += 9.375;
    else
        pos->x -= 3.125;
}

void move_duck_rect(sfIntRect *rect, int offset, int max_value)
{
    if ((rect->left += offset) > max_value - offset)
        rect->left = 0;
}

void move_duck_sprite(sfVector2f *pos, char way, float speed)
{
    switch (way) {
        case 'r':
            pos->x += 3.125 * speed;
            break;
        case 'l':
            pos->x -= 3.125 * speed;
            break;
        case 'd':
            pos->y += 3.125 * speed;
            break;
        case 'u':
            pos->y -= 3.125 * speed;
            break;
    }
    return;
}