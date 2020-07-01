/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower_upgrade.c
*/

#include "defender.h"

void do_upgrade(s_game *g, v2 pos)
{
    g->tower_m.slot->tower->s_dmg[0] = 0;
    g->tower_m.slot->tower->s_range[0] = 0;
    g->tower_m.slot->tower->atk += 0.04;
    g->hud->gold->gold -= 1, update_gold(g);
    my_strcat(g->tower_m.slot->tower->s_range, "RANGE: ");
    my_strcat(g->tower_m.slot->tower->s_range,
    my_itoa(g->tower_m.slot->tower->range));
    put_text(&g->tower_m.slot->tower->text_range,
    g->tower_m.slot->tower->s_range, (v2){pos.x + 150, pos.y + 65}, 16);
    my_strcat(g->tower_m.slot->tower->s_dmg, "DMG: ");
    my_strcat(g->tower_m.slot->tower->s_dmg,
    my_itoa(g->tower_m.slot->tower->atk));
    put_text(&g->tower_m.slot->tower->text_atk,
    g->tower_m.slot->tower->s_dmg, (v2){pos.x + 150, pos.y + 45}, 16);
    g->upgr = sfFalse;
}

void on_upgrade_tower(void *d)
{
    v2 pos = (v2){1920 / 1.5f, 1080 / 1.4f};
    s_game *g = (s_game *)d;
    if (g->upgr == sfFalse)
        do_upgrade(g, pos);
}