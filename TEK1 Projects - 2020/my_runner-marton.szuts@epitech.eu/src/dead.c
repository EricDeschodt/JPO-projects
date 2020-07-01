/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** dead
*/

#include "runner.h"

int render_dead(controll_t *s_controll)
{
    s_controll->s_dead.seconds = 0;
    s_controll->s_dead.clock = sfClock_create();
    s_controll->s_dead.rect.left = 0, s_controll->s_dead.rect.top = 0;
    s_controll->s_dead.rect.width = 165;
    s_controll->s_dead.rect.height = 95;
    s_controll->s_dead.texture =
    sfTexture_createFromFile("sprites/dead.png", NULL);
    s_controll->s_dead.pos.x = 875, s_controll->s_dead.pos.y = 770;
    if (!s_controll->s_dead.texture)
        return (EXIT_FAILURE);
    s_controll->s_dead.sprite = sfSprite_create();
    sfSprite_setTexture(s_controll->s_dead.sprite,
    s_controll->s_dead.texture, sfTrue);
    sfSprite_setPosition(s_controll->s_dead.sprite, s_controll->s_dead.pos);
    return (0);
}

void move_rect_dead(controll_t *s_controll, int offset, int max_value)
{
    if (s_controll->s_dead.rect.left < max_value - offset) {
        s_controll->s_dead.rect.left += offset;
    }
    else
        s_controll->s_dead.rect.left = 0;
}

void display_dead(controll_t *s_controll)
{
    if (s_controll->s_dead.seconds > 0.1 ) {
        move_rect_dead(s_controll, 165, 660);
        sfSprite_setTextureRect(s_controll->s_dead.sprite,
        s_controll->s_dead.rect);
        sfClock_restart(s_controll->s_dead.clock);
    }
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_dead.sprite, NULL);
}
