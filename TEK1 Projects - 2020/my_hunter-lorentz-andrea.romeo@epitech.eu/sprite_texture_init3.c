/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** sprite_texture_init3
*/

#include "my.h"

void sprite_init3(sprite2_t *sprite2)
{
    sprite2->dog_1duck = sfSprite_create();
    sprite2->dog_2duck = sfSprite_create();
    sprite2->overlay = sfSprite_create();
    sprite2->overlay2 = sfSprite_create();
    sprite2->ammo = sfSprite_create();
    sprite2->perfect_s = sfSprite_create();
}

void texture_init5(texture2_t *texture2)
{
    texture2->text_overlay2 = sfTexture_createFromFile("sprite/overlay2.png",
        NULL);
    texture2->text_ammo = sfTexture_createFromFile("sprite/ammo.png",
        NULL);
    texture2->text_perfect = sfTexture_createFromFile("sprite/perfect.png",
        NULL);
}