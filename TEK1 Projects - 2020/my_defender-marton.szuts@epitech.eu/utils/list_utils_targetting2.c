/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** list_utils_targetting2
*/

#include "defender.h"

list_targetting_t *push_back_turret_targetting(turret_t *tmp, int x,
    char *tab, int big)
{
    static int incre = 0, i = 0, k = 0;
    if (k == 5) k = 0, incre = 0, i = 0;
    if (incre == big) i = 1;
    targetting_t *node = new_node_turret_targetting(x, tab, i);
    if (is_empty_list_targetting(tmp->target)) {
        tmp->target = malloc(sizeof(*tmp->target));
        tmp->target->length = 0;
        tmp->target->clock = sfClock_create();
        tmp->target->time =
            sfClock_getElapsedTime(tmp->target->clock);
        tmp->target->seconds =
            tmp->target->time.microseconds / 1000000.0;
        tmp->target->begin = node, tmp->target->end = node;
    } else {
        tmp->target->end->next = node;
        node->back = tmp->target->end;
        tmp->target->end = node;
    } tmp->target->length++;
    i = 0, tmp->target->size = 50, incre++, k++;
    return (tmp->target);
}

void display_turret_target(all_t *s_all)
{
    if (s_all->s_turret == NULL || s_all->s_selected.tur == NULL)
        return;
    list_targetting_t *target = s_all->s_selected.tur->target;
    display_targetting_buttons(s_all, target);
}

void hitbox_change_targetting_back_turret(all_t *s_all,
    list_targetting_t *s_targetting)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= 1459 && mouse_pos.x <= 1487) && (mouse_pos.y >= 939
        && mouse_pos.y <= 978) && s_all->s_selected.type == 'O'
        && s_all->s_selected.on == 1) { button_sound(s_all);
        targetting_t *tmp = s_targetting->begin;
        while (tmp != NULL && tmp->big == 0) tmp = tmp->next;
        if (tmp->back != NULL) {
            sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(tmp->back->sprite, (sfVector2f){1, 1});
            tmp->back->big = 1, tmp->big = 0;
        } else { sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(s_targetting->end->sprite,
                (sfVector2f){1, 1});
            s_targetting->end->big = 1, tmp->big = 0;
        } tmp = s_targetting->begin;
        for (; tmp != NULL; tmp = tmp->next) {
            tmp->pos.x += s_targetting->size;
            sfSprite_setPosition(tmp->sprite, tmp->pos); }
    }
}

void hitbox_change_targetting_next_turret(all_t *s_all,
    list_targetting_t *s_targetting)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= 1673 && mouse_pos.x <= 1702) && (mouse_pos.y >= 939 &&
        mouse_pos.y <= 977) && s_all->s_selected.type == 'O'
        && s_all->s_selected.on == 1) { button_sound(s_all);
        targetting_t *tmp = s_targetting->begin;
        while (tmp != NULL && tmp->big == 0) tmp = tmp->next;
        if (tmp->next != NULL) {
            sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(tmp->next->sprite, (sfVector2f){1, 1});
            tmp->next->big = 1, tmp->big = 0;
        } else { sfSprite_setScale(tmp->sprite, (sfVector2f){0.75, 0.75});
            sfSprite_setScale(s_targetting->begin->sprite,
                (sfVector2f){1, 1});
            s_targetting->begin->big = 1, tmp->big = 0;
        } tmp = s_targetting->begin;
        for (; tmp != NULL; tmp = tmp->next) {
            tmp->pos.x -= s_targetting->size;
            sfSprite_setPosition(tmp->sprite, tmp->pos); }
    }
}

list_targetting_t *pop_front_targetting(list_targetting_t *li)
{
    if (is_empty_list_targetting(li)) return (NULL);
    if (li->begin == li->end) {
        sfFont_destroy(li->begin->font);
        sfText_destroy(li->begin->str);
        sfSprite_destroy(li->begin->sprite);
        sfTexture_destroy(li->begin->texture);
        free (li->begin);
        free (li);
        return (NULL);
    } targetting_t *tmp = li->begin;
    li->begin = li->begin->next;
    tmp->next = NULL;
    sfFont_destroy(tmp->font);
    sfText_destroy(tmp->str);
    sfSprite_destroy(tmp->sprite);
    sfTexture_destroy(tmp->texture);
    free (tmp);
    li->length--;
    return (li);
}