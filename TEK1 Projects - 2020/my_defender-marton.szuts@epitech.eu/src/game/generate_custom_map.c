/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** generate_custom_map
*/

#include "defender.h"

int check_example_hitbox(support_t *temp, all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x > temp->pos.x && mouse_pos.x < temp->pos.x + 120)
        && (mouse_pos.y > temp->pos.y && mouse_pos.y < temp->pos.y + 120))
        return (1);
    return (0);
}

support_t *place_tile(support_t *temp, all_t *s_all, support_t *old)
{
    if (temp->type == 'G') {
        s_all->s_selected.sel->type = 'G';
        return (fill_support(old, s_all->s_selected.sel->pos,
        "sprites/ground.png", 'G'));
    } if (temp->type == 'C') {
        s_all->s_selected.sel->type = 'C';
        return (fill_support(old, s_all->s_selected.sel->pos,
        "sprites/castle.png", 'C'));
    } if (temp->type == 'S') {
        s_all->s_selected.sel->type = 'S';
        return (fill_support(old, s_all->s_selected.sel->pos,
        "sprites/spawner.png", 'S'));
    } if (temp->type == 'O') {
        s_all->s_selected.sel->type = 'O';
        return (fill_support(old, s_all->s_selected.sel->pos,
        "sprites/turret_support.png", 'O'));
    } return (NULL);
}

void click_n_place(all_t *s_all)
{
    support_t *temp = s_all->s_map_edit.examples;
    while (temp != NULL) {
        if (check_example_hitbox(temp, s_all) &&
        s_all->s_selected.sel != NULL && s_all->s_selected.sel->type == '@') {
            s_all->s_map_edit.placed = place_tile(temp, s_all,
            s_all->s_map_edit.placed);
            s_all->s_map_edit.placed->placed = s_all->s_selected.sel;
            if (s_all->s_settings->sound == 1)
                sfSound_play(s_all->s_sounds.build);
        }
        temp = temp->next;
    }
}

void display_placed(all_t *s_all)
{
    support_t *temp = s_all->s_map_edit.placed;
    while (temp != NULL) {
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        temp = temp->next;
    }
}

void display_error_texts(all_t *s_all)
{
    if (s_all->s_map_edit.seconds < 2.5 && s_all->s_map_edit.error == 1) {
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_map_edit.error1, NULL);
    }
    else {
        sfClock_restart(s_all->s_map_edit.clock);
        s_all->s_map_edit.error = 0;
    }
}