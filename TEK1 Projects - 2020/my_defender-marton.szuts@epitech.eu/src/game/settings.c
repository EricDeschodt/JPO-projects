/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** settings
*/

#include "defender.h"

void list_settings_buttons(all_t *s_all)
{
    s_all->s_settings = NULL;
    for (int i = 0, x = 875, y = 368; i != 7; i++, y += 50) {
        if (i == 1) x -= 25;
        if (i == 2) y += 165, x -= 20;
        if (i == 4) y -= 300, x += 415;
        if (i > 4) x += 122, y -= 50;
        if (i < 4) s_all->s_settings = push_back_settings(s_all, x, y, i);
        else s_all->s_settings = push_back_settings(s_all, x, y, i);
    }
}

void display_settings_buttons(all_t *s_all)
{
    node_settings_t *tmp = s_all->s_settings->begin;
    while (tmp != NULL) {
        if (s_all->s_game.scene == 4)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void on_off_settings2(all_t *s_all, int i, node_settings_t *tmp)
{
    if (i == 3) {
        s_all->s_settings->sound = !s_all->s_settings->sound;
        if (s_all->s_settings->sound == 0)
            sfSprite_setTexture(tmp->sprite, tmp->off, sfTrue);
        else sfSprite_setTexture(tmp->sprite, tmp->on, sfTrue);
    } node_settings_t *off = s_all->s_settings->begin;
    for (int x = 0; i >= 4 && off != NULL; off = off->next, x++) {
        if (x >= 4)
            sfSprite_setTexture(off->sprite, off->off, sfTrue);
    }
    if (i == 4) {
        sfRenderWindow_setFramerateLimit(s_all->s_game.window, 30);
        sfSprite_setTexture(tmp->sprite, tmp->on, sfTrue);
    } if (i == 5) {
        sfRenderWindow_setFramerateLimit(s_all->s_game.window, 60);
        sfSprite_setTexture(tmp->sprite, tmp->on, sfTrue);
    } if (i == 6) {
        sfRenderWindow_setFramerateLimit(s_all->s_game.window, 120);
        sfSprite_setTexture(tmp->sprite, tmp->on, sfTrue);
    }
}

void on_off_settings(all_t *s_all, int i, node_settings_t *tmp)
{
    if (i == 0) {
        s_all->s_settings->eric = !s_all->s_settings->eric;
        set_eric_skin(s_all);
        if (s_all->s_settings->eric == 0)
            sfSprite_setTexture(tmp->sprite, tmp->off, sfTrue);
        else sfSprite_setTexture(tmp->sprite, tmp->on, sfTrue);
    } if (i == 1) {
        s_all->s_settings->shaders = !s_all->s_settings->shaders;
        if (s_all->s_settings->shaders == 0)
            sfSprite_setTexture(tmp->sprite, tmp->off, sfTrue);
        else sfSprite_setTexture(tmp->sprite, tmp->on, sfTrue);
    } if (i == 2) {
        s_all->s_settings->music = !s_all->s_settings->music;
        if (s_all->s_settings->music == 0) {
            sfSprite_setTexture(tmp->sprite, tmp->off, sfTrue);
            sfMusic_stop(s_all->s_menu.main_theme);
        } else { sfSprite_setTexture(tmp->sprite, tmp->on, sfTrue);
            sfMusic_play(s_all->s_menu.main_theme);
        }
    } on_off_settings2(s_all, i, tmp);
}

void settings_press_buttons(all_t *s_all)
{
    node_settings_t *tmp = s_all->s_settings->begin;
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    for (int i = 0; tmp != NULL; i++) {
        if ((mouse_pos.x >= tmp->pos.x && mouse_pos.x <= tmp->pos.x + 70)
            && (mouse_pos.y >= tmp->pos.y && mouse_pos.y <= tmp->pos.y + 55)) {
            on_off_settings(s_all, i, tmp);
            if (s_all->s_settings->sound == 1)
                sfSound_play(s_all->s_sounds.button);
        }
        tmp = tmp->next;
    }
}