/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** touch_coin
*/

#include "runner.h"

coin_t *remove_coin(controll_t *s_controll, coin_t *s_coin)
{
    coin_t *temp = s_controll->s_coin;
    if (temp->next != NULL && temp != s_coin) {
        while (temp->next != s_coin) {
            temp = temp->next;
        }
        temp->next = s_coin->next;
        destroy_coin(s_coin), free(s_coin);
        return (temp->next);
    }
    else if (s_controll->s_coin->next == NULL) {
        destroy_coin(s_coin), free(s_coin);
        s_controll->s_coin = NULL;
        return (NULL);
    }
    else {
        s_controll->s_coin = s_coin->next;
        destroy_coin(s_coin), free(s_coin);
        return (s_controll->s_coin);
    }
}

coin_t *check_coin_hitbox(coin_t *s_coin, controll_t *s_controll)
{
    float x = s_coin->pos.x, y = s_coin->pos.y;
    int x_run = s_controll->s_runner.pos.x, y_run = s_controll->s_runner.pos.y;
    if ((x >= x_run && x <= x_run + 100) && (y >= y_run && y <= y_run + 105)) {
        sfSound_play(s_controll->s_music.coin_sound);
        s_controll->s_interface.nb_coin_int += 1;
        free_previous_txt(s_controll->s_interface.strcoin);
        s_controll->s_interface.strcoin =
        my_put_strnbr(s_controll->s_interface.nb_coin_int);
        sfText_setString(s_controll->s_interface.nb_coin,
        s_controll->s_interface.strcoin);
        return (remove_coin(s_controll, s_coin));
    }
    s_coin = s_coin->next;
    return (s_coin);
}

void touch_coin(controll_t *s_controll)
{
    coin_t *temp = s_controll->s_coin;
    while (temp != NULL) {
        temp = check_coin_hitbox(temp, s_controll);
    }
}