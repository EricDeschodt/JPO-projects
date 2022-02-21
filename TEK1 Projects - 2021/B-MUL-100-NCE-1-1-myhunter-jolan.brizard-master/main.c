/*
** EPITECH PROJECT, 2020
** test
** File description:
** main
*/

#include "my_hunter.h"

int loop(t_window *windw, t_sprite *sprite, t_audio *audio)
{
    sfEvent event;
    sfRenderWindow_setFramerateLimit(windw->window, 60);
    play_music(audio);
    sprites_coord(sprite);
    set_cursor(windw, sprite);
    sfRenderWindow_setMouseCursorVisible(windw->window, sfFalse);

    while (sfRenderWindow_isOpen(windw->window)) {
        while (sfRenderWindow_pollEvent(windw->window, &event))
            analyse_events(windw, event, sprite);
        draw_all(windw, sprite);
    }
    return 0;
}

void director(void)
{
    sfIntRect *crow = malloc(sizeof(sfIntRect));
    crow = define_crow_area(crow);
    sfIntRect *heart = malloc(sizeof(sfIntRect));
    heart = define_heart_area(heart);
    t_window *windw = malloc(sizeof(t_window));
    windw = define_window(windw);
    t_sprite *sprite = malloc(sizeof(t_sprite));
    sprite = define_sprite(sprite, crow, heart);
    t_audio *audio = malloc(sizeof(t_audio));
    audio = define_audio(audio);
    loop(windw, sprite, audio);
    destroy_all(windw, sprite, audio);
    clear_all(windw, sprite, audio);
    free(crow);
    free(heart);
}

int main(int ac, char **av)
{
    if (ac > 2)
        return 84;
    else if (ac == 2) {
        if (my_strcmp(av[1], "-h") != 0 && av[1] != NULL) {
            write(2, "Unknown command, "
                        "re run with '-h' for game's manual\n", 53);
            return 84;
        } else if (my_strcmp(av[1], "-h") == 0 && av[1] != NULL) {
            help_message();
            return 0;
        }
    }
    else
        director();
    return 0;
}