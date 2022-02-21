/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** Events related functions
*/

#include "../include/project.h"

void reset(t_window *window)
{
    if (window->start == false) {
        window->text->s = 0;
        sfVector2f reset_pos = {0, 0};
        sfVector2f res_enter = {520, 350};
        sfVector2f reset_scale = {0.5, 0.5};
        sfText_setPosition(window->text->score, reset_pos);
        sfText_setPosition(window->text->enter_text, res_enter);
        sfText_setScale(window->text->score, reset_scale);
        sfSprite_setPosition(window->sprite->character, window->sprite->base);
        window->jumping = false;
        window->sprite->speed = -22;
        window->map->index = 0;
    }
}

void pause_game(t_window *window)
{
    sfVector2f reset_pos = {0, 0};
    sfVector2f res_enter = {520, 350};
    sfVector2f reset_scale = {0.5, 0.5};
    sfText_setPosition(window->text->score, reset_pos);
    sfText_setPosition(window->text->enter_text, res_enter);
    sfText_setScale(window->text->score, reset_scale);
    sfSprite_setPosition(window->sprite->character, window->sprite->base);
    window->jumping = false;
    window->sprite->speed = -22;
}

void win_lose(t_window *window)
{
    sfVector2f hero = sfSprite_getPosition(window->sprite->character);
    sfVector2f blob = sfSprite_getPosition(window->map->obs);

    if (window->map->index >= 229) {
        window->end = true;
        window->win = true;
        window->start = false;
    }
    if (blob.x <= hero.x + (float) window->sprite->character_rect.width
        && blob.y <= hero.y + (float) window->sprite->character_rect.height
        && hero.x <= blob.x + (float) window->map->rct_obs.width) {
        sfSound_play(window->death_sound);
        window->end = true;
        window->win = false;
        window->start = false;
    }
}

void analyse_events(t_window *window, sfEvent event)
{
    if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
        sfRenderWindow_close(window->window);
    if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
        reset(window);
        window->start = true;
        window->end = false;
    }
    if (event.key.code == sfKeySpace)
        window->jumping = true;
    if (event.key.code == sfKeyTab) {
        window->start = false;
        window->end = false;
        pause_game(window);
    }
    else
        return;
}

