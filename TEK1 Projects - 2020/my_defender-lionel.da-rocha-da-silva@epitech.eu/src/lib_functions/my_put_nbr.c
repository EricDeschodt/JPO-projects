/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** display given number
*/

#include <stdlib.h>
#include "defender.h"

char *my_revstr(char *str)
{
    char tmp;
    int len = my_strlen(str);
    for (size_t i = 0, k = len - 1; i < k; ++i, --k) {
        tmp = str[i];
        str[i] = str[k];
        str[k] = tmp;
    }
    return str;
}

char *to_string(int nb)
{
    static char str[10] = {0};
    int i = 0;
    if (nb < 0) {
        nb *= -1;
        str[i++] = '-';
    }
    if (nb == 0)
        return "0\n";
    while (nb) {
        str[i++] = (nb % 10) + '0';
        nb = nb / 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}

void create_mob(s_game *game)
{
    char ***path = enemies_path();
    int fd = 0, k = 0;
    game->enemies = malloc(sizeof(s_wave ***) * 6);
    game->b_enemies = malloc(sizeof(s_wave ***) * 6);
    create_mob_e(game, k, path, fd);
}

void draw_mob(s_game *game)
{
    for (int i = 0; i < game->w_len[game->w_nb]; i++) {
        if (game->enemies[game->levels][game->w_nb][i]->mob->killed ==
        sfFalse) {
            sfSprite_setPosition(game->enemies[game->levels]
            [game->w_nb][i]->mob->sprite, game->enemies[game->levels]
            [game->w_nb][i]->mob->pos);
            sfRenderWindow_drawSprite(game->window, game->enemies[game->levels]
            [game->w_nb][i]->mob->sprite, NULL);
            sfRectangleShape_setPosition
            (game->enemies[game->levels][game->w_nb][i]->mob->life_bar,
            game->enemies[game->levels][game->w_nb][i]->mob->text_pos);
            sfRenderWindow_drawRectangleShape
            (game->window,
            game->enemies[game->levels][game->w_nb][i]->mob->life_bar, NULL);
        }
    }
}