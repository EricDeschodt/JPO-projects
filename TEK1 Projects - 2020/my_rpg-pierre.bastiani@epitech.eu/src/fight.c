/*
** EPITECH PROJECT, 2020
** fight
** File description:
** init
*/

#include "../include/include.h"

void check_util2(mobs *mob, players *player, int option)
{
    if (option == 3 && player->headbut->cur > 0) {
        player->headbut->cur--;
        mob->statu_ennemi = 3;
        sfClock_restart(mob->clock_attaque);
    }
    if (option == 4 && player->strangle->cur > 0) {
        player->strangle->cur--;
        mob->statu_ennemi = 4;
        sfClock_restart(mob->clock_attaque);
    }
}

void check_util(mobs *mob, players *player, int option)
{
    if (sfClock_getElapsedTime(mob->clock_attaque).microseconds < 2000000)
        return;
    player->ani->i = player->ani->d = 0;
    if (option == 1 && player->punch->cur > 0) {
        player->punch->cur--;
        mob->statu_ennemi = 1;
        sfClock_restart(mob->clock_attaque);
    }
    if (option == 2 && player->kick->cur > 0) {
        player->kick->cur--;
        mob->statu_ennemi = 2;
        sfClock_restart(mob->clock_attaque);
    }
    check_util2(mob, player, option);
}

int fight(s_game *game, mobs *mob, players *player)
{
    if (player->current_mob == -1)
        return (0);
    if (mob->life_ennemi > 0 && mob->life_sacha > 0 && player->combat == 4) {
        if (game->event_stat.type == sfEvtMouseButtonPressed && game->statment == 6) {
            fight_(game, mob, player);
        }
        life(mob);
        if (mob->life_ennemi <= 0 || mob->life_sacha <= 0 || player->punch->cur == 0) {
            check_end(game, mob, player);
            return (84);
        }
    }
    fight_2(game, mob, player);
    fight_3(game, mob, player);
    return (0);
}

int fight_2(s_game *game, mobs *mob, players *player)
{
    if (mob->life_ennemi > 0 && mob->life_sacha > 0 && player->combat == 2) {
        if (game->event_stat.type == sfEvtMouseButtonPressed && game->statment == 6) {
            fight_2_(game, mob, player);
        }
        life(mob);
        if (mob->life_ennemi <= 0 || mob->life_sacha <= 0) {
            check_end(game, mob, player);
            return (84);
        }
    }
    return (0);
}

int fight_3(s_game *game, mobs *mob, players *player)
{
    if (mob->life_ennemi > 0 && mob->life_sacha > 0 && player->combat == 3) {
        if (game->event_stat.type == sfEvtMouseButtonPressed && game->statment == 6) {
            fight_3_(game, mob, player);
        }
        life(mob);
        if (mob->life_ennemi <= 0 || mob->life_sacha <= 0) {
            check_end(game, mob, player);
            return (84);
        }
    }
    return (0);
}