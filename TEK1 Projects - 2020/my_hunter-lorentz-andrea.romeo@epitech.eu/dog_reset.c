/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** dog_reset
*/

#include "my.h"

void dog_if_atoi(all_t *all)
{
    if (my_atoi(all->write.score) > my_atoi(open_read()))
        open_write(all->write.score);
}

void dog_reset4(all_t *all)
{
    if (all->my_int.spawn_count >= 8 && all->my_int.game_mode == 1) {
        if (all->rect.red_duck.width < 280) {
            dog_if_atoi(all);
            all->my_int.main_menu = 1;
            all->my_int.begin = 0;
        }
        else {
            all->my_int.perfect = 0;
            all->my_int.end_round = 1;
            all->my_int.round_count++;
            all->write.round_count_text = my_put_nbr(all->my_int.round_count,
                all->write.round_count_text);
            sfText_setString(all->write.text4, all->write.round_count_text);
            sfText_setString(all->write.text5, all->write.round_count_text);
        }
    }
}

void dog_reset3(all_t *all)
{
    if (all->my_int.spawn_count > 8 && all->my_int.game_mode == 0) {
        if (all->rect.red_duck.width < 280) {
            dog_if_atoi(all);
            all->my_int.main_menu = 1;
            all->my_int.begin = 0;
        }
        else {
            all->my_int.perfect = 0;
            all->my_int.end_round = 1;
            all->my_int.round_count++;
            all->write.round_count_text = my_put_nbr(all->my_int.round_count,
                all->write.round_count_text);
            sfText_setString(all->write.text4, all->write.round_count_text);
            sfText_setString(all->write.text5, all->write.round_count_text);
        }
    }
}

void dog_reset2(all_t *all)
{
    all->rect.ammo_rect.width = 54;
    if (all->my_int.game_mode == 1)
        all->my_int.spawn_count += 2;
    else
        all->my_int.spawn_count += 1;
    all->my_int.ammo_left = 3;
    sfSprite_setTextureRect(all->sprite2.ammo, all->rect.ammo_rect);
}

void dog_reset(all_t *all)
{
    if (all->my_int.dog_clock >= 60) {
        all->my_int.duck_spawn1 = 0;
        all->my_int.duck_spawn2 = 0;
        all->my_int.dog_clock = 0;
        all->my_int.laugh_dog_top = 0;
        all->my_int.dog_sound = 0;
        all->my_int.dog_clock2 = 0;
        all->my_int.duck_shoot = 0;
        dog_reset3(all);
        dog_reset4(all);
        dog_reset2(all);
        dog_laugh_reset_duck(all);
    }
}