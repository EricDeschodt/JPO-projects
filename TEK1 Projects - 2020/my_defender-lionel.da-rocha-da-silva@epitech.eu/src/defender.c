/*
** EPITECH PROJECT, 2020
** defender
** File description:
** defender
*/

#include "defender.h"

void create_world(s_game *game)
{
    game->mode.width = 1920, game->mode.height = 1080,
    game->mode.bitsPerPixel = 32;
    game->window = sfRenderWindow_create(game->mode,
        "MY_DEFENDER", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, game->framerate);
    sfRenderWindow_setKeyRepeatEnabled(game->window, sfFalse);
    game->w_size = sfRenderWindow_getSize(game->window);
    menu_init(game);
    game_init(game);
}

void analyse_events(s_game *game)
{
    sfBool ctrl_d = on_key_released(sfKeyEscape & sfKeyD, &game);

    if (game->event.type == sfEvtClosed || ctrl_d)
        sfRenderWindow_close(game->window);
    toggle_pause(&game);
    if (game->state == MENU && game->menu->pages_state != NEG &&
        sfKeyboard_isKeyPressed(sfKeyEscape))
            game->menu->pages_state = NEG;
}

void update_world(s_game *game)
{
    route_all_updates(game);
}

void draw_world(s_game *game)
{
    route_draw_calls(game);
}

int main(int ac, char **av)
{
    s_game game;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        usage();
        return 0;
    }
    if (ac != 1  || (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' &&
    av[1][2] == '\0')) {
        write(2, "Try ./my_defender -h for help.\n", 31);
        return 84;
    }
    init_game_struct(&game);
    create_world(&game);
    read_guide(&game);
    game_loop(&game);
    free_ui(&game);
    sfRenderWindow_destroy(game.window);
}