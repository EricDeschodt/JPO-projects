/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** info_text
*/

#include "defender.h"

void init_info_texts3(all_t *s_all)
{
    sfText_setCharacterSize(s_all->s_info_text.castle_txt, 20);
    sfText_setCharacterSize(s_all->s_info_text.spawner_txt, 20);
    sfText_setCharacterSize(s_all->s_info_text.ground_txt, 20);
    sfText_setCharacterSize(s_all->s_info_text.support_txt, 20);
    sfText_setPosition(s_all->s_info_text.title_o, s_all->s_info_text.
    pos_title), sfText_setPosition(s_all->s_info_text.support_txt, s_all->
    s_info_text.pos_title), sfText_setPosition(s_all->s_info_text.title_c,
    s_all->s_info_text.pos_title), sfText_setPosition(s_all->s_info_text.
    castle_txt, s_all->s_info_text.pos_txt), sfText_setPosition(s_all->
    s_info_text.title_s, s_all->s_info_text.pos_title);
    sfText_setPosition(s_all->s_info_text.spawner_txt, s_all->s_info_text.
    pos_txt), sfText_setPosition(s_all->s_info_text.title_g, s_all->
    s_info_text.pos_title), sfText_setPosition(s_all->s_info_text.ground_txt,
    s_all->s_info_text.pos_txt);
}

void init_info_texts2(all_t *s_all)
{
    sfText_setString(s_all->s_info_text.title_o, "TURRET SUPPORT");
    sfText_setString(s_all->s_info_text.title_c, "CASTLE");
    sfText_setString(s_all->s_info_text.title_g, "GROUND");
    sfText_setString(s_all->s_info_text.title_s, "SPAWNER");
    sfText_setString(s_all->s_info_text.castle_txt,
    "This is the castle, protect it!");
    sfText_setString(s_all->s_info_text.ground_txt,
    "This is the ground, you can't place a turret here.");
    sfText_setString(s_all->s_info_text.spawner_txt,
    "This is the spawner, ennemies are coming from\nhere.");
    sfText_setString(s_all->s_info_text.support_txt,
    "Double click on a turret to place it.");
    sfText_setFont(s_all->s_info_text.castle_txt, s_all->s_game.font);
    sfText_setFont(s_all->s_info_text.ground_txt, s_all->s_game.font);
    sfText_setFont(s_all->s_info_text.spawner_txt, s_all->s_game.font);
    sfText_setFont(s_all->s_info_text.title_c, s_all->s_game.font);
    sfText_setFont(s_all->s_info_text.title_g, s_all->s_game.font);
    sfText_setFont(s_all->s_info_text.title_s, s_all->s_game.font);
    init_info_texts3(s_all);
}

void init_info_texts(all_t *s_all)
{
    s_all->s_info_text.support_txt = sfText_create();
    s_all->s_info_text.castle_txt = sfText_create();
    s_all->s_info_text.ground_txt = sfText_create();
    s_all->s_info_text.spawner_txt = sfText_create();
    s_all->s_info_text.support_txt = sfText_create();
    s_all->s_info_text.title_c = sfText_create();
    s_all->s_info_text.title_g = sfText_create();
    s_all->s_info_text.title_s = sfText_create();
    s_all->s_info_text.title_o = sfText_create();
    sfText_setFont(s_all->s_info_text.title_o, s_all->s_game.font);
    sfText_setFont(s_all->s_info_text.support_txt, s_all->s_game.font);
    s_all->s_info_text.pos_txt = (sfVector2f){1950, 80};
    s_all->s_info_text.pos_title = (sfVector2f){1950, 30};
    init_info_texts2(s_all);
}

void display_info_texts2(all_t *s_all)
{
    if (s_all->s_selected.sel->type == 'O'
    && s_all->s_selected.sel->on != 1) {
        sfRenderWindow_drawText(s_all->s_game.window, s_all->s_info_text.
        title_o, NULL), sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_info_text.support_txt, NULL);
    } if (s_all->s_selected.sel->type == 'O'
    && s_all->s_selected.sel->on == 1) {
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->name, NULL);
    }
}

void display_info_texts(all_t *s_all)
{
    if (s_all->s_selected.sel != NULL && s_all->s_side_menu.draw == 1) {
        if (s_all->s_selected.sel->type == 'G') {
            sfRenderWindow_drawText(s_all->s_game.window, s_all->s_info_text.
            title_g, NULL), sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_info_text.ground_txt, NULL);
        } if (s_all->s_selected.sel->type == 'S') {
            sfRenderWindow_drawText(s_all->s_game.window, s_all->s_info_text.
            title_s, NULL), sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_info_text.spawner_txt, NULL);
        } if (s_all->s_selected.sel->type == 'C') {
            sfRenderWindow_drawText(s_all->s_game.window, s_all->s_info_text.
            title_c, NULL), sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_info_text.castle_txt, NULL);
        } display_info_texts2(s_all);
    }
}