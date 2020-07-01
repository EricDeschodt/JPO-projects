/*
** EPITECH PROJECT, 2020
** end
** File description:
** fight
*/

#include "../include/include.h"

void end_fight_player(s_game *game, mobs *mob, players* player)
{
    if (mob->life_sacha <= 0 || (player->kick->cur == 0 && player->strangle->cur
    == 0 && player->headbut->cur == 0)) {
        player->inv->troph = false;
        mob->state = 0;
        player->current_mob = -1;
        player->pos_x = 5366;
        player->pos_y = 2800;
        player->kick->cur = player->kick->max;
        player->punch->cur = player->punch->max;
        player->strangle->cur = player->strangle->max;
        player->headbut->cur = player->headbut->max;
        mob->life_sacha = 10;
        game->statment = 15;
        sfClock_restart(player->clock);
        sfMusic_play(game->Music_game);
    }
}

void end_fight_ennemie(s_game *game, mobs *mob, players* player)
{
    if (mob->life_ennemi <= 0) {
        player->inv->xp = player->inv->xp + mob->recompense;
        mob->state = 2;
        game->statment = 2;
        player->current_mob = -1;
        sfMusic_play(game->Music_game);
    }
}

void check_end(s_game *game, mobs *mob, players* player)
{
    end_fight_player(game, mob, player);
    end_fight_ennemie(game, mob, player);
}