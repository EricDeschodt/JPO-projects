/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** creator_buttons2
*/

#include "defender.h"

void free_placed_node(all_t *s_all)
{
    support_t *tmp = s_all->s_map_edit.head;
    while (s_all->s_map_edit.placed != NULL) {
        support_t *temp = s_all->s_map_edit.placed;
        sfSprite_destroy(s_all->s_map_edit.placed->sprite),
        sfTexture_destroy(s_all->s_map_edit.placed->texture);
        s_all->s_map_edit.placed = s_all->s_map_edit.placed->next;
        free(temp);
    }
    while (tmp != NULL) {
        tmp->on = 0;
        tmp->type = '@';
        tmp = tmp->next;
    }
}

void button_selector(map_button_t *node, all_t *s_all)
{
    if (node->id == 0 && s_all->s_map_edit.placed != NULL) {
        support_t *temp = s_all->s_map_edit.placed;
        sfSprite_destroy(s_all->s_map_edit.placed->sprite),
        sfTexture_destroy(s_all->s_map_edit.placed->texture);
        if (temp->type == 'S') sfSprite_destroy(temp->sprite_base);
        temp->placed->on = 0, temp->placed->type = '@';
        s_all->s_map_edit.placed = s_all->s_map_edit.placed->next;
        s_all->s_selected.sel->on = 0, s_all->s_selected.sel->type = '@';
        free(temp);
    }
    if (node->id == 1 && s_all->s_map_edit.placed != NULL)
        free_placed_node(s_all);
    if (node->id == 2 && s_all->s_map_edit.placed != NULL)
        save_map(s_all);
    if (node->id == 3) {
        s_all->s_game.transition = 0, s_all->s_game.pause = 0;
        s_all->s_game.lost_anim = 0;
    }
}

void release_creator_buttons(all_t *s_all)
{
    map_button_t *temp = s_all->s_map_buttons;
    while (temp != NULL) {
        if (check_creator_button_hitbox(temp, s_all)
        && s_all->s_game.scene == 2) {
            sfSprite_setTexture(temp->sprite, temp->hover,sfTrue);
            button_selector(temp, s_all);
            if (s_all->s_settings->sound == 1)
                sfSound_play(s_all->s_sounds.button);
        }
        temp = temp->next;
    }
}