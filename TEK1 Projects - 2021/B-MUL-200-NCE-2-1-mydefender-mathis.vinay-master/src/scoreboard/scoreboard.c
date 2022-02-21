/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** picks up and write in a file to display a scoreboard
*/

#include "../../include/scoreboard.h"

scoreboard_t *scoreboard_create(void)
{
    scoreboard_t *scoreboard = malloc(sizeof(scoreboard_t));
    scoreboard->board_text = text_create("input scores", "C", sfWhite, false);
    scoreboard->board_title = text_create("Best 10 Scores:", "C", sfWhite,
                                            false);
    text_set_pos(scoreboard->board_title, 870, 150, 50);
    text_set_pos(scoreboard->board_text, 1050, 250, 40);
    text_set_outline(scoreboard->board_text, sfBlack, 1);
    text_set_outline(scoreboard->board_title, sfBlack, 2);
    scoreboard->return_btn =
    button_create("assets/gui/return_button.png", "C");
    sprite_set_pos(scoreboard->return_btn, 960, 850, 1);
    scoreboard->last_mode = 1;
    return scoreboard;
}

void scoreboard_display(scoreboard_t *score, sfRenderWindow *win)
{
    text_display(score->board_text, win);
    text_display(score->board_title, win);
    button_display(score->return_btn, win, true);
}

void scoreboard_destroy(scoreboard_t *score)
{
    text_destroy(score->board_text);
    text_destroy(score->board_title);
    sprite_destroy(score->return_btn);
    free(score);
}

void scoreboard_set_last_mode(scoreboard_t *score, int mode)
{
    score->last_mode = mode;
}