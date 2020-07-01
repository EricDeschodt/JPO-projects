/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** jelly
*/

#include "runner.h"

int render_jelly(controll_t *s_controll)
{
    s_controll->s_jelly.secconds = 0;
    s_controll->s_jelly.clock = sfClock_create();
    s_controll->s_jelly.rect.left = 0, s_controll->s_jelly.rect.top = 0;
    s_controll->s_jelly.rect.width = 175;
    s_controll->s_jelly.rect.height = 130;
    s_controll->s_jelly.texture =
    sfTexture_createFromFile("sprites/running_jelly.png", NULL);
    s_controll->s_jelly.pos.x = -130, s_controll->s_jelly.pos.y = 640;
    if (!s_controll->s_jelly.texture)
        return (EXIT_FAILURE);
    s_controll->s_jelly.sprite = sfSprite_create();
    sfSprite_setTexture(s_controll->s_jelly.sprite,
    s_controll->s_jelly.texture, sfTrue);
    sfSprite_setTextureRect(s_controll->s_jelly.sprite,
    s_controll->s_jelly.rect);
    sfSprite_setScale(s_controll->s_jelly.sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(s_controll->s_jelly.sprite, s_controll->s_jelly.pos);
    return (0);
}

void display_jelly(controll_t *s_controll)
{
    if (s_controll->s_game.scene == 1 || s_controll->s_game.scene == 5) {
        if (s_controll->s_jelly.secconds > 0.1) {
            move_rect_jelly(s_controll, 170, 680);
            sfSprite_setTextureRect(s_controll->s_jelly.sprite,
            s_controll->s_jelly.rect);
            sfClock_restart(s_controll->s_jelly.clock);
        }
    }
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_jelly.sprite, NULL);
}