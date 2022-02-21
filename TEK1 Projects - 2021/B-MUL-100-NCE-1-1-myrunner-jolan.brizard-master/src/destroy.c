/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** Destroys and cleans sprite
*/

#include "../include/project.h"

void destroy_px(t_parallax *px)
{
    sfTexture_destroy(px->layer01_texture);
    sfTexture_destroy(px->layer02_texture);
    sfTexture_destroy(px->layer03_texture);
    sfTexture_destroy(px->layer04_texture);
    sfTexture_destroy(px->layer05_texture);
    sfTexture_destroy(px->layer06_texture);
    sfTexture_destroy(px->layer07_texture);
    sfTexture_destroy(px->layer08_texture);
    sfTexture_destroy(px->layer09_texture);
    sfSprite_destroy(px->layer01);
    sfSprite_destroy(px->layer02);
    sfSprite_destroy(px->layer03);
    sfSprite_destroy(px->layer04);
    sfSprite_destroy(px->layer05);
    sfSprite_destroy(px->layer06);
    sfSprite_destroy(px->layer07);
    sfSprite_destroy(px->layer08);
    sfSprite_destroy(px->layer09);
    sfClock_destroy(px->clock);
}

void destroy_player(t_sprite *sprite)
{
    sfTexture_destroy(sprite->character_texture);
    sfSprite_destroy(sprite->character);
    sfClock_destroy(sprite->clock);
    sfClock_destroy(sprite->clock_jp);
    sfTexture_destroy(sprite->idle_texture);
    sfSprite_destroy(sprite->idle);
    sfClock_destroy(sprite->clock_idle);
}

void destroy_text(t_text *text)
{
    sfText_destroy(text->title_text);
    sfText_destroy(text->enter_text);
    sfText_destroy(text->win_text);
    sfText_destroy(text->lose_text);
    sfText_destroy(text->score);
    sfFont_destroy(text->font);
}

void destroy_window(t_window *window)
{
    sfRenderWindow_destroy(window->window);
    sfSoundBuffer_destroy(window->sound_buf);
    sfSound_destroy(window->sound);
    sfSoundBuffer_destroy(window->death_buf);
    sfSound_destroy(window->death_sound);
    sfClock_destroy(window->clock);
}

void destroy_all(t_window *window)
{
    destroy_px(window->px);
    destroy_player(window->sprite);
    destroy_text(window->text);
    destroy_window(window);
    sfTexture_destroy(window->map->obs_texture);
    sfSprite_destroy(window->map->obs);
    sfClock_destroy(window->map->clock);
    sfClock_destroy(window->map->clock_obs);
}