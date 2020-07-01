/*
** EPITECH PROJECT, 2019
** crosshair
** File description:
** crosshair
*/

#include "ducky.h"

void load_crosshair(s_show *image)
{
    image->cross.cross.texture =
    sfTexture_createFromFile("sprites/crosshair.png", NULL);
    image->cross.cross.sprite = sfSprite_create();
    sfSprite_setTexture(image->cross.cross.sprite,
    image->cross.cross.texture, 0);

}

void draw_heart(s_show *image)
{
    if (image->life.lives > 0) {
        image->life.heart.left = 0, image->life.heart.top = 0,
        image->life.heart.height = 40,
        image->life.heart.width = image->life.lives * 40;
    }
}

void load_life(s_show *image)
{
    image->life.life.texture =
    sfTexture_createFromFile("sprites/life.png", NULL);
    image->life.life.sprite = sfSprite_create();
    sfSprite_setTexture(image->life.life.sprite, image->life.life.texture, 0);
    draw_heart(image);
    sfSprite_setPosition(image->life.life.sprite, (sfVector2f){100, 880});
    sfSprite_setTextureRect(image->life.life.sprite, image->life.heart);
}

void load_animations(s_show *image)
{
    if (image->func == 0)
        load_sprites(image);
    if (image->func == 1)
        load_duck_rev(image);
    load_life(image);
    update_score(image);
    dead_duck(image);
}

void check_dog(sfRenderWindow *window, s_show *image)
{
    if (image->dog_state == 0) {
        load_dog(image);
        draw_dog(window, image);
    }
    if (image->dog_state == 1) {
        load_dog_rev(image);
        draw_dog_rev(window, image);
    }
}
