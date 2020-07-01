/*
** EPITECH PROJECT, 2020
** print
** File description:
** map
*/

#include "../../include/include.h"

void rot_player(players *player, int rot)
{
    if (sfClock_getElapsedTime(player->clock).microseconds > 250000) {
        player->d = (player->d < 2) ? player->d + 1: 0;
        sfClock_restart(player->clock);
    }
    player->rot = rot;
}

void print_player(sfRenderWindow *window, players *player)
{
    if (player->rot == 0)
        sfRenderWindow_drawSprite(window, player->sprit_up[player->d], NULL);
    if (player->rot == 1)
        sfRenderWindow_drawSprite(window, player->sprit_down[player->d], NULL);
    if (player->rot == 2)
        sfRenderWindow_drawSprite(window, player->sprit_left[player->d], NULL);
    if (player->rot == 3)
        sfRenderWindow_drawSprite(window, player->sprit_right[player->d], NULL);
}

players *init_player2(players *player)
{
    init_charg(player);
    init_inventory(player);
    init_p_sprit(player);
    init_nb_util(player);
    init_animation(player);
    player->text_end = sfTexture_createFromFile("assets/end.png", NULL);
    player->sprit_end = sfSprite_create();
    sfSprite_setTexture(player->sprit_end, player->text_end, 0);
    return (player);
}

players *init_player(void)
{
    players *player = malloc(sizeof(players));
    player->loading =
    sfMusic_createFromFile("assets/assets_fight/menu/sound/loading.ogg");
    sfMusic_play(player->loading);
    player->pos_x = 5366;
    player->pos_y = 3800;
    player->state = 0;
    player->text_back = sfTexture_createFromFile("assets/load.png", NULL);
    player->sprit_back = sfSprite_create();
    player->move_player = sfClock_create();
    player->combat = 2;
    player->current_mob = -1;
    player->text_lose = sfTexture_createFromFile("assets/lose.png", NULL);
    player->sprit_lose = sfSprite_create();
    sfSprite_setTexture(player->sprit_lose, player->text_lose, 0);
    return (init_player2(player));
}

pos *pos_player(players *player)
{
    pos *p = malloc(sizeof(pos));
    p->x = player->pos_x + 928;
    p->y = player->pos_y + 512;
    return (p);
}