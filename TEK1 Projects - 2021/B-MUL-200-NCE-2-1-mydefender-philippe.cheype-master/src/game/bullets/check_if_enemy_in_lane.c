/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** check_if_enemy_in_lane
*/

#include "defender.h"
#include "elements.h"

static bullet_t *handle_bullet(obj_t *tw, obj_t *en, float type, game_t *gm)
{
    sfVector2f pos = {tw->pos_size.left + 40, tw->pos_size.top + 20};
    sfVector2f motion = {5, 0};
    bullet_t *bullet;
    sfMusic_stop(gm->sound[1]);
    sfMusic_play(gm->sound[1]);
    sfMusic_setVolume(gm->sound[1], 10.0);
    if (en->pos_size.left < tw->pos_size.left) return (NULL);
    bullet = create_bullet(pos, motion, type);
    if (tw->body.index.y == 1)
        tw->stats.shot_by = 1;
    bullet->row = tw->stats.row;
    bullet->stop = 0;
    return (bullet);
}

static void check_if_add_enemy(game_t *gm, obj_t *temp, obj_t *temp_en)
{
    temp_en->stats.shot_by = 0;
    if (temp->stats.row == temp_en->stats.row       \
    && temp->body.index.x == 0) {
        temp_en->stats.shot_by = 1;
        if (gm->bl->head == NULL) {
            gm->bl = handle_bullet(temp,            \
            temp_en, temp->body.index.y, gm);
            gm->bl->head = gm->bl;
            gm->bl->prev = NULL;
        } else {
            gm->bl->next = handle_bullet(temp,      \
            temp_en, temp->body.index.y, gm);
            gm->bl->next->head = gm->bl->head;
            gm->bl->next->prev = gm->bl;
            gm->bl = gm->bl->next;
        }
    }
}

static void check_ennemy_in_lane(game_t *gm, obj_t *temp, obj_t *temp_en)
{
    if (GET_TIME_EVERY_S(temp->frame_clock, 5, 1000000)) {
        for (temp_en = gm->en->head->next; temp_en;
        temp_en = temp_en->next)
            check_if_add_enemy(gm, temp, temp_en);
        sfClock_restart(temp->frame_clock);
    }
}

void check_if_enemy_in_lane(game_t *gm)
{
    obj_t *temp_en;
    obj_t *temp;

    if (!gm->tw || !gm->en) return;
    for (temp = gm->tw->head->next; temp; temp = temp->next) {
        if (temp->frame_clock)
            check_ennemy_in_lane(gm, temp, temp_en);
    }
}
