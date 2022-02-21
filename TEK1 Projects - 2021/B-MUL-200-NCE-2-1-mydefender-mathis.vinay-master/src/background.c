/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Handles the background
*/

#include "../include/background.h"

back_ground_t *background_create(void)
{
    back_ground_t *background = malloc(sizeof(back_ground_t));
    background->background = sprite_create("assets/gui/background.png", "",
    true, false);
    sprite_set_pos(background->background, 0, 0, (float) 1.8);
    sfIntRect rect = {0, 0, 1920, 1080};
    sfSprite_setTextureRect(background->background->sprite, rect);
    background->background_planes = sprite_create(
    "assets/gui/background_planes.png", "", true, false);
    sprite_set_pos(background->background_planes, 0, 0, (float) 1.8);
    sfIntRect rect_planes = {0, 0, 1920, 1080};
    sfSprite_setTextureRect(background->background_planes->sprite, rect_planes);
    background->time = time_create();
    background->perso = sprite_create("assets/gui/char.png", "SE", true, false);
    sprite_set_texturerect_size(background->perso, 116, 67);
    sprite_set_origin(background->perso, "SE");
    sprite_set_pos(background->perso, 2100, 1026, 5);
    return background;
}

void background_animate(back_ground_t *b, int mode)
{
    time_update(b->time, 1.0);
    while (b->time->counter >= 16666) {
        b->time->counter -= 16666;
        sprite_add_texturerect_pos(b->background, -1, 2);
        sprite_add_texturerect_pos(b->background_planes, 4, -5);
    }
    while (b->time->counter_2 >= 150000) {
        sfIntRect pos = sfSprite_getTextureRect(b->perso->sprite);
        b->time->counter_2 -= 150000;
        if (mode != 4 || pos.left < 650) pos.left += 116;
        if (mode == 0) {
            pos.top = 0;
            if (pos.left > 550)
                pos.left = 0;
        } if (mode == 4)
            pos.top = 134;
        if (mode == 1 || mode == 5 || mode == 6 || mode == 7)
            pos.top = 67;
        sfSprite_setTextureRect(b->perso->sprite, pos);
    }
}

void background_display(back_ground_t *back, sfRenderWindow *win)
{
    sprite_display(back->background, win);
    sprite_display(back->background_planes, win);
    sprite_display(back->perso, win);
}

void background_destroy(back_ground_t *back)
{
    sprite_destroy(back->background);
    sprite_destroy(back->background_planes);
    sprite_destroy(back->perso);
    time_destroy(back->time);
    free(back);
}