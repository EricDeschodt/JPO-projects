/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** reduce_enemies_life.c
*/

#include "defender.h"

static void pic_manager(obj_t *enem, obj_t *blds, sfVector2f pic_size, \
                                                                sfVector2f size)
{
    if (pic_size.x <= 0) {
            if (blds->next) blds->next->prev = blds->prev;
            if (blds->prev) blds->prev->next = blds->next;
            blds->stop = 1;
        }
    sfRectangleShape_setSize(enem->health.bar, size);
    pic_size.x -= 5.0;
    sfRectangleShape_setSize(blds->health.bar, pic_size);
    sfClock_restart(blds->frame_clock);
}

static void bomb_manager(obj_t *enem, obj_t *blds, sfVector2f size)
{
    if (blds->next) blds->next->prev = blds->prev;
    if (blds->prev) blds->prev->next = blds->next;
    blds->stop = 1;
    sfRectangleShape_setSize(enem->health.bar, size);
}

void reduce_enemies_life(obj_t *blds, obj_t *enem, int trap)
{
    sfVector2f size;
    sfVector2f pic_size;
    float damage;

    damage = 5.0 * blds->stats.level;
    size = sfRectangleShape_getSize(enem->health.bar);
    if (trap == 2)
        damage = 50.0 * blds->stats.level;
    else
        pic_size = sfRectangleShape_getSize(blds->health.bar);
    size.x -= damage;
    if (trap == 1 && GET_TIME_EVERY_S(blds->frame_clock, 1, 1000000))
        pic_manager(enem, blds, pic_size, size);
    else if (trap == 2)
        bomb_manager(enem, blds, size);
    if (size.x <= 0) {
        if (enem->next) enem->next->prev = enem->prev;
        if (enem->prev) enem->prev->next = enem->next;
        enem->stop = 1;
    }
}

void reduce_tower_life(obj_t *blds, obj_t *enem, sfVector2f blds_pos)
{
    sfVector2f size;

    size = sfRectangleShape_getSize(blds->health.bar);
    enem->stats.max_range = blds_pos.x + 48;
    if (size.x <= 0) {
        if (blds->next) blds->next->prev = blds->prev;
        if (blds->prev) blds->prev->next = blds->next;
        enem->stats.max_range = 634;
        blds->stop = 1;
    }
    if (GET_TIME_EVERY_S(blds->frame_clock, 1, 1000000)) {
        size.x -= (5.0 / blds->stats.level) + (1.5 * enem->stats.damage);
        sfRectangleShape_setSize(blds->health.bar, size);
        sfClock_restart(blds->frame_clock);
    }
}
