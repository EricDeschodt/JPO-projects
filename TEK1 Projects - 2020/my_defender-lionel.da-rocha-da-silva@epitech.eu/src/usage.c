/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** usage
*/

#include "defender.h"

void game_loop(s_game *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        game->event.type = -1;
        while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            analyse_events(game);
            game->e = game->event;
        }
        update_world(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_setFramerateLimit(game->window, game->framerate);
        draw_world(game);
        sfRenderWindow_display(game->window);
    }
}

void usage(void)
{
    int fd = open("maps/usage.txt", O_RDONLY);
    char *s = get_next_line(fd);

    while (s) {
        write(1, s, my_strlen(s));
        write(1, "\n", 1);
        free(s);
        s = get_next_line(fd);
    }
    free(s);
}