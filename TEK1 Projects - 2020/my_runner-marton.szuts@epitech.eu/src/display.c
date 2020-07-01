/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** display
*/

#include "runner.h"

void game_scene(controll_t *s_controll)
{
    sfRenderWindow_clear(s_controll->s_game.window, sfBlack);
    display_background(s_controll),
    display_runner(s_controll);
    display_coins(s_controll), display_monster(s_controll);
    display_obstacle(s_controll), display_jelly(s_controll);
    if (s_controll->s_game.scene == 2) {
        display_pause(s_controll);
        display_stopped(s_controll);
        check_on_button(s_controll);
    }
    display_coin_interface(s_controll);
    display_texts(s_controll);
    sfRenderWindow_display(s_controll->s_game.window);
}

void menu_scene(controll_t *s_controll)
{
    sfRenderWindow_clear(s_controll->s_game.window, sfBlack);
    display_background(s_controll);
    sfRenderWindow_drawSprite(s_controll->s_game.window,
    s_controll->s_title.sprite, NULL);
    if (s_controll->s_game.scene == 0) {
        sfRenderWindow_drawText(s_controll->s_game.window,
        s_controll->s_interface.your_best, NULL);
        sfRenderWindow_drawText(s_controll->s_game.window,
        s_controll->s_interface.best, NULL);
        display_buttons(s_controll);
    }
    else
        display_levels(s_controll);
    sfRenderWindow_display(s_controll->s_game.window);
}

void end_scene(controll_t *s_controll)
{
    buttons_t *temp;
    buttons_t *temp2;
    init_clocks3(s_controll);
    sfRenderWindow_clear(s_controll->s_game.window, sfBlack);
    display_background(s_controll);
    display_dead(s_controll);
    if (s_controll->s_game.scene == 4) {
        temp = get_last_node(s_controll->s_pause);
        temp2 = temp->next;
        temp->next = NULL;
        display_pause(s_controll);
        temp->next = temp2;
    }
    else
        display_levels(s_controll);
    display_end_txts(s_controll);
    sfRenderWindow_display(s_controll->s_game.window);
}

void game(controll_t *s_controll)
{
    if (s_controll->s_game.scene == 1 || s_controll->s_game.scene == 2) {
        animation(s_controll), setpos_background(s_controll);
        touch_obstacle(s_controll), touch_coin(s_controll);
        touch_monster(s_controll), game_scene(s_controll);
        winning_check(s_controll);
        if (s_controll->s_state.lose == 1)
            end_game(s_controll);
    }
    if (s_controll->s_game.scene == 0 || s_controll->s_game.scene == 3) {
        check_on_button(s_controll);
        menu_scene(s_controll);
    }
    if (s_controll->s_game.scene == 4) {
        check_on_button(s_controll);
        end_scene(s_controll);
    }
    if (s_controll->s_game.scene == 5)
        show_win(s_controll);
}