/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** init_regroup
*/

#include "my.h"

void setup(all_t *all)
{
    all->video_mode.width = 1920;
    all->video_mode.height = 1080;
    all->video_mode.bitsPerPixel = 32;
    all->window = sfRenderWindow_create(all->video_mode, "Moonwalker Runner",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(all->window, 120);
}

all_t init_regroup(all_t *all)
{
    setup(all);
    int_init(&all->my_int);
    sound_init(&all->sound);
    sprite_regroup(&all->sprite, &all->texture);
    init_pos_background(&all->background_pos);
    clock_init(&all->clock);
    init_pos(&all->pos);
    rect_init(&all->rect);
    background_regroup(all);
    all->mobs = new_list();
    write_init(all);
    return (*all);
}