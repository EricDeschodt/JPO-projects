/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** targetting
*/

#include "defender.h"

void turret_list_targetting(turret_t *tmp, all_t *s_all)
{
    char *tab[5];
    tab[0] = "sprites/buttons/FIRST.png";
    tab[1] = "sprites/buttons/LAST.png";
    tab[2] = "sprites/buttons/WEAKEST.png";
    tab[3] = "sprites/buttons/STRONGEST.png";
    tab[4] = "sprites/buttons/NEAREST.png";
    tmp->target = NULL;
    targetting_t *temp = s_all->s_targetting->begin;
    int big = 0;
    for (; temp != NULL && temp->big != 1; big++, temp = temp->next);
    int x = 1590;
    if (big == 1) x -= 50;
    if (big == 2) x -= 100;
    if (big == 3) x -= 150;
    if (big == 4) x -= 200;
    for (int i = 0; i != 5; i++, x += 50) {
        tmp->target = push_back_turret_targetting(tmp, x, tab[i], big);
    }
}

void list_targetting(all_t *s_all)
{
    char *tab[5];
    tab[0] = "sprites/buttons/FIRST.png";
    tab[1] = "sprites/buttons/LAST.png";
    tab[2] = "sprites/buttons/WEAKEST.png";
    tab[3] = "sprites/buttons/STRONGEST.png";
    tab[4] = "sprites/buttons/NEAREST.png";
    s_all->s_targetting = NULL;
    for (int i = 0, x = 2290; i != 5; i++, x += 50) {
        s_all->s_targetting = push_back_targetting(s_all, x, tab[i]);
    }
}

void display_targetting_buttons(all_t *s_all, list_targetting_t *s_targetting)
{
    targetting_t *tmp = s_targetting->begin;
    keep_centered_targetting(s_targetting);
    set_show_targetting(s_targetting);
    while (tmp != NULL) {
        if (tmp->big == 0 && tmp->show == 1) {
            sfSprite_setColor(tmp->sprite, (sfColor){125, 125, 125, 255});
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        } tmp = tmp->next;
    } tmp = s_targetting->begin;
    while (tmp != NULL) {
        if (tmp->big == 1) {
            sfSprite_setColor(tmp->sprite, (sfColor){255, 255, 255, 255});
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
            sfRenderWindow_drawText(s_all->s_game.window, tmp->str, NULL);
        } tmp = tmp->next;
    }
}

void hitbox_change_targetting_back(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= 1665 && mouse_pos.x <= 1692) && (mouse_pos.y >= 419
        && mouse_pos.y <= 454) && s_all->s_selected.type == 'O'
        && s_all->s_selected.on == 1) { button_sound(s_all);
        targetting_t *tmp = s_all->s_targetting->begin;
        while (tmp != NULL && tmp->big == 0) tmp = tmp->next;
        if (tmp->back != NULL) {
            sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(tmp->back->sprite, (sfVector2f){1, 1});
            tmp->back->big = 1, tmp->big = 0;
        } else { sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(s_all->s_targetting->end->sprite,
                (sfVector2f){1, 1});
            s_all->s_targetting->end->big = 1, tmp->big = 0;
        } tmp = s_all->s_targetting->begin;
        for (; tmp != NULL; tmp = tmp->next) {
            tmp->pos.x += s_all->s_targetting->size;
            sfSprite_setPosition(tmp->sprite, tmp->pos); }
    }
}

void hitbox_change_targetting_next(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= 1868 && mouse_pos.x <= 1893) && (mouse_pos.y >= 417 &&
        mouse_pos.y <= 455) && s_all->s_selected.type == 'O'
        && s_all->s_selected.on == 1) { button_sound(s_all);
        targetting_t *tmp = s_all->s_targetting->begin;
        while (tmp != NULL && tmp->big == 0) tmp = tmp->next;
        if (tmp->next != NULL) {
            sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(tmp->next->sprite, (sfVector2f){1, 1});
            tmp->next->big = 1, tmp->big = 0;
        } else { sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(s_all->s_targetting->begin->sprite,
                (sfVector2f){1, 1});
            s_all->s_targetting->begin->big = 1, tmp->big = 0;
        } tmp = s_all->s_targetting->begin;
        for (; tmp != NULL; tmp = tmp->next) {
            tmp->pos.x -= s_all->s_targetting->size;
            sfSprite_setPosition(tmp->sprite, tmp->pos); }
    }
}