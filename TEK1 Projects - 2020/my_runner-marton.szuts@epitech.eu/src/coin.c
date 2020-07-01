/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** coin
*/

#include "runner.h"

coin_t *render_coin(coin_t *s_coin, int height, int posx)
{
    coin_t *new_coin = malloc(sizeof(coin_t));
    new_coin->clock = sfClock_create();
    new_coin->rect.left = 0, new_coin->rect.top = 0;
    new_coin->rect.width = 50;
    new_coin->rect.height = 50, new_coin->secconds = 0;
    new_coin->texture = sfTexture_createFromFile("sprites/coin.png", NULL);
    new_coin->sprite = sfSprite_create();
    sfSprite_setTexture(new_coin->sprite, new_coin->texture, sfTrue);
    sfSprite_setTextureRect(new_coin->sprite, new_coin->rect);
    if (height == 2)
        new_coin->pos = (sfVector2f){posx, 780};
    else
        new_coin->pos = (sfVector2f){posx, 550};
    sfSprite_setPosition(new_coin->sprite, new_coin->pos);
    new_coin->next = s_coin;
    return (new_coin);
}

void init_coin(controll_t *s_controll)
{
    coin_t *s_coin = NULL;
    int x = 2300;
    s_controll->nb_coins = 50;
    for (int i = 0; i < s_controll->nb_coins; i++) {
        s_coin = render_coin(s_coin, 2, x);
        x += 280;
    }
    s_controll->s_coin = s_coin;
}

void display_coins(controll_t *s_controll)
{
    coin_t *temp = s_controll->s_coin;
    for (; temp != NULL;) {
        temp = draw_coin(s_controll, temp);
    }
}

coin_t *draw_coin(controll_t *s_controll, coin_t *s_coin)
{
    if (s_controll->s_game.scene == 1) {
        if (s_coin->secconds > 0.08) {
            move_rect_coin(s_coin, 50, 300);
            sfSprite_setTextureRect(s_coin->sprite, s_coin->rect);
            sfClock_restart(s_coin->clock);
        }
    }
    sfSprite_setPosition(s_coin->sprite, s_coin->pos);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_coin->sprite, NULL);
    return (move_coins(s_controll, s_coin));
}

coin_t *move_coins(controll_t *s_controll, coin_t *s_coin)
{
    coin_t *temp = s_coin;
    if (s_coin->pos.x > -700) {
        s_coin->pos.x -= 750 * s_controll->s_background.secconds *
        s_controll->s_game.speed;
        s_coin = s_coin->next;
    }
    else {
        s_coin = s_coin->next;
        free_coin(temp, s_controll);
    }
    return (s_coin);
}