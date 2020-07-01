/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** menu2
*/

#include "defender.h"
#include "utils.h"

void menu_press_buttons(all_t *s_all)
{
    node_buttons_t *tmp = s_all->s_buttons->begin;
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    for (int i = 0; tmp != NULL; i++) {
        if (i == 0 && s_all->s_game.eric == 0) {
            tmp = tmp->next;
            continue;
        } if ((mouse_pos.x >= tmp->pos.x && mouse_pos.x <= tmp->pos.x + 500)
            && (mouse_pos.y >= tmp->pos.y && mouse_pos.y <= tmp->pos.y + 80)) {
            sfSprite_setTexture(tmp->sprite, tmp->texture2, sfTrue);
        }
        tmp = tmp->next;
    }
}

void menu_release_selector2(all_t *s_all, int i)
{
    if (i == 2 && s_all->s_game.scene == 0) {
        s_all->s_game.transition = 2, s_all->s_game.pause = 1;
        s_all->s_game.lost_anim = 0;
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    } if (i == 1 && s_all->s_game.scene == 0) {
        s_all->s_game.transition = -1, s_all->s_game.pause = 0;
        s_all->s_game.lost_anim = 0, init_custom_level_buttons(s_all);
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    } if (i == 11 && (s_all->s_game.scene == -1 || s_all->s_game.scene == 6
    || s_all->s_game.scene == 4 || s_all->s_game.scene == 3
    || s_all->s_game.scene == 5)) {
        s_all->s_game.transition = 0, s_all->s_game.lost_anim = 0;
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    }
}

void menu_release_selector(all_t *s_all, int i)
{
    if (i == 0 && s_all->s_game.scene == 0 && s_all->s_game.eric != 0) {
        sfClock_restart(s_all->s_game.clock), s_all->s_game.lost_anim = 0;
        sfClock_restart(s_all->s_wave_c.clock), s_all->s_game.pause = 0;
        restart_tuto_clocks(s_all), sfClock_restart(s_all->s_spawning.clock2);
        s_all->s_game.transition = 1, sfClock_restart(s_all->s_spawning.clock);
        sfSprite_setTexture(s_all->s_buttons->begin->sprite,
        s_all->s_buttons->begin->texture, sfTrue);
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    } menu_release_selector2(s_all, i);
    menu_release_selector3(s_all, i);
    if (i == 5 && s_all->s_game.scene == 0) {
        s_all->s_game.transition = 5, s_all->s_game.lost_anim = 0;
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    }
}

void menu_release_buttons(all_t *s_all)
{
    node_buttons_t *tmp = s_all->s_buttons->begin;
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    int i = 0;
    while (tmp != NULL) {
        if ((mouse_pos.x >= tmp->pos.x && mouse_pos.x <= tmp->pos.x + 500)
            && (mouse_pos.y >= tmp->pos.y && mouse_pos.y <= tmp->pos.y + 80)) {
            menu_release_selector(s_all, i);
        } if (i == 0 && s_all->s_game.eric == 0) {
            tmp = tmp->next;
            i++;
            continue;
        }
        sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
        tmp = tmp->next;
        i++;
    }
}

void menu_buttons_hitbox(node_buttons_t *tmp, all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= tmp->pos.x && mouse_pos.x <= tmp->pos.x + 500)
        && (mouse_pos.y >= tmp->pos.y && mouse_pos.y <= tmp->pos.y + 80)
        && s_all->s_buttons->seconds > 0.01) {
        sfClock_restart(s_all->s_buttons->clock);
        if (tmp->pos.x > 1550)
            tmp->pos.x -= 50;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
    } else if (tmp->pos.x < 1820 && s_all->s_buttons->seconds > 0.01) {
        tmp->pos.x += 50;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        sfClock_restart(s_all->s_buttons->clock);
    }
}