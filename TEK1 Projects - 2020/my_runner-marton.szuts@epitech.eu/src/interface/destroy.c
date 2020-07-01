/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** destroy
*/

#include "runner.h"

void destroy_interface(controll_t *s_controll)
{
    sfText_destroy(s_controll->s_interface.coin_mult);
    sfText_destroy(s_controll->s_interface.nb_coin);
    sfFont_destroy(s_controll->font);
    sfSprite_destroy(s_controll->s_title.sprite);
    sfTexture_destroy(s_controll->s_title.texture);
    sfSprite_destroy(s_controll->s_interface.s_coin.sprite);
    sfTexture_destroy(s_controll->s_interface.s_coin.texture);
    sfClock_destroy(s_controll->s_interface.s_coin.clock);
}

void destroy_buttons(buttons_t *s_button)
{
    sfSprite_destroy(s_button->sprite);
    sfTexture_destroy(s_button->texture);
    sfTexture_destroy(s_button->texture_on);
}