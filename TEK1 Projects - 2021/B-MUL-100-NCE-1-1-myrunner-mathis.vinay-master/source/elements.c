/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** fnc to handle the elements struct
*/

#include "../include/elements.h"

elements_t *create_elements(char *filename)
{
    elements_t *e = malloc(sizeof(elements_t));
    e->map = create_map(filename, "assets/tileset.png");
    if (!e->map)
        return free_null(e);
    e->b = create_backgrounds();
    e->chr = create_character("assets/spritesheet.png");
    e->time = create_time();
    e->audio = create_audio();
    e->window = create_window("My Runner");
    e->menu = -1;
    e->score = create_score("assets/Panic.ttf", "0000000");
    e->interface = create_interface();
    return e;
}

elements_t *display_elements(elements_t *e)
{
    sfRenderWindow_clear(e->window, sfBlack);
    display_backgrounds(e->window, e->b);
    display_map(e->window, e->map);
    display_interface(e->window, e->interface, e->menu);
    if (e->menu == 1)
        sfRenderWindow_drawSprite(e->window, e->chr->sprite, NULL);
    if (e->menu != -1) {
        sfRenderWindow_drawText(e->window, e->score->label, NULL);
        sfRenderWindow_drawText(e->window, e->score->text, NULL);
    }
    sfRenderWindow_display(e->window);
    return e;
}

bool animate_elements(elements_t *e)
{
    bool map = true;
    bool chr = true;
    if (e->menu != 1) {
        sfClock_restart(e->time->clock);
        return true;
    }
    add_elapsed_time(e->time);
    while (e->time->anime_microseconds > 100000) {
        change_frame(e->chr);
        e->time->anime_microseconds -= 100000;
    }
    while (e->time->moove_microseconds > 16666) {
        chr = chr_apply_gravity(e->map, e->chr, 30, (float)(0.30));
        animate_backgrounds(e->b, 17);
        map = animate_map(e->map, e->chr, 17);
        add_score(e->score);
        e->time->moove_microseconds -= 16666;
    }
    return (map && chr);
}

void destroy_elements(elements_t *e)
{
    sfRenderWindow_destroy(e->window);
    destroy_backgrounds(e->b);
    destroy_map(e->map);
    destroy_character(e->chr);
    destroy_time(e->time);
    destroy_audio(e->audio);
    destroy_score(e->score);
    destroy_interface(e->interface);
    free(e);
}