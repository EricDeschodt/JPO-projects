/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** Set sprites
*/

#include "../include/project.h"

void idle_animation(t_window *window)
{
    window->sprite->time_idle =
                sfClock_getElapsedTime(window->sprite->clock_idle);
    window->sprite->seconds_idle =
                window->sprite->time_idle.microseconds / 1000000.0;
    if (window->sprite->seconds_idle >= 0.09) {
        window->sprite->idle_rect =
                move_rect(window->sprite->idle_rect, 200,
                            1600, window->sprite->left);
        sfSprite_setTextureRect(window->sprite->idle,
                                window->sprite->idle_rect);
        sfRenderWindow_drawSprite(window->window, window->sprite->idle, NULL);
        sfClock_restart(window->sprite->clock_idle);
    } else
        sfRenderWindow_drawSprite(window->window, window->sprite->idle, NULL);
}

void set_sprite(t_sprite *sprite)
{
    sfVector2f character_scale = {(float) 1.7, (float) 1.7};
    sfVector2f character_pos = {200, 560};
    sprite->character_texture =
                sfTexture_createFromFile("./img/Run.png", NULL);
    sprite->character = sfSprite_create();
    sprite->idle_texture = sfTexture_createFromFile("./img/Idle.png", NULL);
    sprite->idle = sfSprite_create();
    sprite->base = character_pos;
    sfSprite_setPosition(sprite->character, character_pos);
    sfSprite_setScale(sprite->character, character_scale);
    sfSprite_setPosition(sprite->idle, character_pos);
    sfSprite_setScale(sprite->idle, character_scale);
}

t_sprite *define_sprite(t_sprite *sprite)
{
    set_sprite(sprite);
    sprite->speed = -22;
    sprite->character_rect.top = 60;
    sprite->character_rect.left = 60;
    sprite->character_rect.height = 70;
    sprite->character_rect.width = 70;
    sprite->idle_rect.top = 60;
    sprite->idle_rect.left = 60;
    sprite->idle_rect.height = 70;
    sprite->idle_rect.width = 70;
    sprite->clock = sfClock_create();
    sprite->clock_jp = sfClock_create();
    sprite->clock_idle = sfClock_create();
    sprite->offset = 0;
    sprite->max_value = 0;
    sprite->left = 60;
    sfSprite_setTexture(sprite->character, sprite->character_texture, sfFalse);
    sfSprite_setTexture(sprite->idle, sprite->idle_texture, sfFalse);
    return sprite;
}

void up_or_down(t_window *window)
{
    if (window->sprite->speed < 0) {
        window->sprite->offset = 200;
        window->sprite->max_value = 400;
        window->sprite->left = 60;
    }
    else {
        window->sprite->offset = 200;
        window->sprite->max_value = 800;
        window->sprite->left = 460;
    }
}

void ch_anim(t_window *window)
{
    if (window->jumping) {
        window->sprite->character_rect.top = 130;
        up_or_down(window);
        jump_animation(window);
        player_jump(window);
    } else {
        window->sprite->character_rect.top = 60;
        character_animation(window);
    }
}