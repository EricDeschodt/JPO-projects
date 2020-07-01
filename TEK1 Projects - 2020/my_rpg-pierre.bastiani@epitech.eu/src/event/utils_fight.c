/*
** EPITECH PROJECT, 2020
** utils
** File description:
** life
*/

#include "include.h"

void init_life_ennemi(mobs *mob)
{
    char *filepath[] = {"assets/assets_fight/life/0.png",
    "assets/assets_fight/life/1.png", "assets/assets_fight/life/2.png",
    "assets/assets_fight/life/3.png", "assets/assets_fight/life/4.png",
    "assets/assets_fight/life/5.png", "assets/assets_fight/life/6.png",
    "assets/assets_fight/life/7.png", "assets/assets_fight/life/8.png",
    "assets/assets_fight/life/9.png", "assets/assets_fight/life/10.png", NULL};
    mob->vect_life_enmi = (sfVector2f){1010, 180};
    mob->text_life_enmi = malloc(sizeof(sfTexture *) * 12);
    mob->sprit_life_enmi = malloc(sizeof(sfSprite *) * 12);
    for (int i = 0; i < 11; i++) {
        mob->text_life_enmi[i] = sfTexture_createFromFile(filepath[i], NULL);
        mob->sprit_life_enmi[i] = sfSprite_create();
        sfSprite_setTexture(mob->sprit_life_enmi[i], mob->text_life_enmi[i], 0);
        sfSprite_setPosition(mob->sprit_life_enmi[i], mob->vect_life_enmi);
    }
    mob->text_life_enmi[11] = NULL;
    mob->sprit_life_enmi[11] = NULL;
}

void init_life(mobs *mob)
{
    char *filepath[] = {"assets/assets_fight/life/0.png",
    "assets/assets_fight/life/1.png", "assets/assets_fight/life/2.png",
    "assets/assets_fight/life/3.png", "assets/assets_fight/life/4.png",
    "assets/assets_fight/life/5.png", "assets/assets_fight/life/6.png",
    "assets/assets_fight/life/7.png", "assets/assets_fight/life/8.png",
    "assets/assets_fight/life/9.png", "assets/assets_fight/life/10.png", NULL};
    mob->vect_life = (sfVector2f){280, 500};
    mob->life_text = malloc(sizeof(sfTexture *) * 12);
    mob->life_sprit = malloc(sizeof(sfSprite *) * 12);
    for (int i = 0; i < 11; i++) {
        mob->life_text[i] = sfTexture_createFromFile(filepath[i], NULL);
        mob->life_sprit[i] = sfSprite_create();
        sfSprite_setTexture(mob->life_sprit[i], mob->life_text[i], 0);
        sfSprite_setPosition(mob->life_sprit[i], mob->vect_life);
    }
    mob->life_text[11] = NULL;
    mob->life_sprit[11] = NULL;
    init_life_ennemi(mob);
}

void init_fight2(mobs *mob)
{
    mob->rec_headbut = (sfIntRect){0, 0, 328, 57};
    mob->rec_strangle = (sfIntRect){0, 0, 328, 57};
    mob->rec_punch = (sfIntRect){0, 0, 328, 57};
    mob->rec_kick = (sfIntRect){0, 0, 328, 57};
    sfSprite_setTextureRect(mob->sprite_headbut, mob->rec_headbut);
    sfSprite_setTextureRect(mob->sprite_strangle, mob->rec_strangle);
    sfSprite_setTextureRect(mob->sprite_kick, mob->rec_kick);
    sfSprite_setTextureRect(mob->sprite_punch, mob->rec_punch);
    mob->text_win = sfTexture_createFromFile("assets/win_fight.png", NULL);
    mob->sprit_win = sfSprite_create();
    sfSprite_setTexture(mob->sprit_win, mob->text_win, 0);
    mob->txt_win = sfText_create();
    mob->font = sfFont_createFromFile("assets/font2.ttf");
    sfText_setFont(mob->txt_win, mob->font);
    sfText_setPosition(mob->txt_win, (sfVector2f){200, 300});
    init_util_text(mob);
}

void init_fight(mobs *mob)
{
    mob->life_sacha = 10;
    mob->statu_ennemi = 0;
    mob->clock_attaque = sfClock_create();
    init_life(mob);
    mob->vec_kick = (sfVector2f){1490, 797};
    mob->vec_punch = (sfVector2f){1490, 730};
    mob->vec_headbut = (sfVector2f){1490, 874};
    mob->vec_strangle = (sfVector2f){1490, 949};
    mob->sprite_headbut =
    sprite_creator("assets/assets_fight/attack/headbutt.png");
    mob->sprite_strangle =
    sprite_creator("assets/assets_fight/attack/strangle.png");
    mob->sprite_punch = sprite_creator("assets/assets_fight/attack/punch.png");
    mob->sprite_kick = sprite_creator("assets/assets_fight/attack/kick.png");
    sfSprite_setPosition(mob->sprite_headbut, mob->vec_headbut);
    sfSprite_setPosition(mob->sprite_strangle, mob->vec_strangle);
    sfSprite_setPosition(mob->sprite_kick, mob->vec_kick);
    sfSprite_setPosition(mob->sprite_punch, mob->vec_punch);
    init_fight2(mob);
}