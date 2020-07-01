/*
** EPITECH PROJECT, 2019
** analyse_events
** File description:
** analyse_events
*/

#include "ducky.h"

void analyse_events(sfRenderWindow *window, s_show *image)
{
        if (image->event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (image->event.type == sfEvtMouseButtonPressed) {
            load_sound(image);
            shoot_duck(window, image);
            shoot_duck_rev(window, image);
        }
}

void load_sprites(s_show *image)
{
    image->duck.duck.texture =
    sfTexture_createFromFile("sprites/duck_left.png", NULL);
    image->duck.duck.sprite = sfSprite_create();
    sfSprite_setTexture(image->duck.duck.sprite, image->duck.duck.texture, 0);
    image->duck.time = sfClock_getElapsedTime(image->duck.clock);
    image->duck.seconds = image->duck.time.microseconds / 1000000.0;
    if (image->duck.seconds > 0.1) {
        move_rect(&image->duck.frame, 110, 330);
        sfClock_restart(image->duck.clock);
    }
    image->duck.time_move = sfClock_restart(image->duck.clock_move);
    move_duck(image);

    sfSprite_setTextureRect(image->duck.duck.sprite, image->duck.frame);
}

void move_duck(s_show *image)
{
    if (image->duck.x < 1920) {
        image->duck.x += 0.5 * sfTime_asMilliseconds(image->duck.time_move) *
        image->level;
        image->duck_rev.time_move =
        sfClock_restart(image->duck_rev.clock_move);
    }
    if (image->duck.x >= 1920) {
        image->life.lives -= 1;
        image->duck.x = 0;
        image->duck.y = rand() % 500;
        image->func = rand() % 2;
        image->duck.time_move = sfClock_restart(image->duck.clock_move);
    }
}

void display(sfRenderWindow *window, s_show *image)
{
    image->cross.pos.x = sfMouse_getPositionRenderWindow(window).x;
    image->cross.pos.y = sfMouse_getPositionRenderWindow(window).y;
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_drawSprite(window, image->back.sprite, NULL);
    sfText_setPosition(image->text.text, (sfVector2f){1620, 880});
    sfRenderWindow_drawText(window, image->text.text, NULL);
    sfText_setPosition(image->text.score, (sfVector2f){1800, 880});
    sfRenderWindow_drawText(window, image->text.score, NULL);
    check_bird(window, image);
    sfSprite_setPosition(image->cross.cross.sprite,
    (sfVector2f){image->cross.pos.x - 25, image->cross.pos.y - 25});
    sfRenderWindow_drawSprite(window, image->cross.cross.sprite, NULL);
    sfRenderWindow_drawSprite(window, image->life.life.sprite, NULL);
    draw_dead(window, image);
    draw_dead_rev(window, image);
    sfRenderWindow_display(window);
}

void destroy(sfRenderWindow *window, s_show *image)
{
    sfText_destroy(image->text.text);
    sfFont_destroy(image->text.font);
    sfClock_destroy(image->duck.clock);
    sfClock_destroy(image->duck.clock_move);
    sfClock_destroy(image->duck_rev.clock);
    sfClock_destroy(image->duck_rev.clock_move);
    sfClock_destroy(image->dog.clock);
    sfClock_destroy(image->dog.clock_move);
    sfClock_destroy(image->dog_rev.clock);
    sfClock_destroy(image->dog_rev.clock_move);
    sfClock_destroy(image->dead.dead_clock);
    sfRenderWindow_destroy(window);
}
