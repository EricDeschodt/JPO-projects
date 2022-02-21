/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** placing turrets
*/

#include "../../../include/game/turrets.h"
#include "../../../include/game/main_game.h"

bool is_map_case_correct(main_game_t *g, sfVector2i m_pos)
{
    float h =  (float)(1080.0 / (float)(get_len_array(g->map) - 1));
    int row_index = (int) (m_pos.y / (int) h + 1);
    int col_index = (int)(m_pos.x / (int) h);
    if (row_index >= get_len_array(g->map) || col_index >= get_greater_line
    (g->map)) return false;
    if (g->map[row_index][col_index] == 'I')
        return true;
    return false;
}

sfVector2i get_proper_pos(main_game_t *g, sfVector2i m_pos, bool is_turret)
{
    float h =  (float)(1080.0 / (float)(get_len_array(g->map) - 1));
    int row_index = (int) (m_pos.y / (int) h + 1);
    int col_index = (int)(m_pos.x / (int) h);
    int x = ((int) col_index * (int) h);
    int y = ((int) (row_index - 1) * (int) h);
    if (is_turret) {
        x += ((int) h / 2);
        y += ((int) h / 2);
        g->map[row_index][col_index] = 'J';
    }
    sfVector2i pos = {x, y};
    return pos;
}

int get_turret_cost(int nb)
{
    if (nb == 0)
        return 45;
    if (nb == 1)
        return 75;
    if (nb == 2)
        return 450;
    if (nb == 3)
        return 350;
    return 100;
}

void turret_place(main_game_t *g, sfEvent event, sfRenderWindow *win, int t_nb)
{
    if (t_nb == -1)
        return;
    int cost = get_turret_cost(t_nb);
    if (event_isclicked(event) && !button_is_on_over(g->sidebar->fond, win)) {
        sfVector2i m_pos = sfMouse_getPositionRenderWindow(win);
        if (is_map_case_correct(g, m_pos) && cost <= g->gold) {
            sfVector2i c_pos = get_proper_pos(g, m_pos, true);
            g->turret_list = turret_add(g, c_pos, t_nb);
            g->gold -= cost;
        }
        sfVector2f mf_pos = {(float)(m_pos.x), (float)(m_pos.y)};
        if (is_inmap(g->map, mf_pos) && g->gold < cost)
            g->sidebar->turrets->selected = -1;
    }
}