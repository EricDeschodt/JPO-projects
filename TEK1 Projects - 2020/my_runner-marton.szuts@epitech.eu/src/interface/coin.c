/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** coin
*/

#include "runner.h"

void render_coin_interface(controll_t *s_controll)
{
    s_controll->s_interface.s_coin.clock = sfClock_create();
    s_controll->s_interface.s_coin.rect.left = 0;
    s_controll->s_interface.s_coin.rect.top = 0;
    s_controll->s_interface.s_coin.rect.width = 50;
    s_controll->s_interface.s_coin.rect.height = 50;
    s_controll->s_interface.s_coin.secconds = 0;
    s_controll->s_interface.s_coin.texture =
    sfTexture_createFromFile("sprites/coin.png", NULL);
    s_controll->s_interface.s_coin.sprite = sfSprite_create();
    sfSprite_setTexture(s_controll->s_interface.s_coin.sprite,
    s_controll->s_interface.s_coin.texture, sfTrue);
    sfSprite_setTextureRect(s_controll->s_interface.s_coin.sprite,
    s_controll->s_interface.s_coin.rect);
    sfSprite_setPosition(s_controll->s_interface.s_coin.sprite,
    (sfVector2f){50, 50});
}

void display_coin_interface(controll_t *s_controll)
{
    if (s_controll->s_interface.s_coin.secconds > 0.08) {
        move_rect_coin(&s_controll->s_interface.s_coin, 50, 300);
        sfSprite_setTextureRect(s_controll->s_interface.s_coin.sprite,
        s_controll->s_interface.s_coin.rect);
        sfClock_restart(s_controll->s_interface.s_coin.clock);
    }
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_interface.s_coin.sprite, NULL);
}