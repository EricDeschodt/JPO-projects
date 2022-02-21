/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** update_bullets
*/

#include "defender.h"
#include "elements.h"

static void deal_damage(obj_t *enem, bullet_t *temp,        \
                        float damage, sfVector2f delay)
{
    sfVector2f h_size;

    h_size = sfRectangleShape_getSize(enem->health.bar);
    if (h_size.x <= 0) {
        if (enem->next) enem->next->prev = enem->prev;
        if (enem->prev) enem->prev->next = enem->next;
        enem->stop = 1;
    }
    if (GET_TIME_EVERY_S(temp->clock, delay.x, delay.y)) {
        h_size.x -= damage;
        sfClock_restart(temp->clock);
    }
    sfRectangleShape_setSize(enem->body.rect, h_size);
}

static void handle_damage(game_t *gm, bullet_t *temp,     \
                                sfVector2f pos, int n)
{
    sfVector2f mem = {5, 100000};
    sfVector2f delay;
    float damage;
    obj_t *enem;

    for (enem = gm->en->head->next; enem; enem = enem->next) {
        if (enem->stats.row <= pos.y - 64 && enem->stats.row >= pos.y + 64) {
            damage = 1.0;
            delay = mem;
            if (n == 1 && enem->pos_size.left >= pos.x       \
            && enem->pos_size.left <= pos.x + 192) {
                damage = 5.0;
                delay.x = 1;
                delay.y = 100000;
            }
            deal_damage(enem, temp, damage, delay);
        }
    }
}

static sfVector2f move_bullets(bullet_t *temp, sfVector2f pos)
{
    if (GET_TIME_EVERY_S(temp->clock, 1, 100)) {
        pos = sfRectangleShape_getPosition(temp->bullet);
        pos.x += temp->motion.x;
        pos.y += temp->motion.y;
        sfRectangleShape_setPosition(temp->bullet, pos);
        sfClock_restart(temp->clock);
    }
    return (pos);
}

static void handle_bullets_update(game_t *gm, bullet_t *temp)
{
    sfVector2f pos;

    if (temp->clock && (temp->type == 1 || temp->type == 2) \
    && GET_TIME_EVERY_S(temp->clock, 2, 100000)) {
        handle_damage(gm, temp, pos, 0);
        handle_damage(gm, temp, pos, 1);
        sfClock_restart(temp->clock);
    } else if (temp && temp->type != 1 && temp->type != 2  \
    && temp->bullet && temp->stop == 0) {
        if (temp->frame < 3)
            pos = move_bullets(temp, pos);
    }
}

void update_bullets(sfRenderWindow *win, game_t *gm)
{
    bullet_t *temp;

    if (!gm->bl) return;
    for (temp = gm->bl->head; temp; temp = temp->next) {
        if (temp && temp->bullet && temp->frame >= 3) {
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
        }
        handle_bullets_update(gm, temp);
        if (temp && temp->bullet && temp->frame < 3)
            sfRenderWindow_drawRectangleShape(win, temp->bullet, NULL);
    }
}
