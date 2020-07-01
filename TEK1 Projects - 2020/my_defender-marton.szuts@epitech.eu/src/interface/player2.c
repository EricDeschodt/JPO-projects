/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** player2
*/

#include "defender.h"
#include "utils.h"

int my_if(tuto_t *temp)
{
    if (temp->castle == 1 && temp->id != 0 && temp->scale.x <= 0.1)
        return (1);
    return (0);
}

void end_game(all_t *s_all)
{
    s_all->s_wave_c.round = free_mobs(s_all->s_wave_c.round);
    s_all->s_wave_c.square = free_mobs(s_all->s_wave_c.square);
    s_all->s_wave_c.triangle = free_mobs(s_all->s_wave_c.triangle);
    s_all->s_wave_c.go = 0, s_all->s_wave_c.min = 0, s_all->s_wave_c.start = 0;
    s_all->s_wave_c.strwave = strnbr(s_all->s_wave_c.min);
    update_player(s_all);
    s_all->s_wave_c.strwave = strnbr(0);
    my_strcat(s_all->s_wave_c.strwave, s_all->s_wave_c.base);
    sfText_setString(s_all->s_wave_c.text, s_all->s_wave_c.strwave);
    s_all->s_tuto = free_mobs(s_all->s_tuto);
    s_all->s_turret = free_turret(s_all->s_turret);
    s_all->s_map.s_support = free_support(s_all->s_map.s_support);
    s_all->s_game.lost_anim = 0;
    s_all->s_game.transition = 0;
    s_all->s_side_menu.draw = 0;
    s_all->s_selected.on = 0, s_all->s_player.defeat = 0;
    s_all->s_hard_arrow.stat = 1;
    s_all->s_game.pause = 0, s_all->s_game.eric = 0;
    sfSprite_setTexture(s_all->s_buttons->begin->sprite,
    s_all->s_game.locked, sfTrue);
}