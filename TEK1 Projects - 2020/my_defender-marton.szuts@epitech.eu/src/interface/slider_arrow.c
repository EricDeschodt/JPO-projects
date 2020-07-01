/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** slider_arrow
*/

#include "defender.h"

void init_slider_arrow(all_t *s_all)
{
    s_all->s_hard_arrow.pos = (sfVector2f){1835, 925};
    s_all->s_hard_arrow.sprite = sfSprite_create();
    s_all->s_hard_arrow.texture2 =
        sfTexture_createFromFile("sprites/buttons/arrow_slide_L.png", NULL);
    s_all->s_hard_arrow.texture =
        sfTexture_createFromFile("sprites/buttons/arrow_slide_R.png", NULL);
    s_all->s_hard_arrow.texture4 =
        sfTexture_createFromFile("sprites/buttons/arrow2_slide_L.png", NULL);
    s_all->s_hard_arrow.texture3 =
        sfTexture_createFromFile("sprites/buttons/arrow2_slide_R.png", NULL);
    sfSprite_setTexture(s_all->s_hard_arrow.sprite,
        s_all->s_hard_arrow.texture2, sfTrue);
    sfSprite_setPosition(s_all->s_hard_arrow.sprite,
        s_all->s_hard_arrow.pos);
    s_all->s_hard_arrow.stat = 1;
}

void hitbox_slider_arrow(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_hard_arrow.pos.x - 40 && mouse_pos.x <=
        s_all->s_hard_arrow.pos.x + 90) && (mouse_pos.y >= s_all->s_hard_arrow
        .pos.y - 40 && mouse_pos.y <= s_all->s_hard_arrow.pos.y + 140)
        && s_all->s_game.pause == 0 && s_all->s_game.scene != 0) {
        button_sound(s_all);
        if (s_all->s_hard_arrow.stat == 0)
            sfSprite_setTexture(s_all->s_hard_arrow.sprite,
                s_all->s_hard_arrow.texture3, sfTrue);
        else sfSprite_setTexture(s_all->s_hard_arrow.sprite,
            s_all->s_hard_arrow.texture4, sfTrue);
    }
}

void release_slider_arrow(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if (((mouse_pos.x >= s_all->s_hard_arrow.pos.x - 40 && mouse_pos.x <=
        s_all->s_hard_arrow.pos.x + 90) && (mouse_pos.y >= s_all->s_hard_arrow
        .pos.y - 40 && mouse_pos.y <= s_all->s_hard_arrow.pos.y + 140))
        && s_all->s_game.pause == 0 && s_all->s_game.scene != 0) {
        if (s_all->s_hard_arrow.stat == 0) {
            s_all->s_hard_arrow.stat = 1;
            sfSprite_setTexture(s_all->s_hard_arrow.sprite,
                s_all->s_hard_arrow.texture2, sfTrue);
        } else {
            s_all->s_hard_arrow.stat = 0;
            sfSprite_setTexture(s_all->s_hard_arrow.sprite,
                s_all->s_hard_arrow.texture, sfTrue);
        }
    } else if (s_all->s_hard_arrow.stat == 0)
        sfSprite_setTexture(s_all->s_hard_arrow.sprite,
            s_all->s_hard_arrow.texture, sfTrue);
    else sfSprite_setTexture(s_all->s_hard_arrow.sprite,
        s_all->s_hard_arrow.texture2, sfTrue);
}

void display_slider_arrow(all_t *s_all)
{
    if (s_all->s_side_menu.draw == 1) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_hard_arrow.sprite, NULL);
    }
}