/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** pause_menu.c
*/

#include "defender.h"

void on_resume(void *data)
{
    s_game *g = (s_game *)data;
    g->released = sfTrue;
    g->g_pause.paused = sfFalse;
    for (int i = 0; i < g->w_len[g->w_nb]; i++) {
        g->enemies[g->levels][g->w_nb][i]->mob->movetime =
        sfClock_restart
        (g->enemies[g->levels][g->w_nb][i]->mob->moveclock);
    }
}

void on_menu(void *data)
{
    s_game *g = (s_game *)data;
    g->state = MENU;
    restart(g);
}

void on_set(void *data)
{

}

void init_pause(s_game *g)
{
    sfVector2u s = g->w_size;
    float y = s.y;
    float f = 2;
    v2 pos = (v2){s.x/f, y/f};
    game_pause_t *p = &g->g_pause;
    sfTexture *bg_tex = sfTexture_createFromFile("res/pause_bg.png", NULL);
    p->bg = sfSprite_create();
    sfSprite_setTexture(p->bg, bg_tex, 1);
    p->title = init_text();
    p->b_res = button_create("RESUME", pos, &on_resume, NULL);
    p->b_menu = button_create("MENU", (v2){s.x/f, y / 1.6}, &on_menu, NULL);
    p->b_sett = button_create("SETTINGS", (v2){s.x/f, y / 1.33},
    &on_set, NULL);
    p->b_quit = button_create("QUIT", (v2){s.x/f, y / 1.14}, &on_quit, NULL);
    put_text(&g->g_pause.title, "GAME PAUSED", (v2){1920/f, 1080/4}, 32);
    text_center(&g->g_pause.title);
}

void pause_draw(s_game *g)
{
    game_pause_t *p = &g->g_pause;
    sfVector2u s = g->w_size;
    p->b_quit->pos = (v2){s.x/2, s.y/1.1};
    sfRenderWindow_drawSprite(g->window, g->g_pause.bg, NULL);
    sfRenderWindow_drawText(g->window, g->g_pause.title, NULL);
    button_draw(g->window, g->g_pause.b_res, g, g->event);
    button_draw(g->window, g->g_pause.b_menu, g, g->event);
    button_draw(g->window, g->g_pause.b_sett, g, g->event);
    button_draw(g->window, g->g_pause.b_quit, g, g->event);
}