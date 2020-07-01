/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** pause
*/

#include "defender.h"

void init_pause_button(all_t *s_all)
{
    s_all->s_hard_buttons.pos = (sfVector2f){30, 30};
    s_all->s_hard_buttons.sprite = sfSprite_create();
    s_all->s_hard_buttons.texture =
        sfTexture_createFromFile("sprites/buttons/pause.png", NULL);
    s_all->s_hard_buttons.texture2 =
        sfTexture_createFromFile("sprites/buttons/pause2.png", NULL);
    sfSprite_setTexture(s_all->s_hard_buttons.sprite,
        s_all->s_hard_buttons.texture, sfTrue);
    sfSprite_setPosition(s_all->s_hard_buttons.sprite,
        s_all->s_hard_buttons.pos);
}

void hitbox_pause_button(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_hard_buttons.pos.x
        && mouse_pos.x <= s_all->s_hard_buttons.pos.x + 85)
        && (mouse_pos.y >= s_all->s_hard_buttons.pos.y
        && mouse_pos.y <= s_all->s_hard_buttons.pos.y + 85)) {
        sfSprite_setTexture(s_all->s_hard_buttons.sprite,
            s_all->s_hard_buttons.texture2, sfTrue);
    }
}

void release_pause_button(all_t *s_all)
{
    sfSprite_setTexture(s_all->s_hard_buttons.sprite,
        s_all->s_hard_buttons.texture, sfTrue);
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_hard_buttons.pos.x
        && mouse_pos.x <= s_all->s_hard_buttons.pos.x + 85)
        && (mouse_pos.y >= s_all->s_hard_buttons.pos.y
        && mouse_pos.y <= s_all->s_hard_buttons.pos.y + 85)
        && s_all->s_game.scene == 1 && s_all->s_game.pause == 0) {
        s_all->s_game.pause = 1;
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    }
}

void display_pause_button(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_hard_buttons.sprite, NULL);
}