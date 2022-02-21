/*
** EPITECH PROJECT, 2020
** lib_include_makefile
** File description:
** Main File For Projects
*/

#include "../include/project.h"

void game_not_started(t_window *window)
{
    if (!(window->start) && !(window->end)) {
        draw_background(window);
        draw_title(window);
        idle_animation(window);
    } else if (window->end) {
        draw_background(window);
        draw_win_lose(window);
    }
}

void draw_all(t_window *window)
{
    sfRenderWindow_clear(window->window, sfBlack);
    if (window->start) {
        px_animation(window, 9);
        draw_map(window);
        ch_anim(window);
        draw_score(window);
        window->text->s += 1;
    } else
        game_not_started(window);
    sfRenderWindow_display(window->window);
}

void game_loop(t_window *window)
{
    sfEvent event;
    play_music(window);

    while (sfRenderWindow_isOpen(window->window)) {
        while (sfRenderWindow_pollEvent(window->window, &event))
            analyse_events(window, event);
        draw_all(window);
    }
}

short director(char **av)
{
    t_map *map = malloc(sizeof(t_map));
    map = define_map(map);
    if (!(map_valid(map, av))) {
        return 84;
    }
    t_window *window = malloc(sizeof(t_window));
    window = define_window(window);
    window->map = map;
    load_map(window->map);
    game_loop(window);
    destroy_all(window);
    clear_all(window);
    return 0;
}

int main(int ac, char **av)
{
    int error_status = error_handling(ac, av);
    if (error_status == 84)
        return 84;
    else if (error_status == 1)
        return 0;
    if (director(av) == 84)
        return 84;
    return 0;
}