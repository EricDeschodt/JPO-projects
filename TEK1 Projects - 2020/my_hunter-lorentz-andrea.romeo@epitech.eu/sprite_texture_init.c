/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** sprite_texture_init
*/

#include "my.h"

void set_texture(sprite_t *sprite, texture_t *texture)
{
    sfSprite_setTexture(sprite->duck1, texture->text_duck1, sfTrue);
    sfSprite_setTexture(sprite->duck2, texture->text_duck2, sfTrue);
    sfSprite_setTexture(sprite->duck3, texture->text_duck3, sfTrue);
    sfSprite_setTexture(sprite->duck1_fall, texture->text_duck1_fall, sfTrue);
    sfSprite_setTexture(sprite->duck2_fall, texture->text_duck2_fall, sfTrue);
    sfSprite_setTexture(sprite->duck3_fall, texture->text_duck3_fall, sfTrue);
    sfSprite_setTexture(sprite->duck1_rev, texture->text_duck1_rev, sfTrue);
    sfSprite_setTexture(sprite->duck2_rev, texture->text_duck2_rev, sfTrue);
    sfSprite_setTexture(sprite->duck3_rev, texture->text_duck3_rev, sfTrue);
    sfSprite_setTexture(sprite->duck1_bot, texture->text_duck1_bot, sfTrue);
    sfSprite_setTexture(sprite->duck2_bot, texture->text_duck2_bot, sfTrue);
    sfSprite_setTexture(sprite->duck3_bot, texture->text_duck3_bot, sfTrue);
    sfSprite_setTexture(sprite->dog, texture->text_dog, sfTrue);
    sfSprite_setTexture(sprite->dog_jump, texture->text_dog_jump, sfTrue);
    sfSprite_setTexture(sprite->dead_duck1, texture->text_dead_duck1, sfTrue);
    sfSprite_setTexture(sprite->dead_duck2, texture->text_dead_duck2, sfTrue);
    sfSprite_setTexture(sprite->dead_duck3, texture->text_dead_duck3, sfTrue);
    sfSprite_setTexture(sprite->background, texture->text_background, sfTrue);
    sfSprite_setTexture(sprite->foreground, texture->text_foreground, sfTrue);
    sfSprite_setTexture(sprite->cursor, texture->text_cursor, sfTrue);
}

void sprite_init(sprite_t *sprite)
{
    sprite->duck1 = sfSprite_create();
    sprite->duck2 = sfSprite_create();
    sprite->duck3 = sfSprite_create();
    sprite->duck1_fall = sfSprite_create();
    sprite->duck2_fall = sfSprite_create();
    sprite->duck3_fall = sfSprite_create();
    sprite->duck1_rev = sfSprite_create();
    sprite->duck2_rev = sfSprite_create();
    sprite->duck3_rev = sfSprite_create();
    sprite->duck1_bot = sfSprite_create();
    sprite->duck2_bot = sfSprite_create();
    sprite->duck3_bot = sfSprite_create();
    sprite->dog = sfSprite_create();
    sprite->dog_jump = sfSprite_create();
    sprite->dead_duck1 = sfSprite_create();
    sprite->dead_duck2 = sfSprite_create();
    sprite->dead_duck3 = sfSprite_create();
    sprite->background = sfSprite_create();
    sprite->foreground = sfSprite_create();
    sprite->cursor = sfSprite_create();
}

void texture_init(texture_t *texture)
{
    texture->text_duck1 = sfTexture_createFromFile("sprite/duck1.png", NULL);
    texture->text_duck2 = sfTexture_createFromFile("sprite/duck2.png", NULL);
    texture->text_duck3 = sfTexture_createFromFile("sprite/duck3.png", NULL);
    texture->text_dog = sfTexture_createFromFile("sprite/dog.png", NULL);
    texture->text_dog_jump = sfTexture_createFromFile("sprite/dog_jump.png",
        NULL);
    texture->text_dead_duck1 = sfTexture_createFromFile("sprite/dead1.png",
        NULL);
    texture->text_dead_duck2 = sfTexture_createFromFile("sprite/dead2.png",
        NULL);
    texture->text_dead_duck3 = sfTexture_createFromFile("sprite/dead3.png",
        NULL);
    texture->text_background =
        sfTexture_createFromFile("sprite/background.png", NULL);
    texture->text_foreground =
        sfTexture_createFromFile("sprite/foreground.png", NULL);
    texture->text_cursor = sfTexture_createFromFile("sprite/cursor.png",
        NULL);
    texture->text_main_menu = sfTexture_createFromFile("sprite/main_menu.jpg",
        NULL);
}

void texture_init2(texture_t *texture)
{
    texture->text_duck1_rev = sfTexture_createFromFile("sprite/duck1_rev.png",
        NULL);
    texture->text_duck2_rev = sfTexture_createFromFile("sprite/duck2_rev.png",
        NULL);
    texture->text_duck3_rev = sfTexture_createFromFile("sprite/duck3_rev.png",
        NULL);
    texture->text_duck1_bot = sfTexture_createFromFile("sprite/duck1_bot.png",
        NULL);
    texture->text_duck2_bot = sfTexture_createFromFile("sprite/duck2_bot.png",
        NULL);
    texture->text_duck3_bot = sfTexture_createFromFile("sprite/duck3_bot.png",
        NULL);
    texture->text_duck1_fall = sfTexture_createFromFile("sprite/duck1_fall.png",
        NULL);
    texture->text_duck2_fall = sfTexture_createFromFile("sprite/duck2_fall.png",
        NULL);
    texture->text_duck3_fall = sfTexture_createFromFile("sprite/duck3_fall.png",
        NULL);
    texture->text_main_menu = sfTexture_createFromFile("sprite/main_menu.jpg",
        NULL);
}
