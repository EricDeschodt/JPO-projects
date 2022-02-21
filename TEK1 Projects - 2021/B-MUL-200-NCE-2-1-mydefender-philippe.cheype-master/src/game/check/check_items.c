/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** check_items.c
*/

#include "defender.h"

static void handle_click(game_t *gm, int i, int j)
{
    if (!sfMouse_isButtonPressed(0)) return;
    if (i == 0 && gm->it[0]->info.money > (50 + 50 * j)) {
        gm->it[0]->info.check.x = -1;
        create_clone(gm->it, i, j);
    } else if (i == 1 && gm->it[0]->info.money > (150 + j * 50)) {
        gm->it[0]->info.check.x = -2;
        create_clone(gm->it, i, j);
    } else {
        if (i == 2 && gm->it[0]->info.money >= 500) {
            gm->it[0]->info.check.x = -3;
            create_clone(gm->it, i, j);
        }
    }
    sfMusic_stop(gm->sound[0]);
    sfMusic_play(gm->sound[0]);
}

static void handle_menu_items_hover(game_t *gm, sfVector2f m_pos, int i, int j)
{
    sfVector2f hover = { 1.1, 1.1 };
    sfVector2f pos_onclick, pos;
    sfVector2f out = { 1, 1 };

    pos = gm->it[i]->pos[j];
    if (m_pos.x > pos.x && m_pos.x < pos.x + gm->it[i]->size.x   \
    && m_pos.y > pos.y && m_pos.y < pos.y + gm->it[i]->size.y ) {
        pos_onclick = GET_POS_ON_CLICK(pos, gm->it[i]->size, 1.1);
        sfRectangleShape_setScale(gm->it[i]->rect[j], hover);
        sfRectangleShape_setPosition(gm->it[i]->rect[j], pos_onclick);
        handle_click(gm, i, j);
    } else {
        sfRectangleShape_setPosition(gm->it[i]->rect[j], gm->it[i]->pos[j]);
        sfRectangleShape_setScale(gm->it[i]->rect[j], out);
    }
}

void check_items(sfVector2f m_pos, game_t *gm)
{
    for (int i = 0; gm->it[i]; i++)
        for (int j = 0; gm->it[i]->rect[j]; j++)
            handle_menu_items_hover(gm, m_pos, i, j);
}
