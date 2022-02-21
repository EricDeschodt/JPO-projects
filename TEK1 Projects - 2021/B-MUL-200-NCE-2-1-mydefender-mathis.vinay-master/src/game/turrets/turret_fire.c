/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Handles the dps of any turrets and make them fire at an enemy
*/

#include "../../../include/game/turrets.h"
#include "../../../include/game/main_game.h"

void turret_fire(main_game_t *g, turret_t *t, enemy_t *e)
{
    time_update(t->time, 2);
    if (t->time->counter_dps >= t->dps) {
        sound_set_status(t->gunfire, "play");
        t->time->counter_dps = 0;
        bullet_add(g, t, e);
    }
}
