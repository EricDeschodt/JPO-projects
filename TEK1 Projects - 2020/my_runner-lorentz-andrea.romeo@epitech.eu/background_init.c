/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** background_init
*/

#include "my.h"

void set_sprite_background(background_t *sprite, background_text_t *texture,
    background2_t *sprite2)
{
    sfSprite_setTexture(sprite->background1, texture->background_text1, sfTrue);
    sfSprite_setTexture(sprite->background1_2, texture->background_text1_2,
        sfTrue);
    sfSprite_setTexture(sprite->background2, texture->background_text2, sfTrue);
    sfSprite_setTexture(sprite->background3, texture->background_text3, sfTrue);
    sfSprite_setTexture(sprite->background4, texture->background_text4, sfTrue);
    sfSprite_setTexture(sprite->background5, texture->background_text5, sfTrue);
    sfSprite_setTexture(sprite->background6, texture->background_text6, sfTrue);
    sfSprite_setTexture(sprite->background7, texture->background_text7, sfTrue);
    sfSprite_setTexture(sprite2->background2_1, texture->background_text1,
        sfTrue), sfSprite_setTexture(sprite2->background2_1_2,
            texture->background_text1_2, sfTrue);
    sfSprite_setTexture(sprite2->background2_2, texture->background_text2,
        sfTrue);
    sfSprite_setTexture(sprite2->background2_3, texture->background_text3,
        sfTrue);
    sfSprite_setTexture(sprite2->background2_4, texture->background_text4,
        sfTrue);
    sfSprite_setTexture(sprite2->background2_5, texture->background_text5,
        sfTrue);
}

void background_sprite_init(background_t *sprite, background2_t *sprite2)
{
    sprite->background1 = sfSprite_create();
    sprite->background1_2 = sfSprite_create();
    sprite->background2 = sfSprite_create();
    sprite->background3 = sfSprite_create();
    sprite->background4 = sfSprite_create();
    sprite->background5 = sfSprite_create();
    sprite->background6 = sfSprite_create();
    sprite->background7 = sfSprite_create();
    sprite2->background2_1 = sfSprite_create();
    sprite2->background2_1_2 = sfSprite_create();
    sprite2->background2_2 = sfSprite_create();
    sprite2->background2_3 = sfSprite_create();
    sprite2->background2_4 = sfSprite_create();
    sprite2->background2_5 = sfSprite_create();
}

void background_texture_init(background_text_t *texture)
{
    texture->background_text1 =
        sfTexture_createFromFile("background/layer1.png", NULL);
    texture->background_text1_2 =
        sfTexture_createFromFile("background/layer1_2.png", NULL);
    texture->background_text2 =
        sfTexture_createFromFile("background/layer2.png", NULL);
    texture->background_text3 =
        sfTexture_createFromFile("background/layer3.png", NULL);
    texture->background_text4 =
        sfTexture_createFromFile("background/layer4.png", NULL);
    texture->background_text5 =
        sfTexture_createFromFile("background/layer5.png", NULL);
    texture->background_text6 =
        sfTexture_createFromFile("background/layer6.png", NULL);
    texture->background_text7 =
        sfTexture_createFromFile("background/layer7.png", NULL);
}

void background_regroup(all_t *all)
{
    background_sprite_init(&all->background, &all->background2);
    background_texture_init(&all->background_text);
    set_sprite_background(&all->background, &all->background_text,
        &all->background2);
}