/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** lost_animation
*/

#include "defender.h"

void display_lost_screen(all_t *s_all)
{
    lost_t *tmp = s_all->s_lost;

    anim_transition(s_all);

    while (tmp != NULL) {
        if (tmp->display == 1)
            sfRenderWindow_drawCircleShape(s_all->s_game.window,
                tmp->circle, NULL);
        tmp = tmp->next;
    }

    if (s_all->s_player.life <= 0) {
        if (s_all->s_settings->sound == 1 && s_all->s_player.defeat == 0)
            sfSound_play(s_all->s_sounds.defeat);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_menu.lost, NULL);
        s_all->s_player.defeat = 1;
        s_all->s_game.pause = 1;
    }
}

void remove_lost_screen(all_t *s_all)
{
    lost_t *tmp = s_all->s_lost;
    int clean = 0;

    while (s_all->s_game.lost_anim == 1 && tmp != NULL
    && s_all->s_game.anim_seconds >= 0.01) {
        if (clean == 0 && tmp->display == 1) {
            tmp->display = 0;
            clean = 1;
        }
        tmp = tmp->next;
        sfClock_restart(s_all->s_game.anim_clock);
    }

    if (s_all->s_game.lost_anim == 1) {
        tmp = s_all->s_lost;
        while (tmp->next != NULL)
            tmp = tmp->next;
        if (tmp->display == 0)
            s_all->s_game.lost_anim = 2;
    }
}

void set_lost_screen(all_t *s_all)
{
    lost_t *tmp = s_all->s_lost;
    static int check = 1;

    if (check != 0 && s_all->s_game.lost_anim == 0
    && s_all->s_game.anim_seconds >= 0.01) {
        check = 0;
        while (tmp != NULL) {
            if ((tmp->next == NULL || tmp->next->display == 1)
            && tmp->display != 1) {
                tmp->display = 1;
                check = 1;
            }
            tmp = tmp->next;
            sfClock_restart(s_all->s_game.anim_clock);
        }
        if (s_all->s_lost->display == 1) {
            s_all->s_game.lost_anim = 1;
            s_all->s_game.scene = s_all->s_game.transition;
        }
    }
}

void anim_transition(all_t *s_all)
{
    set_lost_screen(s_all);
    remove_lost_screen(s_all);
}