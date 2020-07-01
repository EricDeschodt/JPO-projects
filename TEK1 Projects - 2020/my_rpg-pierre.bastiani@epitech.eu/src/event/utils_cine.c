/*
** EPITECH PROJECT, 2020
** utils
** File description:
** cine
*/

#include "../../include/include.h"

void cine1(players *player, s_game *game)
{
    if (game->statment == 11) {
        player->pos_x = player->pos_x - 16;
        if (check_in(player, convert_pos(4700, 2900),
        convert_pos(4900, 3600)) == 1) {
            player->pos_x = 9100;
            player->pos_y = 3650;
            game->statment = 2;
            player->state = 7;
        }
    }
}

void cine2(players *player, s_game *game)
{
    if (game->statment == 12) {
        player->pos_x = player->pos_x + 16;
        if (player->pos_y > 2700)
        player->pos_y = player->pos_y - 16;
        if (check_in(player, convert_pos(6000, 2600),
        convert_pos(6400, 3600)) == 1)
            game->statment = 13;
    }
    if (game->statment == 13) {
        player->pos_x = player->pos_x + 16;
        if (check_in(player, convert_pos(6326, 2600),
        convert_pos(6800, 3600)) == 1) {
            player->pos_x = 2540;
            player->pos_y = 3260;
            game->statment = 2;
            player->state = 6;
        }
    }
}

void cine3(players *player, s_game *game)
{
    if (game->statment == 14) {
        player->pos_x = 9350;
        player->pos_y = 1160;
        game->statment = 2;
        player->current_mob = -1;
        player->state = 9;
        player->mob[7]->state = 3;
    }
    if (game->statment == 15) {
        if (sfClock_getElapsedTime(player->clock).microseconds > 5000000) {
            player->pos_x = 5366;
            player->pos_y = 2800;
            game->statment = 2;
        }
    }
}

void cine(players *player, s_game *game)
{
    if (player->state == 0 && game->statment == 2) {
        player->pos_y = player->pos_y - 3;
        rot_player(player, 0);
    }
    if (game->statment == 10) {
        player->pos_x = player->pos_x - 16;
        if (player->pos_y > 2700)
        player->pos_y = player->pos_y - 4;
        if (check_in(player, convert_pos(5100, 2900),
        convert_pos(5300, 3600)) == 1)
            game->statment = 11;
    }
    cine1(player, game);
    cine2(player, game);
    cine3(player, game);
}