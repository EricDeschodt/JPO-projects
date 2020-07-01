/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** pos_init
*/

#include "my.h"

void third_init_dog_duck(pos_t *pos)
{
    pos->pos_score.x = 590;
    pos->pos_score.y = 535;
    pos->pos_perfect.x = 310;
    pos->pos_perfect.y = 175;
}

void second_init_dog_duck(pos_t *pos)
{
    pos->pos_menu_pause_text.x = 370;
    pos->pos_menu_pause_text.y = 100;
    pos->pos_duck2.x = -120;
    pos->pos_duck2.y = 50;
    pos->pos_duck_rev2.x = 850;
    pos->pos_duck_rev2.y = 50;
    pos->pos_duck_bot2.x = 400;
    pos->pos_duck_bot2.y = 450;
    pos->pos_round_text.x = 350;
    pos->pos_round_text.y = 100;
    pos->pos_round_text2.x = 450;
    pos->pos_round_text2.y = 92;
    pos->pos_overlay.x = 125;
    pos->pos_overlay.y = 510;
    pos->pos_round_nb.x = 180;
    pos->pos_round_nb.y = 500;
    pos->pos_ammo.x = 140;
    pos->pos_ammo.y = 546;
    third_init_dog_duck(pos);
}

void first_init_dog_duck(pos_t *pos)
{
    pos->pos_duck.x = -120;
    pos->pos_duck.y = 50;
    pos->pos_dog.x = 15;
    pos->pos_dog.y = 420;
    pos->pos_duck_rev.x = 850;
    pos->pos_duck_rev.y = 50;
    pos->pos_duck_bot.x = 400;
    pos->pos_duck_bot.y = 450;
    pos->pos_main_menu.x = 50;
    pos->pos_main_menu.y = 25;
    pos->pos_menu_arrow.x = 45;
    pos->pos_menu_arrow.y = 340;
    pos->pos_menu_dog.x = 500;
    pos->pos_menu_dog.y = 370;
    pos->pos_menu_score.x = 475;
    pos->pos_menu_score.y = 476;
    pos->pos_menu_dog_pause.x = 370;
    pos->pos_menu_dog_pause.y = 500;
    second_init_dog_duck(pos);
}
