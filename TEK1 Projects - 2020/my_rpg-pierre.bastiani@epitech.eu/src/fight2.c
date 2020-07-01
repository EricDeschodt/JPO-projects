/*
** EPITECH PROJECT, 2020
** fight
** File description:
** init
*/

#include "../include/include.h"

void fight_(s_game *game, mobs *mob, players *player)
{
    if ((game->mouse.x > mob->vec_punch.x && game->mouse.x <= mob->vec_punch.x + mob->rec_punch.width)
    && (game->mouse.y > mob->vec_punch.y && game->mouse.y <= mob->vec_punch.y + mob->rec_punch.height))
        check_util(mob, player, 1);
    else if ((game->mouse.x > mob->vec_kick.x && game->mouse.x <= mob->vec_kick.x + mob->rec_kick.width)
    && (game->mouse.y > mob->vec_kick.y && game->mouse.y <= mob->vec_kick.y + mob->rec_kick.height))
        check_util(mob, player, 2);
    else if ((game->mouse.x > mob->vec_headbut.x && game->mouse.x <= mob->vec_headbut.x + mob->rec_headbut.width)
    && (game->mouse.y > mob->vec_headbut.y && game->mouse.y <= mob->vec_headbut.y + mob->rec_headbut.height))
        check_util(mob, player, 3);
    else if ((game->mouse.x > mob->vec_strangle.x && game->mouse.x <= mob->vec_strangle.x + mob->rec_strangle.width)
    && (game->mouse.y > mob->vec_strangle.y && game->mouse.y <= mob->vec_strangle.y + mob->rec_strangle.height))
        check_util(mob, player, 4);
    else
        mob->statu_ennemi = 0;
}

void fight_2_(s_game *game, mobs *mob, players *player)
{
    if ((game->mouse.x > mob->vec_punch.x && game->mouse.x <= mob->vec_punch.x + mob->rec_punch.width)
    && (game->mouse.y > mob->vec_punch.y && game->mouse.y <= mob->vec_punch.y + mob->rec_punch.height))
        check_util(mob, player, 1);
    else if ((game->mouse.x > mob->vec_kick.x && game->mouse.x <= mob->vec_kick.x + mob->rec_kick.width)
    && (game->mouse.y > mob->vec_kick.y && game->mouse.y <= mob->vec_kick.y + mob->rec_kick.height))
        check_util(mob, player, 2);
    else
        mob->statu_ennemi = 0;
}

void fight_3_(s_game *game, mobs *mob, players *player)
{
    if ((game->mouse.x > mob->vec_punch.x && game->mouse.x <= mob->vec_punch.x + mob->rec_punch.width)
    && (game->mouse.y > mob->vec_punch.y && game->mouse.y <= mob->vec_punch.y + mob->rec_punch.height))
        check_util(mob, player, 1);
    else if ((game->mouse.x > mob->vec_kick.x && game->mouse.x <= mob->vec_kick.x + mob->rec_kick.width)
    && (game->mouse.y > mob->vec_kick.y && game->mouse.y <= mob->vec_kick.y + mob->rec_kick.height))
        check_util(mob, player, 2);
    else if ((game->mouse.x > mob->vec_headbut.x && game->mouse.x <= mob->vec_headbut.x + mob->rec_headbut.width)
    && (game->mouse.y > mob->vec_headbut.y && game->mouse.y <= mob->vec_headbut.y + mob->rec_headbut.height))
        check_util(mob, player, 3);
    else
        mob->statu_ennemi = 0;
}