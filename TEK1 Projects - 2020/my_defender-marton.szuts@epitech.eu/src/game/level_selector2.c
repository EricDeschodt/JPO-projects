/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** level_selector2
*/

#include "defender.h"

void menu_level_hitbox(levels_t *tmp, all_t *s_all)
{
    tmp->time = sfClock_getElapsedTime(tmp->clock);
    tmp->seconds = tmp->time.microseconds / 1000000.0;
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= tmp->pos.x - (200 * tmp->scale) && mouse_pos.x
    <= tmp->pos.x + (200 * tmp->scale)) && (mouse_pos.y >= tmp->pos.y -
    (117 * tmp->scale) && mouse_pos.y <= tmp->pos.y + (117 * tmp->scale))
    && tmp->seconds > 0.01) {
        if (tmp->scale < 1.18)
            tmp->scale += 0.02;
        sfClock_restart(tmp->clock);
        sfSprite_setScale(tmp->sprite, (sfVector2f){tmp->scale, tmp->scale});
    } else if (tmp->scale > 1 && tmp->seconds > 0.01) {
            tmp->scale -= 0.02;
        sfSprite_setScale(tmp->sprite, (sfVector2f){tmp->scale, tmp->scale});
        sfClock_restart(tmp->clock);
    }
}

void map_selector_click(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    levels_t *temp = s_all->s_levels;
    if (s_all->s_game.scene != -1)
        return;
    while (temp != NULL) {
        if ((mouse_pos.x > temp->pos.x - (200 * temp->scale)
        && mouse_pos.x < temp->pos.x + (200 * temp->scale))
        && (mouse_pos.y > temp->pos.y - (117 * temp->scale)
        && mouse_pos.y < temp->pos.y + (117 * temp->scale))) {
            sfSprite_setTexture(temp->sprite, temp->click, sfTrue);
        } temp = temp->next;
    }
}

void init_level_buttons2(all_t *s_all)
{
    s_all->s_menu.line = sfRectangleShape_create();
    sfRectangleShape_setPosition(s_all->s_menu.line, (sfVector2f){-20, 650});
    sfRectangleShape_setSize(s_all->s_menu.line, (sfVector2f){2000, 5});
    sfRectangleShape_setFillColor(s_all->s_menu.line,
        (sfColor){140, 220, 240, 240});
}