/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** events_controll
*/

#include "runner.h"

void menu_event(controll_t *s_controll)
{
    if (sfKeyboard_isKeyPressed(sfKeyP) &&
    s_controll->s_game.scene == 1) {
        s_controll->s_game.speed = 0;
        s_controll->s_game.scene = 2;
    }
    if (sfKeyboard_isKeyPressed(sfKeyR) &&
    s_controll->s_game.scene == 2) {
        s_controll->s_game.speed = 1;
        s_controll->s_game.scene = 1;
    }
}

void event_controll(controll_t *s_controll)
{
    if (s_controll->s_game.event.type == sfEvtClosed) {
        sfRenderWindow_close(s_controll->s_game.window);
    }
    if (s_controll->s_game.scene != 1)
        if (s_controll->s_game.event.type == sfEvtMouseButtonReleased)
            button_hitbox(s_controll);
    if (s_controll->s_game.scene == 1) {
        if (s_controll->s_runner.jump != 1 && s_controll->s_runner.fall != 1 &&
        s_controll->s_game.scene != 2) {
            jump_slide(s_controll);
        }
        if (s_controll->s_runner.jump != 1 && s_controll->s_runner.fall != 1 &&
        s_controll->s_slide.slide != 1) {
            menu_event(s_controll);
        }
    }
}

void jump_slide(controll_t *s_controll)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) &&
    s_controll->s_slide.slide == 0) {
        sfSound_play(s_controll->s_music.jump_sound);
        s_controll->s_runner.jump = 1;
        s_controll->s_slide.slide = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLControl)) {
        if (s_controll->s_runner.jump != 1 && s_controll->s_slide.slide != 1) {
            sfSound_play(s_controll->s_music.slide_sound);
            s_controll->s_runner.pos.y += 30;
            s_controll->s_slide.slide = 1;
        }
    }
    else if (!sfKeyboard_isKeyPressed(sfKeyLControl) &&
    s_controll->s_slide.slide == 1) {
        s_controll->s_runner.pos.y -= 30;
        s_controll->s_slide.slide = 0;
    }
}