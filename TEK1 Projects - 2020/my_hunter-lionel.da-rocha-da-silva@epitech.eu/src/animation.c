/*
** EPITECH PROJECT, 2019
** animation
** File description:
** animation
*/

#include "ducky.h"

void move_rev(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset)
        rect->left += 148;
    else
        rect->left = 0;
}

void move_duck_rev(s_show *image)
{
    if (image->duck_rev.x > -148){
        image->duck_rev.x -= 0.5 *
        sfTime_asMilliseconds(image->duck_rev.time_move) * image->level;
        image->duck.time_move = sfClock_restart(image->duck.clock_move);
    }
    if (image->duck_rev.x <= -148) {
        image->life.lives -= 1;
        image->duck_rev.x = 1772;
        image->duck_rev.y = rand() % 500;
        image->func = rand() % 2;
        image->duck_rev.time_move =
        sfClock_restart(image->duck_rev.clock_move);
    }
}

void shoot_duck_rev(sfRenderWindow *window, s_show *image)
{
    image->duck_rev.hit.hitbox.height = 110,
    image->duck_rev.hit.hitbox.left = image->duck_rev.x,
    image->duck_rev.hit.hitbox.top = image->duck_rev.y,
    image->duck_rev.hit.hitbox.width = 148;
    image->duck_rev.hit.mouse.x = sfMouse_getPositionRenderWindow(window).x;
    image->duck_rev.hit.mouse.y = sfMouse_getPositionRenderWindow(window).y;
    if (sfFloatRect_contains(&image->duck_rev.hit.hitbox,
    image->duck_rev.hit.mouse.x, image->duck_rev.hit.mouse.y) == sfTrue) {
        image->dead.deadx = image->duck_rev.hit.mouse.x;
        image->dead.deady = image->duck_rev.hit.mouse.y;
        image->dead.dead_time.microseconds = 200;
        image->text.number = inf_add(image->text.number, "1");
        image->duck_rev.x = 1920;
        image->duck_rev.y = rand() % 500;
        image->level += 0.1;
        image->func = rand() % 2;
        image->duck.time_move = sfClock_restart(image->duck.clock_move);

    }
}

void draw_dead_rev(sfRenderWindow *window, s_show *image)
{
    if (sfFloatRect_contains(&image->duck_rev.hit.hitbox,
    image->duck_rev.hit.mouse.x, image->duck_rev.hit.mouse.y) == sfTrue) {
        if (image->dead.dead_time.microseconds > 0) {
            sfSprite_setPosition(image->dead.dead_duck.sprite,
            (sfVector2f){image->dead.deadx, image->dead.deady});
            sfRenderWindow_drawSprite(window,
            image->dead.dead_duck.sprite, NULL);
            image->dead.dead_time.microseconds -= 1.0;
        }
    }
}

void move_rev_dog(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left > max_value + offset)
        rect->left -= 162;
    else
        rect->left = 648;
}
