/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** sprite_texture_init2
*/

#include "my.h"

void set_texture3(sprite2_t *sprite2, texture2_t *texture2)
{
    sfSprite_setTexture(sprite2->dead_duck2_2, texture2->text_dead_duck2_2,
        sfTrue);
    sfSprite_setTexture(sprite2->dead_duck3_2, texture2->text_dead_duck3_2,
        sfTrue);
    sfSprite_setTexture(sprite2->dead_duck1_2, texture2->text_dead_duck1_2,
        sfTrue);
    sfSprite_setTexture(sprite2->dog_1duck, texture2->text_dog_1duck, sfTrue);
    sfSprite_setTexture(sprite2->dog_2duck, texture2->text_dog_2duck, sfTrue);
    sfSprite_setTexture(sprite2->overlay, texture2->text_overlay, sfTrue);
    sfSprite_setTexture(sprite2->overlay2, texture2->text_overlay2, sfTrue);
    sfSprite_setTexture(sprite2->ammo, texture2->text_ammo, sfTrue);
    sfSprite_setTexture(sprite2->perfect_s, texture2->text_perfect, sfTrue);
}

void set_texture2(sprite_t *sprite, texture_t *texture, sprite2_t *sprite2,
    texture2_t *texture2)
{
    sfSprite_setTexture(sprite->main_menu, texture->text_main_menu, sfTrue);
    sfSprite_setTexture(sprite->menu_arrow, texture->text_menu_arrow, sfTrue);
    sfSprite_setTexture(sprite->menu_dog, texture->text_menu_dog, sfTrue);
    sfSprite_setTexture(sprite2->duck1_2, texture2->text_duck1_2, sfTrue);
    sfSprite_setTexture(sprite2->duck2_2, texture2->text_duck2_2, sfTrue);
    sfSprite_setTexture(sprite2->duck3_2, texture2->text_duck3_2, sfTrue);
    sfSprite_setTexture(sprite2->duck1_fall2, texture2->text_duck1_fall2,
        sfTrue);
    sfSprite_setTexture(sprite2->duck2_fall2, texture2->text_duck2_fall2,
        sfTrue);
    sfSprite_setTexture(sprite2->duck3_fall2, texture2->text_duck3_fall2,
        sfTrue);
    sfSprite_setTexture(sprite2->duck1_rev2, texture2->text_duck1_rev2, sfTrue);
    sfSprite_setTexture(sprite2->duck2_rev2, texture2->text_duck2_rev2, sfTrue);
    sfSprite_setTexture(sprite2->duck3_rev2, texture2->text_duck3_rev2, sfTrue);
    sfSprite_setTexture(sprite2->duck1_bot2, texture2->text_duck1_bot2, sfTrue);
    sfSprite_setTexture(sprite2->duck2_bot2, texture2->text_duck2_bot2, sfTrue);
    sfSprite_setTexture(sprite2->duck3_bot2, texture2->text_duck3_bot2, sfTrue);
    sfSprite_setTexture(sprite2->laugh_dog, texture2->text_laugh_dog, sfTrue);
}

void sprite_init2(sprite_t *sprite, sprite2_t *sprite2)
{
    sprite->main_menu = sfSprite_create();
    sprite->menu_arrow = sfSprite_create();
    sprite->menu_dog = sfSprite_create();
    sprite2->duck1_2 = sfSprite_create();
    sprite2->duck2_2 = sfSprite_create();
    sprite2->duck3_2 = sfSprite_create();
    sprite2->duck1_fall2 = sfSprite_create();
    sprite2->duck2_fall2 = sfSprite_create();
    sprite2->duck3_fall2 = sfSprite_create();
    sprite2->duck1_rev2 = sfSprite_create();
    sprite2->duck2_rev2 = sfSprite_create();
    sprite2->duck3_rev2 = sfSprite_create();
    sprite2->duck1_bot2 = sfSprite_create();
    sprite2->duck2_bot2 = sfSprite_create();
    sprite2->duck3_bot2 = sfSprite_create();
    sprite2->dead_duck1_2 = sfSprite_create();
    sprite2->dead_duck2_2 = sfSprite_create();
    sprite2->dead_duck3_2 = sfSprite_create();
    sprite2->laugh_dog = sfSprite_create();
    sprite_init3(sprite2);
}

void texture_init4(texture2_t *texture2)
{
    texture2->text_dead_duck1_2 = sfTexture_createFromFile("sprite/dead1.png",
        NULL);
    texture2->text_dead_duck2_2 = sfTexture_createFromFile("sprite/dead2.png",
        NULL);
    texture2->text_dead_duck3_2 = sfTexture_createFromFile("sprite/dead3.png",
        NULL);
    texture2->text_duck1_fall2 =
        sfTexture_createFromFile("sprite/duck1_fall.png", NULL);
    texture2->text_duck2_fall2 =
        sfTexture_createFromFile("sprite/duck2_fall.png", NULL);
    texture2->text_duck3_fall2 =
        sfTexture_createFromFile("sprite/duck3_fall.png", NULL);
    texture2->text_laugh_dog = sfTexture_createFromFile("sprite/laugh_dog.png",
        NULL);
    texture2->text_dog_1duck = sfTexture_createFromFile("sprite/1duck.png",
        NULL);
    texture2->text_dog_2duck = sfTexture_createFromFile("sprite/2duck.png",
        NULL);
    texture2->text_overlay = sfTexture_createFromFile("sprite/overlay.png",
        NULL);
}

void texture_init3(texture_t *texture, texture2_t *texture2)
{
    texture->text_menu_dog = sfTexture_createFromFile("sprite/menu_dog.png",
        NULL);
    texture->text_menu_arrow = sfTexture_createFromFile("sprite/menu_arrow.png",
        NULL);
    texture2->text_duck1_rev2 = sfTexture_createFromFile("sprite/duck1_rev.png",
        NULL);
    texture2->text_duck2_rev2 = sfTexture_createFromFile("sprite/duck2_rev.png",
        NULL);
    texture2->text_duck3_rev2 = sfTexture_createFromFile("sprite/duck3_rev.png",
        NULL);
    texture2->text_duck1_bot2 = sfTexture_createFromFile("sprite/duck1_bot.png",
        NULL);
    texture2->text_duck2_bot2 = sfTexture_createFromFile("sprite/duck2_bot.png",
        NULL);
    texture2->text_duck3_bot2 = sfTexture_createFromFile("sprite/duck3_bot.png",
        NULL);
    texture2->text_duck1_2 = sfTexture_createFromFile("sprite/duck1.png", NULL);
    texture2->text_duck2_2 = sfTexture_createFromFile("sprite/duck2.png", NULL);
    texture2->text_duck3_2 = sfTexture_createFromFile("sprite/duck3.png", NULL);
    texture_init5(texture2);
}