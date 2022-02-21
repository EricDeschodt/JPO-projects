/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** main_loop
*/

#include "defender.h"

static int event_handler(vars_t *va)
{
    if (va->event.type == sfEvtClosed)
        sfRenderWindow_close(va->window);
    if (va->event.key.code == sfKeyEscape)
        return (1);
    return (0);
}

static int handle_clock_enemies(game_t *gm, sfClock *clock)
{
    if (GET_TIME_EVERY_S(clock, 2, 1000000)) {
        new_enemies(gm);
        return (1);
    }
    return (0);
}

static int game_updates(game_t *gm, framebuffer_t *fb, vars_t *va)
{
    int paused = 0;

    update_elements(va, gm);
    while (sfRenderWindow_pollEvent(va->window, &va->event))
        paused = event_handler(va);
    if (paused != 0) paused = pause_menu(fb, va, gm);
    update_user_action(va, gm);
    return (paused);
}

static void handle_game_clock(game_t *gm, sfClock *clock)
{
    if ((gm->wave->skip || GET_TIME_EVERY_S(gm->wave->start_clock, 60,   \
    1000000)) && handle_clock_enemies(gm, clock))
    sfClock_restart(clock);
}

void game(framebuffer_t *fb, vars_t *va, menu_t *mn)
{
    sfClock *clock = sfClock_create();
    game_t *gm = init_game();
    int paused = 0;

    WAIT_FOR_BUTTON_RELEASE;
    while (gm->life->points.y > 0 && paused != 3    \
    && paused != 2 && sfRenderWindow_isOpen(va->window)) {
        sfRenderWindow_clear(va->window, sfBlack);
        paused = game_updates(gm, fb, va);
        handle_game_clock(gm, clock);
        sfTexture_updateFromPixels(va->texture, fb->pixels,    \
                                    fb->width, fb->height, 0, 0);
        sfRenderWindow_display(va->window);
    }
    mn->state = 1;
    sfMusic_destroy(gm->sound[0]);
    sfMusic_destroy(gm->sound[1]);
    sfMusic_destroy(gm->sound[2]);
    if (gm->life->points.y > 0 && paused == 2) game(fb, va, mn);
}
