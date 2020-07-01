/*
** EPITECH PROJECT, 2020
** init
** File description:
** sprite
*/

#include "../../include/include.h"

void init_sprite2_2(s_sprite *sprite)
{
    sprite->rect_option_press = (sfIntRect){0, 0, 372, 151};
    sprite->vect_option_press = (sfVector2f){500, 810};
    sfSprite_setPosition(sprite->option_button_press,
    sprite->vect_option_press);
    sfSprite_setTextureRect(sprite->option_button_press,
    sprite->rect_option_press);
    sprite->vect_play_click = (sfVector2f){50, 810};
}

void init_sprite_3_3(s_sprite *sprite)
{
    sfSprite_setTextureRect(sprite->sprite_menu_invent,
    sprite->rect_menu_invent);
    sfSprite_setTextureRect(sprite->sprite_exit_invent,
    sprite->rect_exit_invent);
    sprite->vect_menu_invt = (sfVector2f) {1210, 300};
    sprite->vect_exit_invt = (sfVector2f) {1210, 450};
}

void init_sprite_5_5(s_sprite *sprite)
{
    sfSprite_setPosition(sprite->sprite_menu_invent_p, sprite->vect_menu_invt);
    sfSprite_setPosition(sprite->sprite_exit_invent_p, sprite->vect_exit_invt);
}