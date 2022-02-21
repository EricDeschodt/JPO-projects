/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** multiple menu handling
*/

#include "../include/menus.h"

void sub_end(elements_t *e)
{
    sfText_setOutlineThickness(e->score->label, 6);
    sfText_setOutlineThickness(e->score->text, 6);
    sfSprite_setTexture(e->interface->play, e->interface->replay_text, sfTrue);
    sfRenderWindow_setMouseCursorVisible(e->window, sfTrue);
}

void end_menu(elements_t *e)
{
    if (e->map->rang < e->map->x)
        sfSound_play(e->audio->death);
    else
        sfSound_play(e->audio->win);
    sfVector2f label_pos = {715, 450};
    sfText_setPosition(e->score->label, label_pos);
    sfText_setCharacterSize(e->score->label, 50);
    sfVector2f score_pos = {label_pos.x + 250, label_pos.y};
    sfText_setPosition(e->score->text, score_pos);
    sfText_setCharacterSize(e->score->text, 50);
    sfText_setString(e->interface->end_label, (e->map->rang >= e->map->x)?
    "You won":"You lose");
    sfVector2f o = {(float)((int)(sfText_getLocalBounds(e->interface->end_label)
    .width / 2)), 35};
    sfText_setOrigin(e->interface->end_label, o);
    sfVector2f end_p = {(float)(1920.0 / 2), (float)(1080.0 / 3)};
    sfText_setPosition(e->interface->end_label, end_p);
    sfMusic_stop(e->audio->music);
    sub_end(e);
}

void game_menu(elements_t *e)
{
    sfMusic_play(e->audio->music);
    e->map->rang = 0;
    sfText_setOutlineThickness(e->score->label, 3);
    sfText_setOutlineThickness(e->score->text, 3);
    sfVector2f pos = {150, 0};
    sfText_setPosition(e->score->text, pos);
    pos.x = 0;
    sfText_setPosition(e->score->label, pos);
    sfText_setCharacterSize(e->score->label, 30);
    sfText_setCharacterSize(e->score->text, 30);
    my_strcpy(e->score->string, "0000000");
    sfRenderWindow_setMouseCursorVisible(e->window, sfFalse);
    sfVector2f poss = {(float)(1080.0/7) * 2, (float)(1080.0/7) * 6 - 1};
    sfSprite_setPosition(e->chr->sprite, poss);
    e->chr->is_jumping = false;
    e->chr->pos = poss.y;
}

elements_t *switch_menu(elements_t *e, short menu)
{
    e->menu = menu;
    if (menu == 0)
        end_menu(e);
    if (menu == 1)
        game_menu(e);
    return e;
}