/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** update_attack
*/

#include "defender.h"

void attack_update(s_game *game, t_list *tmp, float per)
{
    if (tmp->tower[tmp->type]->is_tower == sfTrue) {
        for (int i = 0; i < game->w_len[game->w_nb]; i++) {
            attack_update4(game, tmp, i, per);
        }
    }
}

void attack_update1(s_game *game, int i)
{
    game->enemies[game->levels][game->w_nb][i]->mob->atk_time =
    sfClock_getElapsedTime(game->enemies[game->levels]
    [game->w_nb][i]->mob->atk_clock);
    if (sfTime_asSeconds(game->enemies[game->levels][game->w_nb]
    [i]->mob->atk_time) >= 0.5) {
        if (game->enemies[game->levels][game->w_nb][i]->mob->blink ==
        sfFalse) {
            sfSprite_setColor(game->enemies[game->levels][game->w_nb]
            [i]->mob->sprite, (sfColor){255, 10, 10, 100});
            game->enemies[game->levels][game->w_nb][i]->mob->blink = sfTrue;
        }
    }
}

void attack_update2(s_game *game, t_list *tmp, int i, float per)
{
    if (tmp->tower[tmp->type]->is_tower == sfTrue) {
        if (is_inRange(tmp->tower[tmp->type], game->enemies[game->levels]
        [game->w_nb][i]->mob) == 0) {
            game->enemies[game->levels][game->w_nb][i]->mob->life -=
            tmp->tower[tmp->type]->tower->atk;
            per = ((game->enemies[game->levels][game->w_nb][i]->mob->life * 50)
            / game->enemies[game->levels][game->w_nb][i]->mob->t_life);
            sfRectangleShape_setSize(game->enemies[game->levels][game->w_nb]
            [i]->mob->life_bar, (v2){per, 5});
            sfText_setString(game->enemies[game->levels][game->w_nb]
            [i]->mob->text, my_itoa(game->enemies[game->levels][game->w_nb]
            [i]->mob->life));
        }
    }
}

void attack_update3(s_game *game, int i, float per)
{
    for (t_list *temp = game->slots[game->levels]; temp != NULL;
    temp = temp->next) {
        attack_update2(game, temp, i, per);
    }
    if (game->enemies[game->levels][game->w_nb][i]->mob->blink == sfTrue) {
        sfSprite_setColor(game->enemies[game->levels][game->w_nb]
        [i]->mob->sprite, game->enemies[game->levels][game->w_nb]
        [i]->mob->color);
        game->enemies[game->levels][game->w_nb][i]->mob->blink = sfFalse;
    }
    game->enemies[game->levels][game->w_nb][i]->mob->atk_time =
    sfClock_restart(game->enemies[game->levels][game->w_nb]
    [i]->mob->atk_clock);
}

void attack_update4(s_game *game, t_list *tmp, int i, float per)
{
    if (is_inRange(tmp->tower[tmp->type], game->enemies[game->levels]
    [game->w_nb][i]->mob) == 0) {
        attack_update1(game, i);
        if (sfTime_asSeconds(game->enemies[game->levels][game->w_nb]
        [i]->mob->atk_time) >= 1) {
            attack_update3(game, i, per);
        }
    }
    else {
        sfSprite_setColor(game->enemies[game->levels][game->w_nb]
        [i]->mob->sprite, game->enemies[game->levels][game->w_nb]
        [i]->mob->color);
        game->enemies[game->levels][game->w_nb][i]->mob->blink =
        sfFalse;
    }
}