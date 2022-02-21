/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-jolan.brizard
** File description:
** Set window
*/

#include "../include/project.h"

sfRenderWindow *create_window(unsigned int x, unsigned int y,
                                unsigned int bpp, char *window_title)
{
    sfVideoMode video_mode = {x, y, bpp};
    return (sfRenderWindow_create(video_mode, window_title, sfClose, NULL));
}

void define_all(t_window *window)
{
    window->px = malloc(sizeof(t_parallax));
    window->text = malloc(sizeof(t_text));
    window->rect = malloc(sizeof(t_rect));
    window->sprite = malloc(sizeof(t_sprite));
    window->text = define_text(window->text);
    window->px = define_px(window->px);
    window->rect = define_rect(window->rect, window->px);
    window->sprite = define_sprite(window->sprite);
}

t_window *define_window(t_window *window)
{
    define_all(window);
    window->window = create_window(1280, 720, 32, "LonelyRunner");
    window->start = false;
    window->end  = false;
    window->clock = sfClock_create();
    set_audio(window);
    sfRenderWindow_setKeyRepeatEnabled(window->window, sfFalse);
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    return (window);
}

void clear_all(t_window *window)
{
    free(window->px);
    free(window->sprite);
    free(window->text->s_score);
    free(window->text);
    free(window->map->tab);
    free(window->map->buf);
    free(window->map);
    free(window->rect);
    free(window);
}