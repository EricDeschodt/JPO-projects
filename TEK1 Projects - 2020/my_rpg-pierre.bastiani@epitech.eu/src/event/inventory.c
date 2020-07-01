/*
** EPITECH PROJECT, 2020
** inv
** File description:
** entory
*/

#include "../../include/include.h"

void print_inventory2(sfRenderWindow *window, players *player)
{
    if (player->inv->lvl < player->inv->xp/100) {
        player->inv->lvl = player->inv->xp/100;
        player->punch->cur = player->punch->max;
        player->kick->cur = player->kick->max;
        player->strangle->cur = player->strangle->max;
        player->headbut->cur = player->headbut->max;
        if (player->inv->lvl == 1)
            player->combat = 3;
        if (player->inv->lvl >= 2)
            player->combat = 4;
    }
    sfText_setString(player->inv->xp_txt, int_to_char(player->inv->xp));
    sfText_setString(player->inv->lvl_txt, int_to_char(player->inv->lvl));
    sfRenderWindow_drawText(window, player->inv->xp_txt, 0);
    sfRenderWindow_drawText(window, player->inv->lvl_txt, 0);
}

void print_inventory(sfRenderWindow *window, players *player)
{
    if (player->inv->pick == true)
        sfRenderWindow_drawSprite(window, player->inv->sprit_pick, NULL);
    if (player->inv->map == true)
        sfRenderWindow_drawSprite(window, player->inv->sprit_map, NULL);
    if (player->inv->key == true)
        sfRenderWindow_drawSprite(window, player->inv->sprit_key, NULL);
    if (player->inv->troph == true)
        sfRenderWindow_drawSprite(window, player->inv->sprit_troph, NULL);
    if (player->combat >= 2) {
        sfRenderWindow_drawSprite(window, player->inv->sprit_kick, NULL);
        sfRenderWindow_drawSprite(window, player->inv->sprit_punch, NULL);
    }
    if (player->combat >= 3)
        sfRenderWindow_drawSprite(window, player->inv->sprit_head, NULL);
    if (player->combat >= 4)
        sfRenderWindow_drawSprite(window, player->inv->sprit_strangle, NULL);
    sfSprite_setTexture(player->inv->xp_bar,
    player->inv->text_xp_bar[(player->inv->xp%100)/10], 0);
    sfRenderWindow_drawSprite(window, player->inv->xp_bar, NULL);
    print_inventory2(window, player);
}