/*
** EPITECH PROJECT, 2020
** init
** File description:
** sprite
*/

#include "../../include/include.h"

void init_sprite2(s_sprite *sprite)
{
    sprite->play_pressed =
    sprite_creator("assets/assets_fight/menu/play/play_p.png");
    sfSprite_setTextureRect(sprite->play_pressed, sprite->rect_play);
    sfSprite_setPosition(sprite->play_pressed, sprite->vect_play);
    sprite->quit_button_pressed =
    sprite_creator("assets/assets_fight/menu/quit/quit_p.png");
    sprite->rect_quit_press = (sfIntRect){0, 0, 372, 151};
    sprite->vect_quit_press = (sfVector2f) {1550, 810};
    sfSprite_setTextureRect(sprite->quit_button_pressed,
    sprite->rect_quit_press);
    sfSprite_setPosition(sprite->quit_button_pressed, sprite->vect_quit_press);
    sprite->option_button_press =
    sprite_creator("assets/assets_fight/menu/option/Option_p.png");
    sprite->how_tp_click =
    sprite_creator("assets/assets_fight/menu/htp/htp_p.png");
    sprite->rect_htp_click = (sfIntRect){0, 0, 372, 151};
    sprite->vect_htp_click = (sfVector2f){1000, 810};
    sfSprite_setTextureRect(sprite->how_tp_click, sprite->rect_htp_click);
    sfSprite_setPosition(sprite->how_tp_click, sprite->vect_htp_click);
    init_sprite2_2(sprite);
}

void init_sprite_3(s_sprite *sprite)
{
    sfSprite_setPosition(sprite->play_pressed, sprite->vect_play_click);
    sfSprite_setTextureRect(sprite->option_button_press,
    sprite->rect_option_press);
    sprite->how_tp = sprite_creator("assets/assets_fight/menu/htp/htp.png");
    sprite->rect_htp = (sfIntRect){0, 0, 372, 151};
    sprite->vect_htp = (sfVector2f){1000, 800};
    sfSprite_setTextureRect(sprite->how_tp, sprite->rect_htp);
    sfSprite_setPosition(sprite->how_tp, sprite->vect_htp);
    sprite->sprite_inventaire =
    sprite_creator("assets/inventaire/inventaire.png");
    sprite->rect_inventaire = (sfIntRect){0, 0, 1920, 1080};
    sfSprite_setTextureRect(sprite->sprite_inventaire,
    sprite->rect_inventaire);
    sprite->sprite_menu_invent =
    sprite_creator("assets/inventaire/invent_menu.png");
    sprite->sprite_exit_invent =
    sprite_creator("assets/inventaire/exit_menu.png");
    sprite->rect_menu_invent = (sfIntRect){0, 0, 264, 97};
    sprite->rect_exit_invent = (sfIntRect){0, 0, 264, 97};
    init_sprite_3_3(sprite);
}

void init_sprite_4(s_sprite *sprite)
{
    sfSprite_setPosition(sprite->sprite_menu_invent, sprite->vect_menu_invt);
    sfSprite_setPosition(sprite->sprite_exit_invent, sprite->vect_exit_invt);
    sprite->sprite_musique =
    sprite_creator("assets/assets_fight/menu/option/VOLUME.png");
    sprite->rect_musique = (sfIntRect){0, 0, 300, 82};
    sfSprite_setTextureRect(sprite->sprite_musique, sprite->rect_musique);
    sprite->sprite_bck_option =
    sprite_creator("assets/assets_fight/menu/bck_option.png");
    sprite->rect_bck_option = (sfIntRect){0, 0, 1920, 1080};
    sfSprite_setTextureRect(sprite->sprite_bck_option, sprite->rect_bck_option);
    sprite->vect_musique = (sfVector2f){790, 540};
    sfSprite_setPosition(sprite->sprite_musique, sprite->vect_musique);
    sprite->sprite_menu_opt =
    sprite_creator("assets/inventaire/invent_menu.png");
    sprite->rect_menu_opt = (sfIntRect){0, 0, 264, 97};
    sfSprite_setTextureRect(sprite->sprite_menu_opt, sprite->rect_menu_opt);
    sprite->vect_menu_opt = (sfVector2f){0, 900};
    sfSprite_setPosition(sprite->sprite_menu_opt, sprite->vect_menu_opt);
}

void init_sprite_5(s_sprite *sprite)
{
    sprite->sprite_croix = sprite_creator("assets/inventaire/croix1.png");
    sprite->sprite_croix_p = sprite_creator("assets/inventaire/croix2.png");
    sprite->rect_croix = (sfIntRect){0, 0, 131, 170};
    sprite->rect_croix_p = (sfIntRect){0, 0, 131, 170};
    sprite->vect_croix = (sfVector2f){1170, 57};
    sfSprite_setTextureRect(sprite->sprite_croix, sprite->rect_croix);
    sfSprite_setTextureRect(sprite->sprite_croix_p, sprite->rect_croix_p);
    sfSprite_setPosition(sprite->sprite_croix, sprite->vect_croix);
    sfSprite_setPosition(sprite->sprite_croix_p, sprite->vect_croix);
    sprite->sprite_menu_invent_p =
    sprite_creator("assets/inventaire/invent_menu_p.png");
    sprite->sprite_exit_invent_p =
    sprite_creator("assets/inventaire/exit_menu_p.png");
    sprite->rect_menu_invent_p = (sfIntRect){0, 0, 264, 97};
    sprite->rect_exit_invent_p = (sfIntRect){0, 0, 264, 97};
    sfSprite_setTextureRect(sprite->sprite_menu_invent_p,
    sprite->rect_menu_invent_p);
    sfSprite_setTextureRect(sprite->sprite_exit_invent_p,
    sprite->rect_exit_invent_p);
    init_sprite_5_5(sprite);
}