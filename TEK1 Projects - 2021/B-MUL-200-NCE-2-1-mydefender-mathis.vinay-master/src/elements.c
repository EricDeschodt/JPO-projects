/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** main struct functions
*/

#include "../include/elements.h"
#include "../include/mouse_events.h"

element_t *elements_create(void)
{
    element_t *e = malloc(sizeof(element_t));
    e->mode = 0;
    e->win = window_create("Proteccc", 1920, 1080, 60);
    e->main = main_menu_create();
    e->level = level_menu_create();
    e->back = background_create();
    e->end = end_game_create();
    e->pause = pause_menu_create();
    e->score = scoreboard_create();
    e->htp = create_htp();
    e->manual = manual_create();
    e->setting = setting_create();
    e->game = main_game_create(e->setting->t_volume);
    sounds_create(e);
    return e;
}

void elements_display(element_t *e)
{
    sfRenderWindow_clear(e->win, sfBlack);
    if (e->mode == 0) {
        background_display(e->back, e->win);
        main_menu_display(e->main, e->win);
    } else if (e->mode == 1) {
        background_display(e->back, e->win);
        level_menu_display(e->level, e->win);
    }
    if (e->mode == 2)
        main_game_display(e->game, e->win, true);
    if (e->mode == 3) {
        main_game_display(e->game, e->win, false);
        pause_menu_display(e->pause, e->win);
    }
    if (e->mode == 4) {
        background_display(e->back, e->win);
        end_game_display(e->end, e->win);
    }
    element_display_x(e);
    sfRenderWindow_display(e->win);
}

void element_events_handling(element_t *e)
{
    sfEvent event = {};
    while (sfRenderWindow_pollEvent(e->win, &event)) {
        event_close(e->win, event);
        mouse_events(e, event);
    }
}

void elements_animate(element_t *e)
{
    if (e->mode == 0 || e->mode == 1 || e->mode == 4 || e->mode == 5
        || e->mode == 6 || e->mode == 7 || e->mode == 8)
        background_animate(e->back, e->mode);
    if (e->mode == 2)
        if (!main_game_animate(e->game)) {
            music_set_status(e->music_beach, "stop");
            music_set_status(e->music_menu, "play");
            e->mode = 4;
            sprite_set_texturerect_pos(e->back->perso, 0, 134);
            scoreboard_add_score(
                e->level->lvl->list_lvl[e->level->lvl->list_index],
                e->game->wave);
            endgame_add_your_score(e->end, e->game->wave);
        }
}

void elements_destroy(element_t *e)
{
    sfRenderWindow_destroy(e->win);
    main_menu_destroy(e->main);
    level_menu_destroy(e->level);
    background_destroy(e->back);
    main_game_destroy(e->game, true);
    end_game_destroy(e->end);
    pause_menu_destroy(e->pause);
    scoreboard_destroy(e->score);
    htp_destroy(e->htp);
    manual_destroy(e->manual);
    sounds_destroy(e);
    free(e);
}