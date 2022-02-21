/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** Handling Errors
*/

#include "../include/project.h"

bool map_valid(t_map *map, char **av)
{
    int fd = open(av[1], O_RDONLY);
    int reader = read(fd, map->buf, 1446);
    if (fd == -1 || reader == -1) {
        write(2, "Invalid map_filepath - run with '-h'\n", 38);
        close(fd);
        sfTexture_destroy(map->obs_texture);
        sfSprite_destroy(map->obs);
        sfClock_destroy(map->clock);
        free(map->tab);
        free(map->buf);
        free(map);
        return false;
    }
    close(fd);
    return true;
}

int error_handling(int ac, char **av)
{
    if (ac > 2) {
        write(2, "Invalid Argument: try to run with '-h' flag\n", 45);
        return 84;
    }
    if (ac == 2 && my_strcmp("-h", av[1]) == 0) {
        help_message();
        return 1;
    }
    else
        return 0;
}

void help_message(void)
{
    write(1, "The Lonely Runner\n\nOn his way back home, the Ronin"
                " is searching for redemption, help him to make his way !\n\n"
                "USAGE:\n\n\tRun the program using"
                " './my_runner [map_filepath]'command.\n"
                "\tPress 'ENTER' to start a run.\n\t"
                "Press 'TAB' to return to Home Menu.\n\t"
                "Press 'SPACE' to jump and a avoid enemies.\n"
                "\tPress 'ESCAPE' to exit game.\n\n"
                "You are now ready to begin your journey !\n\n", 363);
}