/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** handle_items.c
*/

#include "defender.h"

sfIntRect handle_frames(obj_t *enem, sfIntRect text_rect)
{
    if (enem->random_texture.top == 0)
        text_rect = small_zombie(enem, text_rect);
    else
        text_rect = big_zombie(enem, text_rect);
    return (text_rect);
}

void handle_animation(obj_t *enem)
{
    sfIntRect text_rect;
    char path[] = "assets/textures/enemies_ss.png";

    text_rect = sfRectangleShape_getTextureRect(enem->body.rect);
    text_rect = handle_frames(enem, text_rect);
    sfTexture *texture = sfTexture_createFromFile(path, &text_rect);
    sfRectangleShape_setTexture(enem->body.rect, texture, sfFalse);
    sfClock_restart(enem->frame_clock);
}

void handle_tower_damaged(game_t *gm, obj_t *enem)
{
    sfVector2f tw_pos;
    sfVector2f enem_pos;
    obj_t *tw;

    if (!gm->tw->head->next) return;
    enem_pos = sfRectangleShape_getPosition(enem->body.rect);
    for (tw = gm->tw->head->next; tw->next; tw = tw->next) {
        tw_pos = sfRectangleShape_getPosition(tw->body.rect);
        if (enem_pos.x >= tw_pos.x + 32 && enem_pos.x <= tw_pos.x + 96   \
        && enem->stats.row == tw->stats.row) {
            enem->stats.max_range = tw_pos.x;
        }
    }
}

static void manage_life(obj_t *enem, obj_t *blds, int trap, sfVector2f blds_pos)
{
    if (blds->body.index.x == 0) {
        reduce_tower_life(blds, enem, blds_pos);
    } else {
        if ((trap = blds->body.index.y) == 0)
            reduce_tower_life(blds, enem, blds_pos);
        else
            reduce_enemies_life(blds, enem, trap);
    }
}

void handle_traps(game_t *gm, obj_t *enem, sfVector2f e_pos)
{
    sfVector2f blds_pos;
    obj_t *blds;
    int trap;

    if (!gm->tw->head->next) return;
    for (blds = gm->tw->head->next; blds; blds = blds->next) {
        if (blds->stop == 1) continue;
        blds_pos = sfRectangleShape_getPosition(blds->body.rect);
        if (((enem->stats.damage > 1.0                           \
        && blds->stats.row == enem->stats.row + 64)              \
        || (blds->stats.row == enem->stats.row))                 \
        && e_pos.x >= blds_pos.x && e_pos.x <= blds_pos.x + 64)
            manage_life(enem, blds, trap, blds_pos);
    }
}
