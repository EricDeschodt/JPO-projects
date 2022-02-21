/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myhunter-jolan.brizard
** File description:
** Animate and move the sprites
*/

#include "my_hunter.h"

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
    if (rect.left >= max_value - offset)
        rect.left = 0;
    else
        rect.left += offset;
    return rect;
}

void sprites_coord(t_sprite *sprite)
{
    float y_pos = rand() % 300 + 60;
    sprite->speed = rand() % 15 + 5;
    sfVector2f crow_scale = {0.32, 0.32};
    sfVector2f crow_pos = {-100, y_pos};
    sfSprite_setPosition(sprite->crow, crow_pos);
    sfSprite_setScale(sprite->crow, crow_scale);
    sfVector2f heart_pos = {50, 900};
    sfVector2f heart_scale = {0.6, 0.6};
    sfSprite_setScale(sprite->heart, heart_scale);
    sfSprite_setPosition(sprite->heart, heart_pos);
}

void crow_animation(t_window *windw, t_sprite *sprite)
{
    windw->time = sfClock_getElapsedTime(windw->clock);
    windw->seconds = windw->time.microseconds / 1000000.0;
    if (windw->seconds >= 0.015) {
        sfVector2f move = {sprite->speed, 0};
        sfSprite_move(sprite->crow, move);
    }
    if (windw->seconds >= 0.110) {
        sprite->crow_rect = move_rect(sprite->crow_rect, 1600/4, 1600);
        sfSprite_setTextureRect(sprite->crow, sprite->crow_rect);
        sfRenderWindow_drawSprite(windw->window, sprite->crow, NULL);
        sfClock_restart(windw->clock);
    } else
        draw_crow(windw, sprite);
}