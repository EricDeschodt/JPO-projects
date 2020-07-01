/*
** EPITECH PROJECT, 2019
** dog
** File description:
** dog
*/

#include "ducky.h"

void move_rect_dog(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset)
        rect->left += 162;
    else
        rect->left = 0;
}

void move_dog(s_show *image)
{
    if (image->dog.x < 1920) {
        image->dog_rev.time_move = sfClock_restart(image->dog_rev.clock_move);
        image->dog.x += 0.1 * sfTime_asMilliseconds(image->dog.time_move);
        }
    if (image->dog.x >= 1920) {
        image->dog.x = -162;
        image->dog_rev.x = 1920;
        image->dog_state = 1;
        image->dog_rev.time_move = sfClock_restart(image->dog_rev.clock_move);
    }
}

void load_dog(s_show *image)
{
    image->dog.duck.texture =
    sfTexture_createFromFile("sprites/dog.png", NULL);
    image->dog.duck.sprite = sfSprite_create();
    sfSprite_setTexture(image->dog.duck.sprite, image->dog.duck.texture, 0);
    image->dog.time = sfClock_getElapsedTime(image->dog.clock);
    image->dog.seconds = image->dog.time.microseconds / 1000000.0;
    if (image->dog.seconds > 0.1) {
        move_rect_dog(&image->dog.frame, 162, 648);
        sfClock_restart(image->dog.clock);
    }
    image->dog.time_move = sfClock_restart(image->dog.clock_move);
    move_dog(image);

    sfSprite_setPosition(image->dog.duck.sprite,
    (sfVector2f){image->dog.x, image->dog.y});
    sfSprite_setTextureRect(image->dog.duck.sprite, image->dog.frame);
}

void draw_dog(sfRenderWindow *window, s_show *image)
{
    sfRenderWindow_drawSprite(window, image->dog.duck.sprite, NULL);
}

void load_dog_rev(s_show *image)
{
    image->dog_rev.duck.texture =
    sfTexture_createFromFile("sprites/dog_rev.png", NULL);
    image->dog_rev.duck.sprite = sfSprite_create();
    sfSprite_setTexture(image->dog_rev.duck.sprite,
    image->dog_rev.duck.texture, 0);
    image->dog_rev.time = sfClock_getElapsedTime(image->dog_rev.clock);
    image->dog_rev.seconds = image->dog_rev.time.microseconds / 1000000.0;
    if (image->dog_rev.seconds > 0.1) {
        move_rev_dog(&image->dog_rev.frame, 162, 0);
        sfClock_restart(image->dog_rev.clock);
    }
    image->dog_rev.time_move = sfClock_restart(image->dog_rev.clock_move);
    move_dog_rev(image);
    sfSprite_setPosition(image->dog_rev.duck.sprite,
    (sfVector2f){image->dog_rev.x, image->dog_rev.y});
    sfSprite_setTextureRect(image->dog_rev.duck.sprite, image->dog_rev.frame);
}
