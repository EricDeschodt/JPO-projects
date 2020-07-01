/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** player
*/

#include "defender.h"
#include "utils.h"

void init_play_texts(all_t *s_all)
{
    s_all->s_player.txt_life = sfText_create();
    s_all->s_player.txt_money = sfText_create();
    sfText_setFont(s_all->s_player.txt_life, s_all->s_game.font);
    sfText_setFont(s_all->s_player.txt_money, s_all->s_game.font);
    sfText_setString(s_all->s_player.txt_life, "20");
    sfText_setString(s_all->s_player.txt_money, "150");
    sfText_setPosition(s_all->s_player.txt_life, (sfVector2f){350, 30});
    sfText_setPosition(s_all->s_player.txt_money, (sfVector2f){470, 30});
    s_all->s_player.strlife = NULL, s_all->s_player.strmoney = NULL;
}

void init_player_infos(all_t *s_all)
{
    s_all->s_player.sprite_h = sfSprite_create();
    s_all->s_player.sprite_m = sfSprite_create();
    s_all->s_player.texture_h =
    sfTexture_createFromFile("sprites/life.png", NULL);
    s_all->s_player.texture_m =
    sfTexture_createFromFile("sprites/money.png", NULL);
    sfSprite_setTexture(s_all->s_player.sprite_h,
    s_all->s_player.texture_h, sfTrue);
    sfSprite_setTexture(s_all->s_player.sprite_m,
    s_all->s_player.texture_m, sfTrue);
    s_all->s_player.life = 20, s_all->s_player.money = 150;
    sfSprite_setPosition(s_all->s_player.sprite_h, (sfVector2f){300, 30});
    sfSprite_setPosition(s_all->s_player.sprite_m, (sfVector2f){420, 30});
    s_all->s_player.defeat = 0;
    init_play_texts(s_all);
}

void display_player_info(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_player.sprite_h, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_player.sprite_m, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_player.txt_life, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_player.txt_money, NULL);
}

void get_money_by_mobs(all_t *s_all)
{
    if (s_all->s_player.strmoney != NULL)
        free(s_all->s_player.strmoney);
    s_all->s_player.money += 5;
    s_all->s_stats.coins += 5;
    s_all->s_stats.killed += 1;
    s_all->s_player.strmoney = strnbr(s_all->s_player.money);
    sfText_setString(s_all->s_player.txt_money, s_all->s_player.strmoney);
}

void losing_life(all_t *s_all)
{
    if (s_all->s_player.life != 0) {
        if (s_all->s_player.strlife != NULL)
            free(s_all->s_player.strlife);
        s_all->s_player.life -= 2;
        s_all->s_stats.passed += 1;
        s_all->s_player.strlife = strnbr(s_all->s_player.life);
        sfText_setString(s_all->s_player.txt_life, s_all->s_player.strlife);
    }
}