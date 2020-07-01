/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** game_loop
*/

#include "runner.h"

int game_loop(controll_t *s_controll)
{
    render_menu(s_controll);
    render_sounds(s_controll);
    render_texts(s_controll);
    render_interface(s_controll);
    sfRenderWindow_setFramerateLimit(s_controll->s_game.window, 60);
    if (!s_controll->s_game.window)
        return (EXIT_FAILURE);
    sfMusic_play(s_controll->s_music.background_sound);
    while (sfRenderWindow_isOpen(s_controll->s_game.window)) {
        while (sfRenderWindow_pollEvent(s_controll->s_game.window,
        &s_controll->s_game.event))
            event_controll(s_controll);
        game(s_controll);
    }
    destroy_background(s_controll), destroy_interface(s_controll);
    free_buttons(s_controll);
    return (0);
}