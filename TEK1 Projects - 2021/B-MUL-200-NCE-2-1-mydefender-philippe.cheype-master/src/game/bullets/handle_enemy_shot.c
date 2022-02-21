/*
** EPITECH PROJECT, 2020
** B-MUL-200-NCE-2-1-mydefender-philippe.cheype
** File description:
** check_ennemy_shot.c
*/

#include "defender.h"
#include "elements.h"

static void handle_explosion(bullet_t *bl)
{
    char path[] = "assets/textures/bullets_ss.png";
    sfIntRect mem = {0, 69, 64, 30};
    sfIntRect area;

    area = mem;
    if (bl->frame == 3) {
        if (bl->next) bl->next->prev = bl->prev;
        if (bl->prev) bl->prev->next = bl->next;
    } else {
        area.left += 64 * ++bl->frame;
    }
    sfTexture *texture = sfTexture_createFromFile(path, &area);
    sfRectangleShape_setTexture(bl->bullet, texture, sfFalse);
}

static void reduce_life(obj_t *enem, game_t *gm)
{
    sfVector2f size = sfRectangleShape_getSize(enem->health.bar);

    size.x -= 3 * (gm->tw->stats.level + 1);
    if (size.x <= 0) {
        if (enem->next) enem->next->prev = enem->prev;
        if (enem->prev) enem->prev->next = enem->next;
        enem->stop = 1;
        gm->it[0]->info.killed += 1;
    }
    sfRectangleShape_setSize(enem->health.bar, size);
    gm->it[0]->info.score += 2;
}

static void handle_effects(game_t *gm, bullet_t *bl, obj_t *enem)
{
    sfColor light_blue = {60, 255, 255, 255};
    sfVector2f e_pos, bl_pos;

    e_pos = sfRectangleShape_getPosition(enem->body.rect);
    bl_pos = sfRectangleShape_getPosition(bl->bullet);
    if (bl->stop == 0 && bl_pos.x >= e_pos.x - 36 && bl_pos.x <= e_pos.x + 12) {
        bl->is_exploding = 1;
        bl->stop = 1;
        if (bl->type == 5) {
            sfRectangleShape_setFillColor(enem->health.bar, light_blue);
            if (enem->stats.is_slowed != 1) enem->stats.speed *= 0.60;
            enem->stats.is_slowed = 1;
            gm->it[0]->info.score += 2;
        } else
            reduce_life(enem, gm);
    }
}

static void check_for_bullet_collision(game_t *gm, obj_t *enem)
{
    bullet_t *bl;

    for (bl = gm->bl->head; bl; bl = bl->next) {
        if (((enem->stats.damage > 1.0                          \
        && bl->row == enem->stats.row + 64)                     \
        || (bl->row == enem->stats.row)) && bl->stop == 0)
            handle_effects(gm, bl, enem);
        if (bl->is_exploding && bl->frame >= 3) bl->is_exploding = 0;
        if (bl->is_exploding) handle_explosion(bl);
    }
}

void handle_enemy_shot(game_t *gm)
{
    obj_t *enem;

    if (!gm->en->head->next) return;
    for (enem = gm->en->head->next; enem; enem = enem->next)
        if (enem->stop != 1)
            check_for_bullet_collision(gm, enem);
}
