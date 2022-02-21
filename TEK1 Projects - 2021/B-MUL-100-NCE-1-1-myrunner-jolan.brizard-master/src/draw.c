/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** Draw functions
*/

#include "../include/project.h"

void draw_title(t_window *window)
{
    sfRenderWindow_drawText(window->window, window->text->title_text, NULL);
    sfRenderWindow_drawText(window->window, window->text->enter_text, NULL);
}

void draw_background(t_window *window)
{
    sfRenderWindow_drawSprite(window->window, window->px->layer01, NULL);
    sfRenderWindow_drawSprite(window->window, window->px->layer02, NULL);
    sfRenderWindow_drawSprite(window->window, window->px->layer03, NULL);
    sfRenderWindow_drawSprite(window->window, window->px->layer04, NULL);
    sfRenderWindow_drawSprite(window->window, window->px->layer05, NULL);
    sfRenderWindow_drawSprite(window->window, window->px->layer06, NULL);
    sfRenderWindow_drawSprite(window->window, window->px->layer07, NULL);
    sfRenderWindow_drawSprite(window->window, window->px->layer08, NULL);
    sfRenderWindow_drawSprite(window->window, window->px->layer09, NULL);
}

void draw_character(t_window *window)
{
    sfRenderWindow_drawSprite(window->window, window->sprite->character, NULL);
}

void draw_score(t_window *window)
{
    int_to_str(window->text, window->text->s);
    sfText_setString(window->text->score, window->text->s_score);
    sfRenderWindow_drawText(window->window, window->text->score, NULL);
}

void draw_win_lose(t_window *window)
{
    sfVector2f pos_score_end = {580, 360};
    sfVector2f pos_enter_end = {500, 420};
    sfVector2f sc_score_end = {1, 1};
    sfText_setScale(window->text->score, sc_score_end);
    sfText_setPosition(window->text->score, pos_score_end);
    sfText_setPosition(window->text->enter_text, pos_enter_end);
    if (window->win) {
        sfRenderWindow_drawText(window->window, window->text->win_text, NULL);
        sfRenderWindow_drawText(window->window, window->text->enter_text, NULL);
        draw_score(window);
    }
    if (!(window->win)) {
        sfRenderWindow_drawText(window->window, window->text->lose_text, NULL);
        sfRenderWindow_drawText(window->window, window->text->enter_text, NULL);
        draw_score(window);
    }
}