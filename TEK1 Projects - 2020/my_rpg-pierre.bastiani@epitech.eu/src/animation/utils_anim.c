/*
** EPITECH PROJECT, 2020
** utils
** File description:
** anim
*/

#include "../../include/include.h"

void set_print(sfRenderWindow *window, sfSprite *sprite, sfTexture *texture)
{
    sfSprite_setTexture(sprite, texture, 0);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void print_anim(sfRenderWindow *window, mobs *mob, players *player)
{
    if (sfClock_getElapsedTime(mob->clock_attaque).microseconds > 1000000)
        return;
    player->ani->d = (player->ani->d != 22) ? player->ani->d + 1: 0;
    player->ani->i = (player->ani->i != 22) ? player->ani->i + 1:0;
    if (player->ani->text_enem[player->ani->i] == NULL
    || player->ani->text_punch[player->ani->d] == NULL) return;
    set_print(window, player->ani->sprit_enem,
    player->ani->text_enem[player->ani->i]);
    if (mob->statu_ennemi == 1)
        set_print(window, player->ani->sprit_punch,
        player->ani->text_punch[player->ani->d]);
    if (mob->statu_ennemi == 2)
        set_print(window, player->ani->sprit_punch,
        player->ani->text_kick[player->ani->d]);
    if (mob->statu_ennemi == 3)
        set_print(window, player->ani->sprit_punch,
        player->ani->text_head[player->ani->d]);
    if (mob->statu_ennemi == 4)
        set_print(window, player->ani->sprit_punch,
        player->ani->text_strangle[player->ani->d]);
}

void init_texture_anim2(players *player, char **file)
{
    for (int i = 0; i < 23; i++)
        player->ani->text_head[i] = sfTexture_createFromFile(file[i], NULL);
    for (int i = 0; i < 23; i++)
        player->ani->text_enem[i] = sfTexture_createFromFile(file[i], NULL);
    player->ani->text_enem[23] = player->ani->text_head[23] = NULL;
    player->ani->text_kick[23] = player->ani->text_punch[23] = NULL;
    player->ani->text_strangle[23] = NULL;
}

void init_texture_anim(players *player)
{
    player->ani->text_strangle = malloc(sizeof(sfTexture *) * 24);
    player->ani->text_enem = malloc(sizeof(sfTexture *) * 24);
    player->ani->d = player->ani->i = 0;
    char *file[] = {"assets/anim_p/0.png", "assets/anim_p/1.png",
    "assets/anim_p/2.png", "assets/anim_p/3.png", "assets/anim_p/4.png",
    "assets/anim_p/5.png", "assets/anim_p/6.png", "assets/anim_p/7.png",
    "assets/anim_p/8.png", "assets/anim_p/9.png", "assets/anim_p/10.png",
    "assets/anim_p/11.png", "assets/anim_p/12.png", "assets/anim_p/13.png",
    "assets/anim_p/14.png", "assets/anim_p/15.png", "assets/anim_p/16.png",
    "assets/anim_p/16.png", "assets/anim_p/17.png", "assets/anim_p/18.png",
    "assets/anim_p/19.png", "assets/anim_p/20.png", "assets/anim_p/21.png",
    NULL};
    for (int i = 0; i < 23; i++)
        player->ani->text_punch[i] = sfTexture_createFromFile(file[i], NULL);
    for (int i = 0; i < 23; i++)
        player->ani->text_kick[i] = sfTexture_createFromFile(file[i], NULL);
    for (int i = 0; i < 23; i++)
        player->ani->text_strangle[i] = sfTexture_createFromFile(file[i], NULL);
    init_texture_anim2(player, file);
}

void init_animation(players *player)
{
    player->ani = malloc(sizeof(anim));
    player->ani->sprit_head = sfSprite_create();
    sfSprite_setPosition(player->ani->sprit_head, (sfVector2f){1020, 220});
    sfSprite_setScale(player->ani->sprit_head, (sfVector2f){3, 3});
    player->ani->sprit_kick = sfSprite_create();
    sfSprite_setPosition(player->ani->sprit_kick, (sfVector2f){1020, 220});
    sfSprite_setScale(player->ani->sprit_kick, (sfVector2f){3, 3});
    player->ani->sprit_strangle = sfSprite_create();
    sfSprite_setPosition(player->ani->sprit_strangle, (sfVector2f){1020, 220});
    sfSprite_setScale(player->ani->sprit_strangle, (sfVector2f){3, 3});
    player->ani->sprit_punch = sfSprite_create();
    sfSprite_setPosition(player->ani->sprit_punch, (sfVector2f){1020, 220});
    sfSprite_setScale(player->ani->sprit_punch, (sfVector2f){3, 3});
    player->ani->sprit_enem = sfSprite_create();
    sfSprite_setPosition(player->ani->sprit_enem, (sfVector2f){270, 620});
    sfSprite_setScale(player->ani->sprit_enem, (sfVector2f){3, 3});
    player->ani->text_head = malloc(sizeof(sfTexture *) * 24);
    player->ani->text_kick = malloc(sizeof(sfTexture *) * 24);
    player->ani->text_punch = malloc(sizeof(sfTexture *) * 24);
    init_texture_anim(player);
}