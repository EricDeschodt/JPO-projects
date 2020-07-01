/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** start
*/

#include "defender.h"

int main(int ac, char **av)
{
    all_t s_all;
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) message();
    else if (ac == 1) {
        init_all(&s_all);
        game_loop(&s_all);
        destroy_regroup(&s_all);
    } else {
        write(2, "WRONG ARG", 9);
        return (84);
    } return (EXIT_SUCCESS);
}