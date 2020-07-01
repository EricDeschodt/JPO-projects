/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** move
*/

#include "defender.h"

void run(s_game *game, int idx, int t)
{
    s_wave *w = game->enemies[game->levels][idx][t];
    w->mob->time = sfClock_getElapsedTime(w->mob->clock);
    w->mob->seconds = w->mob->time.microseconds / 1000000.0;
    if (w->mob->seconds > 0.1) {
        if (w->mob->rect.left < 180)
            w->mob->rect.left += 60;
        else
            w->mob->rect.left = 0;
        sfClock_restart(w->mob->clock);
    }
    w->mob->movetime = sfClock_restart(w->mob->moveclock);
    move(game, idx, t);
    sfSprite_setTextureRect(w->mob->sprite, w->mob->rect);
}

void move_right_left(s_game *game, sfVector2i pos, int idx, int t)
{
    s_wave *w = game->enemies[game->levels][idx][t];
    if (w->mob->moves == RIGHT) {
        if (w->mob->pos.x < w->grid[pos.y][pos.x + 1].pos.x)
            w->mob->pos.x += w->mob->speed *
            sfTime_asMilliseconds(w->mob->movetime);
        else {
            w->mob->x++;
            w->grid[pos.y][pos.x].move = PREV;
            return;
        }
    } if (w->mob->moves == LEFT) {
        if (w->mob->pos.x > w->grid[pos.y][pos.x - 1].pos.x)
            w->mob->pos.x -= w->mob->speed *
            sfTime_asMilliseconds(w->mob->movetime);
        else {
            w->mob->x--;
            w->grid[pos.y][pos.x].move = PREV;
            return;
        }
    }
}

void check_options(s_game *game, int idx, int t)
{
    s_wave *w = game->enemies[game->levels][idx][t];
    sfVector2i pos = {w->mob->x, w->mob->y};
    move_right_left(game, pos, idx, t);
    if (w->mob->moves == UP) {
        if (w->mob->pos.y > w->grid[pos.y - 1][pos.x].pos.y)
            w->mob->pos.y -= w->mob->speed *
            sfTime_asMilliseconds(w->mob->movetime);
        else {
            w->mob->y--, w->grid[pos.y][pos.x].move = PREV;
            return;
        }
    } if (w->mob->moves == DOWN) {
        if (w->mob->pos.y < w->grid[pos.y + 1][pos.x].pos.y)
            w->mob->pos.y += w->mob->speed *
            sfTime_asMilliseconds(w->mob->movetime);
        else {
            w->mob->y++, w->grid[pos.y][pos.x].move = PREV;
            return;
        }
    }
}

e_move check_pos(s_game *game, int idx, int t)
{
    s_wave *w = game->enemies[game->levels][idx][t];
    sfVector2i pos = {w->mob->x, w->mob->y};
    if (w->grid[pos.y][pos.x + 1].move == NEXT) {
        return (RIGHT);
    }
    if (w->grid[pos.y][pos.x - 1].move == NEXT) {
        return (LEFT);
    }
    if (w->grid[pos.y - 1][pos.x].move == NEXT) {
        return (UP);
    }
    if (w->grid[pos.y + 1][pos.x].move == NEXT) {
        return (DOWN);
    }
    return (RIGHT);
}

void move(s_game *game, int idx, int t)
{
    s_wave *w = game->enemies[game->levels][idx][t];
    if (w->mob->pos.x < 24)
        w->mob->pos.x += w->mob->speed *
        sfTime_asMilliseconds(w->mob->movetime);
    else if (w->mob->pos.x < 1720 && w->mob->pos.x >= 24) {
        check_options(game, idx, t);
        w->mob->moves = check_pos(game, idx, t);
        move_switch(w);
    }
    if (w->mob->pos.x >= 1710 && w->mob->pos.x < 2080) {
        if (w->mob->attacked == sfFalse && w->mob->killed == sfFalse) {
            atk_castle(game, w->mob->atk);
            w->mob->attacked = sfTrue;
        } w->mob->pos.x += w->mob->speed *
        sfTime_asMilliseconds(w->mob->movetime);
    }
    else if (w->mob->pos.x >= 2080) {
        w->mob->dead = sfTrue;
    }
}
