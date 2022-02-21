/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Draws the map
*/

#include "../../include/game/main_game.h"

void draw_proper_indicator(main_game_t *game, sfRenderWindow *win, int mode)
{
    if (mode == 0 && game->gold < 45 || mode == 1 && game->gold < 75
        || mode == 2 && game->gold < 450 || mode == 3 && game->gold < 350) {
        sprite_set_texturerect_pos(game->t_indic, 256 / 2, 0);
        sprite_display(game->t_indic, win);
        return;
    }
    sprite_set_texturerect_pos(game->t_indic, 0, 0);
    sprite_display(game->t_indic, win);
}

void set_mouse_indicator(main_game_t *game, sfRenderWindow *win, int mode,
sfVector2i pos)
{
    float h =  (float)(1080.0 / (float)(get_len_array(game->map) - 1));
    float ratio = (float) ((100 * h) / 900) / 100;
    if (mode == 0)
        sprite_set_pos(game->range_indicator, (float) pos.x + (h / 2) + 5,
        (float) pos.y + (h / 2), 2 * ratio);
    if (mode == 1)
        sprite_set_pos(game->range_indicator, (float) pos.x + (h / 2) + 5,
        (float) pos.y + (h / 2), (float) 2.5 * ratio);
    if (mode == 2)
        sprite_set_pos(game->range_indicator, (float) pos.x + (h / 2) + 5,
        (float) pos.y + (h / 2), 4 * ratio);
    if (mode == 3)
        sprite_set_pos(game->range_indicator, (float) pos.x + (h / 2) + 5,
        (float) pos.y + (h / 2), 8 * ratio);
    sprite_display(game->range_indicator, win);
}

void turret_indicator_selector(main_game_t *g, struct sfRenderWindow *win)
{
    sfVector2f pos_t = sfSprite_getPosition
    (g->turret_list[g->turret_selected]->turret);
    sfVector2i m_pos_t = {(int)(pos_t.x), (int)(pos_t.y)};
    m_pos_t = get_proper_pos(g, m_pos_t, false);
    set_mouse_indicator(g, win, g->turret_list[g->turret_selected]->mode,
    m_pos_t);
}

void turret_indicator_display(main_game_t *g, sfRenderWindow *win)
{
    if (g->sidebar->turrets->selected != -1) {
        sfVector2i m_pos = sfMouse_getPositionRenderWindow(win);
        sfVector2f m_posf = {(float) m_pos.x, (float) m_pos.y};
        if (is_map_case_correct(g, m_pos) && !button_is_on_over
            (g->sidebar->fond, win)) {
            sfVector2i c_pos = get_proper_pos(g, m_pos, false);
            sprite_set_pos(g->t_indic, (float)(c_pos.x), (float)(c_pos.y), 0);
            set_mouse_indicator(g, win, g->sidebar->turrets->selected, c_pos);
            draw_proper_indicator(g, win, g->sidebar->turrets->selected);
        } else if (is_inmap(g->map, m_posf) && !button_is_on_over
        (g->sidebar->fond, win)) {
            sfVector2i c_pos = get_proper_pos(g, m_pos, false);
            sprite_set_pos(g->t_indic, (float) (c_pos.x), (float)(c_pos.y), 0);
            sprite_set_texturerect_pos(g->t_indic, 256 / 2, 0);
            sprite_display(g->t_indic, win);
        }
    }
    if (g->turret_selected != -1)
        turret_indicator_selector(g, win);
}

void map_display(main_game_t *game, sfRenderWindow *win)
{
    float h =  (float)(1080.0 / (float)(get_len_array(game->map) - 1));
    for (int i = 1; game->map[i]; i++) {
        for (int j = 0; game->map[i][j]; j++) {
            char c = game->map[i][j];
            c = (char)((c == 'Q' || c == 'S')?'A':c);
            c = (char)((c == 'R' || c == 'T')?'B':c);
            c -= 'A';
            sprite_set_texturerect_pos(game->map_tampon, 256 * (c % 4), 256 *
            (c / 4));
            sprite_set_pos(game->map_tampon, (float)j * h, (float)(i - 1) * h,
            0);
            sprite_display(game->map_tampon, win);
        }
    }
}