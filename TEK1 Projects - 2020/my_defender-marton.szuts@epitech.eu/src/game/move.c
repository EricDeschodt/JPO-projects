/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** move
*/

#include "utils.h"
#include "defender.h"

void move_up(tuto_t *s_balls, int len, all_t *s_all)
{
    if (s_all->s_game.pause == 1) {
        sfClock_restart(s_balls->clock);
        return;
    } sfSprite_setRotation(s_balls->sprite, 180);
    if (s_balls->increment > 0) {
        s_balls->pos.y -= s_balls->speed * s_balls->seconds * 72;
        s_balls->increment -= s_balls->speed * s_balls->seconds * 72;
    } else {
        s_balls->previous = 'U';
        s_balls->map_pos -= len;
        s_balls->increment = 120;
    } sfClock_restart(s_balls->clock);
    if (s_balls->map_pos == s_all->s_map.castle) {
        s_balls->state = -1, s_balls->castle = 1;
        if (s_all->s_settings->sound == 1 && s_balls->id != 0)
            sfSound_play(s_all->s_sounds.reached);
    }
}

void move_down(tuto_t *s_balls, int len, all_t *s_all)
{
    if (s_all->s_game.pause == 1) {
        sfClock_restart(s_balls->clock);
        return;
    } sfSprite_setRotation(s_balls->sprite, 360);
    if (s_balls->increment > 0) {
        s_balls->pos.y += s_balls->speed * s_balls->seconds * 72;
        s_balls->increment -= s_balls->speed * s_balls->seconds * 72;
    } else {
        s_balls->previous = 'D';
        s_balls->map_pos += len;
        s_balls->increment = 120;
    } sfClock_restart(s_balls->clock);
    if (s_balls->map_pos == s_all->s_map.castle) {
        s_balls->state = -1, s_balls->castle = 1;
        if (s_all->s_settings->sound == 1 && s_balls->id != 0)
            sfSound_play(s_all->s_sounds.reached);
    }
}

void move_left(tuto_t *s_balls, all_t *s_all)
{
    if (s_all->s_game.pause == 1) {
        sfClock_restart(s_balls->clock);
        return;
    } sfSprite_setRotation(s_balls->sprite, 90);
    if (s_balls->increment > 0) {
        s_balls->pos.x -= s_balls->speed * s_balls->seconds * 72;
        s_balls->increment -= s_balls->speed * s_balls->seconds * 72;
    } else {
        s_balls->previous = 'L';
        s_balls->map_pos -= 1;
        s_balls->increment = 120;
    } sfClock_restart(s_balls->clock);
    if (s_balls->map_pos == s_all->s_map.castle) {
        s_balls->state = -1, s_balls->castle = 1;
        if (s_all->s_settings->sound == 1 && s_balls->id != 0)
            sfSound_play(s_all->s_sounds.reached);
    }
}

void move_right(tuto_t *s_balls, all_t *s_all)
{
    if (s_all->s_game.pause == 1) {
        sfClock_restart(s_balls->clock);
        return;
    } sfSprite_setRotation(s_balls->sprite, 270);
    if (s_balls->increment > 0) {
        s_balls->pos.x += s_balls->speed * s_balls->seconds * 72;
        s_balls->increment -= s_balls->speed * s_balls->seconds * 72;
    } else {
        s_balls->previous = 'R';
        s_balls->map_pos += 1;
        s_balls->increment = 120;
    }
    sfClock_restart(s_balls->clock);
    if (s_balls->map_pos == s_all->s_map.castle) {
        s_balls->state = -1, s_balls->castle = 1;
        if (s_all->s_settings->sound == 1 && s_balls->id != 0)
            sfSound_play(s_all->s_sounds.reached);
    }
}