/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_ui.c
*/

#include "defender.h"

void free_ui(s_game *game)
{
    free(game->guide);
    free(game->menu->level);
    free(game->menu->guide);
    free(game->menu->score);
    free(game->menu->settings);
    free(game->menu);
}

void tower_switch_1(s_game *g, t_tower_menu m, v2 pos, sfSprite *sp)
{
    if (m.is_active) {
        m.sel_tower = sfSprite_copy(m.slot->sprite_tower);
        sfSprite_setPosition(m.sel_tower, (v2){pos.x + 96, pos.y + 41});
        sfRenderWindow_drawSprite(g->window, m.sprite_bg, NULL);
        sfRenderWindow_drawSprite(g->window, sp, NULL);
        if (m.slot->is_tower == sfTrue) {
            sfCircleShape_setPosition(g->tower_m.slot->area,
            (v2){g->tower_m.slot->pos.x, g->tower_m.slot->pos.y});
            sfRenderWindow_drawCircleShape(g->window, m.slot->area, NULL);
            sfRenderWindow_drawText(g->window, m.slot->tower->text_atk, NULL);
            sfRenderWindow_drawText
            (g->window, m.slot->tower->text_range, NULL);
            sfRenderWindow_drawSprite(g->window, m.sel_tower, NULL);
            button_draw(g->window, g->b_tower_upgrade, g, g->event);
        }
    }
}

void tower_switch_0(s_game *g, t_tower_menu m, v2 pos, sfSprite *sp)
{
    if (m.is_active) {
        sfRenderWindow_drawSprite(g->window, m.sprite_bg, NULL);
        sfRenderWindow_drawSprite(g->window, m.coins, NULL);
        button_draw(g->window, m.button_dam, g, g->event);
        button_draw(g->window, m.button_slow, g, g->event);
        button_draw(g->window, m.button_dot, g, g->event);
        button_draw(g->window, m.button_freez, g, g->event);
        sfRenderWindow_drawText(g->window, m.price_dam, NULL);
        sfRenderWindow_drawText(g->window, m.price_slow, NULL);
        sfRenderWindow_drawText(g->window, m.price_dot, NULL);
        sfRenderWindow_drawText(g->window, m.price_freez, NULL);
        if (m.slot->is_tower == sfTrue) {
            sfCircleShape_setPosition(g->tower_m.slot->area,
            (v2){g->tower_m.slot->pos.x, g->tower_m.slot->pos.y});
            sfRenderWindow_drawCircleShape(g->window, m.slot->area, NULL);
        }
    }
}

void tower_menu_draw(s_game *g)
{
    t_tower_menu m = g->tower_m;
    v2 pos = (v2){1920 / 1.5f, 1080 / 1.4f};
    sfSprite *sp = sfSprite_create();
    switch (m.slot->is_tower) {
        case 1:
            tower_switch_1(g, m, pos, sp);
            break;
        case 0:
            tower_switch_0(g, m, pos, sp);
            break;
        default:
            break;
    }
}

void toggle_tower_menu(s_game *g, s_slot *s)
{
    v2 pos = sfSprite_getPosition(g->tower_m.sprite_bg);
    if ((g->tower_m.is_active == sfFalse)) {
        g->tower_m.slot_id = s->id;
        g->tower_m.slot = s;
        g->tower_m.is_active = 1;
        put_text(&g->tower_m.title, to_string(s->id), pos, 32);
    }
    else if ((g->tower_m.is_active == sfTrue) && s->id == g->tower_m.slot_id) {
        g->tower_m.is_active = sfFalse;
    }
    else {
        g->tower_m.slot = s;
        g->tower_m.slot_id = s->id;
        put_text(&g->tower_m.title, to_string(s->id), pos, 32);
    }
}