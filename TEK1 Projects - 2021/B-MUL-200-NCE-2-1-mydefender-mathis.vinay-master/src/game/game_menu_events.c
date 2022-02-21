/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Game events
*/

#include "../../include/elements.h"
#include "../../include/mouse_events.h"

void sidebar_update_mode(element_t *e)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(e->win);
    float h =  (float)(1080.0 / (float)(get_len_array(e->game->map) - 1));
    int y = (int) (m_pos.y / (int) h + 1);
    int x = (int)(m_pos.x / (int) h);
    if (e->game->map[y][x] == 'J') {
        for (int i = 0; e->game->turret_list[i]; i++) {
            sfVector2f t_posf = sfSprite_getPosition
            (e->game->turret_list[i]->turret);
            int y_t = (int) (t_posf.y / h + 1);
            int x_t = (int)(t_posf.x / h);
            if (x == x_t && y == y_t) {
                e->game->turret_selected = i;
                upgrade_update(e->game);
            }
        }
    } else if (e->game->turret_selected != -1)
        e->game->turret_selected = -1;
}

void game_menu(element_t *e, sfEvent event)
{
    if ((button_is_clicked(e->game->sidebar->pause_button, e->win, event)) ||
    event_escape(event) || event_enter(event)) {
        music_set_status(e->music_beach, "pause");
        music_set_status(e->music_menu, "stop");
        sound_set_status(e->click, "play");
        e->game->time->is_paused = true;
        e->mode = 3;
    }
    if (event_isclicked(event)) {
        sfVector2i m_pos = sfMouse_getPositionRenderWindow(e->win);
        sfVector2f m_posf = {(float) m_pos.x, (float) m_pos.y};
        if (is_inmap(e->game->map, m_posf) && !button_is_on_over
        (e->game->sidebar->fond, e->win) &&
        e->game->sidebar->turrets->selected == -1)
            sidebar_update_mode(e);
        turret_place(e->game, event, e->win,
        e->game->sidebar->turrets->selected);
        if (e->game->turret_selected == -1)
            radio_buttons_update_selection(e->game->sidebar->turrets, e->win);
    }
}