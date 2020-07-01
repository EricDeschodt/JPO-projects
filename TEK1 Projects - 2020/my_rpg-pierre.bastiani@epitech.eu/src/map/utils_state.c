/*
** EPITECH PROJECT, 2020
** utils
** File description:
** state
*/

#include "../../include/include.h"

pos *convert_pos(int x, int y)
{
    pos *p = malloc(sizeof(pos));
    p->x = x;
    p->y = y;
    return (p);
}

int check_in(players *player, pos *a, pos *b)
{
    pos *p = pos_player(player);
    if (p->x > a->x && p->y > a->y && p->x < b->x
    && p->y < b->y)
        return (1);
    free(a);
    free(b);
    return (0);
}

void get_state_pnj(players *player, s_game *game)
{
    for (int i = 0; player->pnj[i] != NULL; i++) {
        if (check_in(player, convert_pos(player->pnj[i]->posi->x - 300,
        player->pnj[i]->posi->y - 300), convert_pos(player->pnj[i]->posi->x
        + 300, player->pnj[i]->posi->y + 300)) == 1 && player->state >=
        player->pnj[i]->segment) 
        player->pnj[i]->state = 1;
    }
    if (check_in(player, convert_pos(player->pnj[10]->posi->x - 300,
        player->pnj[10]->posi->y - 300), convert_pos(player->pnj[10]->posi->x
        + 300, player->pnj[10]->posi->y + 300)) == 1 && player->state == 1)
        player->state = 2;
    if (player->pnj[6]->state == 2 && player->state == 3)
        player->state = 4;
    if (player->pnj[17]->state == 2 && player ->state == 9)
        player->state = 10;
    if (player->pnj[20]->state == 2 && player ->state == 10)
        player->state = 11;
    if (player->pnj[22]->state == 2) {
        player->state = 12;
        game->statment = 16;
    }
}

void get_status_mob(players *player, s_game *game)
{
    if (player->mob[0]->state == 2 && player->state == 2) {
        player->inv->pick = true;
        player->state = 3;
    }
    if (player->mob[4]->state == 2 && player->state == 4) {
        player->inv->map = true;
        player->state = 5;
        game->statment = 10;
    }
    if (player->mob[2]->state == 2 && player->state == 7) {
        player->inv->key = true;
        player->state = 6;
        game->statment = 12;
    }
    if (player->mob[5]->state == 2 && player->mob[6]->state == 2)
        player->state = 8;
    if (player->mob[7]->state == 2 && player->state != 9) {
        player->state = 9;
        game->statment = 14;
    }
}

void get_status(players *player, s_game *game)
{
    for (int i = 0; player->mob[i] != NULL; i++) {
        if (check_in(player, convert_pos(player->mob[i]->posi->x - 300,
        player->mob[i]->posi->y - 300), convert_pos(player->mob[i]->posi->x
        + 300, player->mob[i]->posi->y + 300)) == 1 && player->mob[i]->state
        != 2 && player->state >= player->mob[i]->segment &&
        game->statment == 2) {
            player->mob[i]->state = 1;
            player->current_mob = i;
            sfMusic_pause(game->Music_game);
            game->statment = 6;
        }
    }
    get_status_mob(player, game);
    get_state_pnj(player, game);
    if (game->statment != 2) return;
    if (player->state == 0 && check_in(player,
    convert_pos(6000, 2750), convert_pos(6800, 3200)) == 1)
        player->state = 1;
}