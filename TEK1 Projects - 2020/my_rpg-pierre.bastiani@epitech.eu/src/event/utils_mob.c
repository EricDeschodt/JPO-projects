/*
** EPITECH PROJECT, 2020
** utils
** File description:
** mob
*/

#include "../../include/include.h"

void print_combat2(s_game *game, players *player, mobs *mob)
{
    sfRenderWindow_drawSprite(game->window, mob->life_sprit[mob->life_sacha],
    NULL);
    sfRenderWindow_drawSprite(game->window,
    mob->sprit_life_enmi[mob->life_ennemi*10/mob->life_max_enne], NULL);
    print_util(game->window, mob, player);
    print_anim(game->window, mob, player);
}

void print_combat(s_game *game, players *player, mobs *mob)
{
    sfRenderWindow_drawSprite(game->window, mob->attack, NULL);
    sfRenderWindow_drawSprite(game->window, mob->ennemi, NULL);
    sfRenderWindow_drawSprite(game->window, mob->sacha_f, NULL);
    if (player->combat == 4) {
        sfRenderWindow_drawSprite(game->window, mob->sprite_headbut, NULL);
        sfRenderWindow_drawSprite(game->window, mob->sprite_strangle, NULL);
        sfRenderWindow_drawSprite(game->window, mob->sprite_kick, NULL);
        sfRenderWindow_drawSprite(game->window, mob->sprite_punch, NULL);
    }
    if (player->combat == 3) {
        sfRenderWindow_drawSprite(game->window, mob->sprite_headbut, NULL);
        sfRenderWindow_drawSprite(game->window, mob->sprite_kick, NULL);
        sfRenderWindow_drawSprite(game->window, mob->sprite_punch, NULL);
    }
    if (player->combat == 2) {
        sfRenderWindow_drawSprite(game->window, mob->sprite_kick, NULL);
        sfRenderWindow_drawSprite(game->window, mob->sprite_punch, NULL);
    }
    print_combat2(game, player, mob);
}

void print_mob(sfRenderWindow *window, mobs *mob, players *player)
{
    if (mob->state == 0) {
        sfSprite_setPosition(mob->sprit, (sfVector2f)
        {mob->posi->x - player->pos_x, mob->posi->y - player->pos_y});
        sfRenderWindow_drawSprite(window, mob->sprit, NULL);
    }
}

void init_mob(players *player)
{
    player->mob = malloc(sizeof(mobs *) * 9);
    player->mob[0] = mob_pioche();
    player->mob[1] = mob_champ_1();
    player->mob[2] = mob_champ_2();
    player->mob[3] = mob_champ_3();
    player->mob[4] = mob_boss_one();
    player->mob[5] = mob_three_lave();
    player->mob[6] = mob_four_lave();
    player->mob[7] = mob_boss_final();
    player->mob[8] = NULL;
}