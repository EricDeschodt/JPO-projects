/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** player
*/

#include "../../include/include.h"

void init_p_sprit_up(players *player)
{
    char *filepath[] = {"assets/s_player/up1.png", "assets/s_player/up2.png",
    "assets/s_player/up3.png", NULL};
    player->text_up = malloc(sizeof(sfTexture *) * 4);
    player->sprit_up = malloc(sizeof(sfSprite *) * 4);
    for (int i = 0; i < 3; i++) {
        player->text_up[i] = sfTexture_createFromFile(filepath[i], NULL);
        player->sprit_up[i] = sfSprite_create();
        sfSprite_setTexture(player->sprit_up[i], player->text_up[i], 0);
        sfSprite_setOrigin(player->sprit_up[i], (sfVector2f){8, 16});
        sfSprite_setScale(player->sprit_up[i], (sfVector2f){6, 6});
        sfSprite_setPosition(player->sprit_up[i], (sfVector2f){960, 540});
    }
    player->text_up[3] = NULL;
    player->sprit_up[3] = NULL;
}

void init_p_sprit_left(players *player)
{
    char *filepath[] = {"assets/s_player/left1.png",
    "assets/s_player/left2.png", "assets/s_player/left3.png", NULL};
    player->text_left = malloc(sizeof(sfTexture *) * 4);
    player->sprit_left = malloc(sizeof(sfSprite *) * 4);
    for (int i = 0; i < 3; i++) {
        player->text_left[i] = sfTexture_createFromFile(filepath[i], NULL);
        player->sprit_left[i] = sfSprite_create();
        sfSprite_setTexture(player->sprit_left[i], player->text_left[i], 0);
        sfSprite_setOrigin(player->sprit_left[i], (sfVector2f){8, 16});
        sfSprite_setScale(player->sprit_left[i], (sfVector2f){6, 6});
        sfSprite_setPosition(player->sprit_left[i], (sfVector2f){960, 540});
    }
    player->text_left[3] = NULL;
    player->sprit_left[3] = NULL;
}

void init_p_sprit_right(players *player)
{
    char *filepath[] = {"assets/s_player/right1.png",
    "assets/s_player/right2.png", "assets/s_player/right3.png", NULL};
    player->text_right = malloc(sizeof(sfTexture *) * 4);
    player->sprit_right = malloc(sizeof(sfSprite *) * 4);
    for (int i = 0; i < 3; i++) {
        player->text_right[i] = sfTexture_createFromFile(filepath[i], NULL);
        player->sprit_right[i] = sfSprite_create();
        sfSprite_setTexture(player->sprit_right[i], player->text_right[i], 0);
        sfSprite_setOrigin(player->sprit_right[i], (sfVector2f){8, 16});
        sfSprite_setScale(player->sprit_right[i], (sfVector2f){6, 6});
        sfSprite_setPosition(player->sprit_right[i], (sfVector2f){960, 540});
    }
    player->text_right[3] = NULL;
    player->sprit_right[3] = NULL;
}

void init_p_sprit_down(players *player)
{
    char *filepath[] = {"assets/s_player/down1.png",
    "assets/s_player/down2.png", "assets/s_player/down3.png", NULL};
    player->text_down = malloc(sizeof(sfTexture *) * 4);
    player->sprit_down = malloc(sizeof(sfSprite *) * 4);
    for (int i = 0; i < 3; i++) {
        player->text_down[i] = sfTexture_createFromFile(filepath[i], NULL);
        player->sprit_down[i] = sfSprite_create();
        sfSprite_setTexture(player->sprit_down[i], player->text_down[i], 0);
        sfSprite_setOrigin(player->sprit_down[i], (sfVector2f){8, 16});
        sfSprite_setScale(player->sprit_down[i], (sfVector2f){6, 6});
        sfSprite_setPosition(player->sprit_down[i], (sfVector2f){960, 540});
    }
    player->text_down[3] = NULL;
    player->sprit_down[3] = NULL;
}

void init_p_sprit(players *player)
{
    init_p_sprit_up(player);
    init_p_sprit_down(player);
    init_p_sprit_left(player);
    init_p_sprit_right(player);
    player->clock = sfClock_create();
    player->rot = 0;
    player->d = 0;
}