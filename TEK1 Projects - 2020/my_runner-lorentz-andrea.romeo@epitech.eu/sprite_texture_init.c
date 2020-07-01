/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** sprite_texture_init
*/

#include "my.h"

void set_texture(sprite_t *sprite, texture_t *texture)
{
    sfSprite_setTexture(sprite->michael, texture->text_michael, sfTrue);
    sfSprite_setTexture(sprite->jump, texture->text_jump, sfTrue);
    sfSprite_setTexture(sprite->crouch, texture->text_crouch, sfTrue);
    sfSprite_setTexture(sprite->hit, texture->text_hit, sfTrue);
    sfSprite_setTexture(sprite->crouch_hit, texture->text_crouch_hit, sfTrue);
    sfSprite_setTexture(sprite->up_throw, texture->text_up_throw, sfTrue);
    sfSprite_setTexture(sprite->down_throw, texture->text_down_throw, sfTrue);
    sfSprite_setTexture(sprite->hat, texture->text_hat, sfTrue);
}

void sprite_init(sprite_t *sprite)
{
    sprite->michael = sfSprite_create();
    sprite->jump = sfSprite_create();
    sprite->crouch = sfSprite_create();
    sprite->hit = sfSprite_create();
    sprite->crouch_hit = sfSprite_create();
    sprite->up_throw = sfSprite_create();
    sprite->down_throw = sfSprite_create();
    sprite->hat = sfSprite_create();
}

void texture_init(texture_t *texture)
{
    texture->text_michael = sfTexture_createFromFile("sprites/michael.png",
        NULL);
    texture->text_jump = sfTexture_createFromFile("sprites/jump.png", NULL);
    texture->text_crouch = sfTexture_createFromFile("sprites/crouch.png", NULL);
    texture->text_hit = sfTexture_createFromFile("sprites/hit.png", NULL);
    texture->text_crouch_hit =
        sfTexture_createFromFile("sprites/crouch_hit.png", NULL);
    texture->text_up_throw =
        sfTexture_createFromFile("sprites/up_throw.png", NULL);
    texture->text_down_throw =
        sfTexture_createFromFile("sprites/down_throw.png", NULL);
    texture->text_hat = sfTexture_createFromFile("sprites/hat.png", NULL);
    texture->text_fat_zombie =
        sfTexture_createFromFile("sprites/fat_zombie.png", NULL);
    texture->text_flying_zombie =
        sfTexture_createFromFile("sprites/flying_zombie.png", NULL);
    texture->text_traps = sfTexture_createFromFile("sprites/traps.png", NULL);
    texture->text_skull = sfTexture_createFromFile("sprites/skull.png", NULL);
}

void sprite_regroup(sprite_t *sprite, texture_t *texture)
{
    sprite_init(sprite);
    texture_init(texture);
    set_texture(sprite, texture);
}