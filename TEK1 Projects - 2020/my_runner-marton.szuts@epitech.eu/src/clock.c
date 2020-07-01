/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** clock
*/

#include "runner.h"

void init_clocks(controll_t *s_controll)
{
    s_controll->s_runner.time =
    sfClock_getElapsedTime(s_controll->s_runner.clock);
    s_controll->s_background.time =
    sfClock_getElapsedTime(s_controll->s_background.clock);
    s_controll->s_runner.time_air =
    sfClock_getElapsedTime(s_controll->s_runner.jump_cl);
    s_controll->s_runner.secconds =
    s_controll->s_runner.time.microseconds / 1000000.0;
    s_controll->s_background.secconds =
    s_controll->s_background.time.microseconds / 1000000.0;
    s_controll->s_runner.jump_sec =
    s_controll->s_runner.time_air.microseconds / 1000000.0;
    init_clocks2(s_controll);
    init_clocks3(s_controll);
    init_coin_clocks(s_controll);
    init_monster_clock(s_controll);
}

void init_clocks2(controll_t *s_controll)
{
    s_controll->s_slide.time =
    sfClock_getElapsedTime(s_controll->s_slide.clock);
    s_controll->s_slide.secconds =
    s_controll->s_slide.time.microseconds / 1000000.0;
    s_controll->s_jelly.time =
    sfClock_getElapsedTime(s_controll->s_jelly.clock);
    s_controll->s_jelly.secconds =
    s_controll->s_jelly.time.microseconds / 1000000.0;
    s_controll->s_interface.s_coin.time =
    sfClock_getElapsedTime(s_controll->s_interface.s_coin.clock);
    s_controll->s_interface.s_coin.secconds =
    s_controll->s_interface.s_coin.time.microseconds / 1000000.0;
    s_controll->s_interface.time =
    sfClock_getElapsedTime(s_controll->s_interface.clock);
    s_controll->s_interface.seconds =
    s_controll->s_interface.time.microseconds / 1000000.0;
}

void init_clocks3(controll_t *s_controll)
{
    s_controll->s_dead.time =
    sfClock_getElapsedTime(s_controll->s_dead.clock);
    s_controll->s_dead.seconds =
    s_controll->s_dead.time.microseconds / 1000000.0;
}

void init_coin_clocks(controll_t *s_controll)
{
    coin_t *temp = s_controll->s_coin;
    while (temp != NULL) {
        temp->time = sfClock_getElapsedTime(temp->clock);
        temp->secconds = temp->time.microseconds / 1000000.0;
        temp = temp->next;
    }
}

void init_monster_clock(controll_t *s_controll)
{
    monster1_t *temp = s_controll->s_monster;
    while (temp != NULL) {
        temp->time = sfClock_getElapsedTime(temp->clock);
        temp->secconds = temp->time.microseconds / 1000000.0;
        temp = temp->next;
    }
}