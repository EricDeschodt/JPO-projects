/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** game_update
*/

#include "defender.h"

void game_init1(s_game *game)
{
    s_path tmp;
    tmp.move = 0, tmp.pos = (v2){0, 0};
    game->grid = malloc(sizeof(s_path **) * 6);
    for (int k = 0; k < 5; k++) {
        game->grid[k] = malloc(sizeof(s_path *) * 22);
        game_init3(game, tmp, k);
        game->grid[k][21] = NULL;
    }
    game->grid[5] = NULL;
    for (int i = 0; i < 5; i++) {
        game->maps[i] = NULL;
    }
}

void send_wave(void *data)
{
    s_game *g = (s_game *)data;
    int j = g->w_len[g->w_nb];
    if (g->sent == sfFalse) {
        g->w_nb++;
        j = g->w_len[g->w_nb];
        for (int i = 0; i < j; i++) {
            g->enemies[g->levels][g->w_nb][i]->mob->movetime =
            sfClock_restart(g->enemies[g->levels][g->w_nb][i]->mob->moveclock);
        }
        for (t_list *tmp = g->slots[g->levels]; tmp != NULL;
        tmp = tmp->next) {
            tmp->tower[tmp->type]->time =
            sfClock_restart(tmp->tower[tmp->type]->clock);
        }
        g->sent = sfTrue;
        g->hud->waves->w_nb++;
        update_waves(g);
    }
}

void game_init(s_game *game)
{
    game->sent = sfFalse;
    game_init1(game);
    game_init2(game);
    init_map(game);
    create_castles(game);
    init_pause(game);
    create_mob(game);
    tower_menu_init(game);
    game->gameover = create_gameover(game);
    game->hud = create_hud(game);
    game->b_hud = create_hud(game);
    game->w_button = button_create("Next wave",
        (v2){150, 800}, send_wave, "res/buttons/button-bg.png");
}

void game_update1(s_game *game)
{
    if (game->event.type == sfEvtKeyReleased && game->event.key.code ==
    sfKeyEscape) {
        if (game->g_pause.paused == sfFalse)
            game->g_pause.paused = sfTrue;
    }
    if (game->w_nb < 4) {
        if (check_dead(game) == 0)
            game->sent = sfFalse;
    }
    if (game->castles[game->levels]->life >= 70)
        sfSprite_setTexture(game->castles[game->levels]->sprite,
        game->castles[game->levels]->texture[FULL], sfTrue);
    if (game->castles[game->levels]->life >= 35 &&
    game->castles[game->levels]->life < 70)
        sfSprite_setTexture(game->castles[game->levels]->sprite,
        game->castles[game->levels]->texture[HALF], sfTrue);
    if (game->castles[game->levels]->life < 35)
        sfSprite_setTexture(game->castles[game->levels]->sprite,
        game->castles[game->levels]->texture[DESTROYED], sfTrue);
}

void kill_mobs(s_game *game, int i)
{
    if (game->enemies[game->levels][game->w_nb][i]->mob->life <= 0) {
        game->enemies[game->levels][game->w_nb][i]->mob->killed =
        sfTrue;
        game->enemies[game->levels][game->w_nb][i]->mob->dead = sfTrue;
        if (game->enemies[game->levels][game->w_nb][i]->mob->killed ==
        sfTrue && game->enemies[game->levels][game->w_nb][i]->mob->xp
        == sfFalse) {
            game->score += (game->enemies[game->levels]
            [game->w_nb][i]->mob->type * 10) + 10;
            game->hud->gold->gold += (game->enemies[game->levels]
            [game->w_nb][i]->mob->type * 10) + 100;
            update_gold(game);
            game->enemies[game->levels][game->w_nb][i]->mob->xp =
            sfTrue;
        }
    }
    game->enemies[game->levels][game->w_nb][i]->mob->text_pos.x =
    game->enemies[game->levels][game->w_nb][i]->mob->pos.x - 20;
    game->enemies[game->levels][game->w_nb][i]->mob->text_pos.y =
    game->enemies[game->levels][game->w_nb][i]->mob->pos.y - 75;
}