/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Setting up music game ux sound
*/

#include "../../include/settings.h"
#include "../../include/elements.h"

void setting_update_game_up(element_t *e)
{
    e->game->volume += 10;
    e->game->volume = (int) check_volume_value((float) e->game->volume, 100);
    e->setting->t_volume += 10;
    e->setting->t_volume = (int)
                check_volume_value((float) e->setting->t_volume, 100);
    sfText_setString(e->setting->tnb->text,
                        int_to_str(e->setting->t_str, e->setting->t_volume));
}

void setting_update_game_down(element_t *e)
{
    e->game->volume -= 10;
    e->game->volume = (int) check_volume_value((float) e->game->volume, 100);
    e->setting->t_volume -= 10;
    e->setting->t_volume = (int)
                check_volume_value((float) e->setting->t_volume, 100);
    sfText_setString(e->setting->tnb->text,
                        int_to_str(e->setting->t_str, e->setting->t_volume));
}