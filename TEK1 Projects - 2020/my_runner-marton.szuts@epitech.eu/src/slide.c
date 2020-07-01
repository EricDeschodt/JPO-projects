/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** slide
*/

#include "runner.h"

int render_slide(controll_t *s_controll)
{
    s_controll->s_slide.secconds = 0;
    s_controll->s_slide.clock = sfClock_create();
    s_controll->s_slide.rect.left = 0, s_controll->s_slide.rect.top = 0;
    s_controll->s_slide.rect.width = 155, s_controll->s_slide.slide = 0;
    s_controll->s_slide.rect.height = 100;
    s_controll->s_slide.texture =
    sfTexture_createFromFile("sprites/slide.png", NULL);
    if (!s_controll->s_slide.texture)
        return (EXIT_FAILURE);
    s_controll->s_slide.sprite = sfSprite_create();
    sfSprite_setTexture(s_controll->s_slide.sprite,
    s_controll->s_slide.texture, sfTrue);
    return (0);
}

void slide(controll_t *s_controll)
{
    sfSprite_setPosition(s_controll->s_slide.sprite,
    (sfVector2f){s_controll->s_runner.pos.x, s_controll->s_runner.pos.y});
    sfSprite_setTextureRect(s_controll->s_slide.sprite,
    s_controll->s_slide.rect);
    move_rect_slide(s_controll, 155, 310);
    sfClock_restart(s_controll->s_slide.clock);
}