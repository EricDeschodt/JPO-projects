/*
** EPITECH PROJECT, 2020
** init
** File description:
** sprite
*/

#include "../../include/include.h"

sfSprite *sprite_creator(char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}

void init_sprite1(s_sprite *sprite)
{
    sprite->bckg_menu = sprite_creator("assets/assets_fight/menu/bck.png");
    sprite->play_button =
    sprite_creator("assets/assets_fight/menu/play/play_n.png");
    sprite->rect_play = (sfIntRect){0, 0, 372, 151};
    sfSprite_setTextureRect(sprite->play_button, sprite->rect_play);
    sprite->vect_play = (sfVector2f){50, 800};
    sfSprite_setPosition(sprite->play_button, sprite->vect_play);
    sprite->option_button =
    sprite_creator("assets/assets_fight/menu/option/Option_n.png");
    sprite->rect_option = (sfIntRect){0, 0, 372, 151};
    sfSprite_setTextureRect(sprite->option_button, sprite->rect_option);
    sprite->vect_option = (sfVector2f){500, 800};
    sfSprite_setPosition(sprite->option_button, sprite->vect_option);
    sprite->quit_button =
    sprite_creator("assets/assets_fight/menu/quit/quit_n.png");
    sprite->rect_quit = (sfIntRect){0, 0, 372, 151};
    sfSprite_setTextureRect(sprite->quit_button, sprite->rect_quit);
    sprite->vect_quit = (sfVector2f) {1550, 800};
    sfSprite_setPosition(sprite->quit_button, sprite->vect_quit);
}

void init_sprite_6(s_sprite *sprite)
{
    sprite->sprite_volume_p =
    sprite_creator("assets/assets_fight/menu/option/plus.png");
    sprite->sprite_volume_m =
    sprite_creator("assets/assets_fight/menu/option/moin.png");
    sprite->rect_volume_p = (sfIntRect){0, 0, 81, 81};
    sprite->rect_volume_m = (sfIntRect){0, 0, 81, 81};
    sfSprite_setTextureRect(sprite->sprite_volume_p, sprite->rect_volume_p);
    sfSprite_setTextureRect(sprite->sprite_volume_m, sprite->rect_volume_m);
    sprite->vect_volume_m = (sfVector2f){1290, 555};
    sprite->vect_volume_p = (sfVector2f){590, 555};
    sfSprite_setPosition(sprite->sprite_volume_p, sprite->vect_volume_p);
    sfSprite_setPosition(sprite->sprite_volume_m, sprite->vect_volume_m);
    sprite->bck_htp =
    sprite_creator("assets/assets_fight/menu/htp/bck_htp.png");
    sprite->rect_bck_htp = (sfIntRect){0, 0, 1920, 1080};
    sfSprite_setTextureRect(sprite->bckg_menu, sprite->rect_bck_htp);
}

void init_sprite(s_sprite *sprite)
{
    init_sprite1(sprite);
    init_sprite2(sprite);
    init_sprite_3(sprite);
    init_sprite_4(sprite);
    init_sprite_5(sprite);
    init_sprite_6(sprite);
}