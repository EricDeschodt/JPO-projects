/*
** EPITECH PROJECT, 2019
** start
** File description:
** start
*/

#include "runner.h"
#include "map.h"

int check_arg(char *str)
{
    int fd = open(str, O_RDONLY);
    if (fd >= 0) {
        close(fd);
        return (1);
    }
    close(fd);
    return (0);
}

int main(int ac, char **av)
{
    controll_t *s_controll = malloc(sizeof(controll_t));
    s_controll->s_game.scene = 0, s_controll->s_game.speed = 0;
    s_controll->s_state.lose = 0, s_controll->s_game.infinite = 0;
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) message();
    else if (ac == 2) {
        sfVideoMode mode = {1920, 1080, 32};
        if (!check_arg(av[1])) return (84);
        s_controll->current_map = my_strdup(av[1]);
        s_controll->arg_map = my_strdup(av[1]);
        s_controll->s_game.window =
        sfRenderWindow_create(mode, "RUNNER", sfClose, NULL);
        sfRenderWindow_setPosition(s_controll->s_game.window,
        (sfVector2i){0, 0}), game_loop(s_controll);
    }
    else {
        write(2, "WRONG ARG", 9);
        return (84);
    }
    free(s_controll);
    return (EXIT_SUCCESS);
}