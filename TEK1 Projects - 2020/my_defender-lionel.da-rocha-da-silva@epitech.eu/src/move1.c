/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** move1
*/

#include "defender.h"

void move_switch(s_wave *w)
{
    switch(w->mob->moves) {
        case UP:
            sfSprite_setTexture(w->mob->sprite, w->mob->textures[0], sfTrue);
            sfSprite_setTextureRect(w->mob->sprite, w->mob->rect);
            break;
        case DOWN:
            sfSprite_setTexture(w->mob->sprite, w->mob->textures[1], sfTrue);
            sfSprite_setTextureRect(w->mob->sprite, w->mob->rect);
            break;
        case RIGHT:
            sfSprite_setTexture(w->mob->sprite, w->mob->textures[3], sfTrue);
            sfSprite_setTextureRect(w->mob->sprite, w->mob->rect);
            break;
        case LEFT:
            sfSprite_setTexture(w->mob->sprite, w->mob->textures[2], sfTrue);
            sfSprite_setTextureRect(w->mob->sprite, w->mob->rect);
            break;
    }
}

void game_init2(s_game *game)
{
    for (int i = 0; i < 5; i++) {
        game->castles[i] = NULL;
    }
    game->slots = malloc(sizeof(t_list *) * 6);
    for (int i = 0; i < 5; i++) {
        game->slots[i] = NULL;
    }
    game->b_slots = malloc(sizeof(t_list *) * 6);
    for (int i = 0; i < 5; i++) {
        game->b_slots[i] = NULL;
    }
}

void atk_castle(s_game *game, int atk)
{
    if (game->hud->life->life >= atk) {
        game->hud->life->life -= atk;
        sfRectangleShape_setSize(game->hud->life->hp,
        (v2){game->hud->life->life, 15});
    }
    else {
        game->hud->life->life -= game->hud->life->life;
        sfRectangleShape_setSize(game->hud->life->hp,
        (v2){game->hud->life->life, 15});
        game->state = GAMEOVER;
    }
}

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int check_dead(s_game *game)
{
    for (int i = 0; i < game->w_len[game->w_nb]; i++) {
        if (game->enemies[game->levels][game->w_nb][i]->mob->dead == sfFalse)
            return (-1);
    }
    return (0);
}