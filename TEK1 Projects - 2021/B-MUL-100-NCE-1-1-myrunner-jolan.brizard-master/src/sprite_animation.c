/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** sprite function
*/

#include "../include/project.h"

void character_animation(t_window *window)
{
    window->sprite->time = sfClock_getElapsedTime(window->sprite->clock);
    window->sprite->seconds = window->sprite->time.microseconds / 1000000.0;
    if (window->sprite->seconds >= 0.08) {
        window->sprite->character_rect =
                move_rect(window->sprite->character_rect, 200,
                            1600, window->sprite->left);
        sfSprite_setTextureRect(window->sprite->character,
                                window->sprite->character_rect);
        draw_character(window);
        sfClock_restart(window->sprite->clock);
    } else
        draw_character(window);
}

sfIntRect move_rect(sfIntRect rect, int offset, int max_value, int left)
{
    if (rect.left >= max_value - offset)
        rect.left = left;
    else
        rect.left += offset;
    return rect;
}

void on_base(t_window *window)
{
    sfVector2f position = sfSprite_getPosition(window->sprite->character);
    if (position.y == window->sprite->base.y) {
        window->jumping = false;
        window->sprite->speed = -22;
    }
}

void jump_animation(t_window *window)
{
    window->time = sfClock_getElapsedTime(window->clock);
    window->seconds = window->time.microseconds / 1000000.0;
    if (window->seconds >= 0.09) {
        window->sprite->character_rect =
                move_rect(window->sprite->character_rect,
                            window->sprite->offset,
                            window->sprite->max_value,
                            window->sprite->left);
        sfSprite_setTextureRect(window->sprite->character,
                                window->sprite->character_rect);
        draw_character(window);
        sfClock_restart(window->clock);
    } else
        draw_character(window);
}

void player_jump(t_window *window)
{
    window->sprite->time_jp = sfClock_getElapsedTime(window->sprite->clock_jp);
    window->sprite->seconds_jp =
            window->sprite->time_jp.microseconds / 1000000.0;
    if (window->sprite->seconds_jp >= 0.016667) {
        sfVector2f jump = {0, window->sprite->speed};
        sfSprite_move(window->sprite->character, jump);
        window->sprite->speed++;
        draw_character(window);
        on_base(window);
        sfClock_restart(window->sprite->clock_jp);
    } else {
        draw_character(window);
    }
}