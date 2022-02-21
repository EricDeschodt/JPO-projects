/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** update_enemies
*/

#include "defender.h"

sfIntRect small_zombie(obj_t *enem, sfIntRect text_rect)
{
    text_rect.left = enem->random_texture.left;
    if (enem->frame >= 2) {
        enem->frame = 0;
    } else {
        if (enem->frame >= 1)
            text_rect.left += 48;
        else
            text_rect.left += 96;
        enem->frame++;
    }
    return (text_rect);
}

sfIntRect big_zombie(obj_t *enem, sfIntRect text_rect)
{
    text_rect.left = enem->random_texture.left;
    if (enem->frame >= 3) {
        enem->frame = 0;
    } else if (enem->frame >= 2) {
        text_rect.left += 128;
        enem->frame++;
    } else {
        if (enem->frame >= 1)
            text_rect.left += 258;
        else
            text_rect.left += 384;
        enem->frame++;
    }
    text_rect.top = enem->random_texture.top;
    return (text_rect);
}

static void handle_enemy_pos(sfVector2f pos, game_t *gm, obj_t *enem)
{
    if (pos.x >= 634 && pos.x <= 650)
        gm->life->points.y -= 0.10 * enem->stats.damage;
    handle_tower_damaged(gm, enem);
    if (pos.x - 1 > enem->stats.max_range) {
        pos.x -= enem->stats.speed;
        sfRectangleShape_setPosition(enem->body.rect, pos);
        sfRectangleShape_setPosition(enem->health.background, pos);
        sfRectangleShape_setPosition(enem->health.bar, pos);
    }
}

void update_enemies(vars_t *va, game_t *gm)
{
    sfVector2f pos;
    obj_t *enem;

    if (!gm->en->head->next) return;
    for (enem = gm->en->head->next; enem->next; enem = enem->next) {
        if (enem->stop == 1) continue;
        if (GET_TIME_EVERY_S(enem->frame_clock, 3, 100000))
            handle_animation(enem);
        pos = sfRectangleShape_getPosition(enem->body.rect);
        handle_traps(gm, enem, pos);
        handle_enemy_pos(pos, gm, enem);
        sfRenderWindow_drawRectangleShape(va->window, enem->body.rect, NULL);
        sfRenderWindow_drawRectangleShape(va->window, enem->health.background, \
                                                                        NULL);
        sfRenderWindow_drawRectangleShape(va->window, enem->health.bar, NULL);
    }
}
