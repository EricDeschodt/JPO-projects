/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** jump
*/

#include "runner.h"

int render_up(controll_t *s_controll)
{
    s_controll->s_jump.texture_j =
    sfTexture_createFromFile("sprites/jump.png", NULL);
    if (!s_controll->s_jump.texture_j)
        return (EXIT_FAILURE);
    s_controll->s_jump.sprite_j = sfSprite_create();
    sfSprite_setTexture(s_controll->s_jump.sprite_j,
    s_controll->s_jump.texture_j, sfTrue);
    return (0);
}

int render_down(controll_t *s_controll)
{
    s_controll->s_jump.texture_f =
    sfTexture_createFromFile("sprites/fall.png", NULL);
    if (!s_controll->s_jump.texture_f)
        return (EXIT_FAILURE);
    s_controll->s_jump.sprite_f = sfSprite_create();
    sfSprite_setTexture(s_controll->s_jump.sprite_f,
    s_controll->s_jump.texture_f, sfTrue);
    return (0);
}

void render_jump(controll_t *s_controll)
{
    render_up(s_controll);
    render_down(s_controll);
}

void jump(controll_t *s_controll)
{
    if (s_controll->s_runner.pos.y > 520) {
        s_controll->s_runner.pos.y -= s_controll->s_runner.inercy;
        s_controll->s_runner.inercy -= 1;
    }
    else {
        s_controll->s_runner.fall = 1;
        s_controll->s_runner.jump = 0;
        s_controll->s_runner.inercy = 0;
    }
    sfSprite_setPosition(s_controll->s_jump.sprite_j,
    s_controll->s_runner.pos);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_jump.sprite_j, NULL);
    sfClock_restart(s_controll->s_runner.jump_cl);
}

void fall(controll_t *s_controll)
{
    if (s_controll->s_runner.pos.y < 730) {
        s_controll->s_runner.pos.y += s_controll->s_runner.inercy;
        s_controll->s_runner.inercy += 1;
    }
    else {
        s_controll->s_runner.fall = 0;
        s_controll->s_runner.inercy = 20;
    }
    sfSprite_setPosition(s_controll->s_jump.sprite_f,
    s_controll->s_runner.pos);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_jump.sprite_f, NULL);
    sfClock_restart(s_controll->s_runner.jump_cl);
}