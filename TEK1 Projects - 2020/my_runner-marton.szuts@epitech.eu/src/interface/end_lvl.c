/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** end_lvl
*/

#include "runner.h"

void end_txt_win(controll_t *s_controll)
{
    s_controll->s_interface.end.win = sfText_create();
    sfText_setString(s_controll->s_interface.end.win, "You won !");
    sfText_setPosition(s_controll->s_interface.end.win,
    (sfVector2f){800, 300});
    sfText_setFont(s_controll->s_interface.end.lose, s_controll->font);
}

void end_txt_lose_gameover(controll_t *s_controll)
{
    s_controll->s_interface.end.lose = sfText_create();
    sfText_setString(s_controll->s_interface.end.lose, "Game Over");
    sfText_setCharacterSize(s_controll->s_interface.end.lose, 100);
    sfText_setPosition(s_controll->s_interface.end.lose,
    (sfVector2f){720, 100});
    sfText_setFont(s_controll->s_interface.end.lose, s_controll->font);
}

void display_end_txts(controll_t *s_controll)
{
    if (s_controll->s_game.scene == 4)
        sfRenderWindow_drawText(s_controll->s_game.window,
        s_controll->s_interface.end.lose, NULL);
    if (s_controll->s_game.scene == 5)
        sfRenderWindow_drawText(s_controll->s_game.window,
        s_controll->s_interface.end.win, NULL);
    sfRenderWindow_drawText(s_controll->s_game.window,
    s_controll->s_interface.end.your_score, NULL);
    sfRenderWindow_drawText(s_controll->s_game.window,
    s_controll->s_interface.end.score, NULL);
}