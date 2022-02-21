/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** update_elements.c
*/

#include "defender.h"
#include "my.h"

static void draw_menu_items(vars_t *va, game_t *gm)
{
    sfVector2f pos_score = {800, 95};
    sfVector2f pos_money = {1203, 85};
    sfVector2f pos_killed = {1650, 95};
    int menus[] = { 6, 3, 3 };
    char *score_t = my_get_str(gm->it[0]->info.score);
    char *money_t = my_get_str(gm->it[0]->info.money);
    char *killed_t = my_get_str(gm->it[0]->info.killed);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < menus[i]; j++)
            sfRenderWindow_drawRectangleShape(va->window,  \
                                                    gm->it[i]->rect[j], NULL);
    gm->it[0]->info.killed_t = create_text(pos_killed, killed_t, 50, sfBlack);
    gm->it[0]->info.money_t = create_text(pos_money, money_t, 50, sfBlack);
    gm->it[0]->info.score_t = create_text(pos_score, score_t, 50, sfBlack);
    sfRenderWindow_drawText(va->window, gm->it[0]->info.killed_t, NULL);
    sfRenderWindow_drawText(va->window, gm->it[0]->info.money_t, NULL);
    sfRenderWindow_drawText(va->window, gm->it[0]->info.score_t, NULL);
}

static void update_wave(wave_t *wave)
{
    int phase = 60;
    int time = 0;

    if (wave->status == 2) {
        time = sfClock_getElapsedTime(wave->start_clock).microseconds / 1000000;
    }
    if (time >= phase || wave->skip) {
        wave->status = 0;
        wave->skip = 0;
    } else {
        sfText_setString(wave->time_left->text, my_get_str(phase - time));
    }
}

static void render_wave_timer(sfRenderWindow *win, wave_t *wave)
{
    if (wave->status == 0) return;
    sfRenderWindow_drawRectangleShape(win, wave->skip_timer->rect, NULL);
    sfRenderWindow_drawRectangleShape(win, wave->time_left->rect,  NULL);
    sfRenderWindow_drawText(win, wave->skip_timer->text, NULL);
    sfRenderWindow_drawText(win, wave->time_left->text,  NULL);
}

void draw_overlay_onclick(vars_t *va, game_t *gm, int index)
{
    sfRenderWindow_drawRectangleShape(va->window, gm->it[0]->filter, NULL);
    display_terrain_overlay(va, gm->it, index);
    sfRenderWindow_drawRectangleShape(va->window, gm->it[0]->temp.rect, NULL);
}

void update_elements(vars_t *va, game_t *gm)
{
    sfRenderWindow_drawSprite(va->window, gm->mn->map, NULL);
    draw_menu_items(va, gm);
    if (gm->it[0]->info.check.x == -1) draw_overlay_onclick(va, gm, 1);
    if (gm->it[0]->info.check.x == -2) draw_overlay_onclick(va, gm, 2);
    if (gm->it[0]->info.check.x == -3) draw_overlay_onclick(va, gm, 3);
    if (gm->wave->status != 0) {
        update_wave(gm->wave);
        handle_skip_button(va->window, gm->wave);
        render_wave_timer(va->window, gm->wave);
    }
    check_if_enemy_in_lane(gm);
    update_towers(va, gm->tw, gm);
    update_bullets(va->window, gm);
    handle_enemy_shot(gm);
    update_enemies(va, gm);
    handle_player_health_bar(va->window, gm);
}
