/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** upgrade_menu_events
*/

#include "../../../include/elements.h"
#include "../../../include/mouse_events.h"

void update_name(main_game_t *g);

void update_ad(main_game_t *g);

void update_dps(main_game_t *g);

void update_image(main_game_t *g);

void upgrade_update(main_game_t *g)
{
    sfText_setString(g->sidebar->upgrade->ad_text->text, int_to_str(g->sidebar->
    upgrade->ad_str, g->turret_list[g->turret_selected]->ad));
    sfText_setString(g->sidebar->upgrade->cost_text->text, int_to_str
    (g->sidebar->upgrade->cost_str, g->turret_list[g->turret_selected]->cost));
    update_ad(g);
    update_dps(g);
    update_name(g);
    update_image(g);
    texts_set_colors(g->sidebar->upgrade);
    if (g->turret_list[g->turret_selected]->mode == 0)
        sfText_setString(g->sidebar->upgrade->range_text->text, "2");
    if (g->turret_list[g->turret_selected]->mode == 1)
        sfText_setString(g->sidebar->upgrade->range_text->text, "2.5");
    if (g->turret_list[g->turret_selected]->mode == 2)
        sfText_setString(g->sidebar->upgrade->range_text->text, "4");
    else if (g->turret_list[g->turret_selected]->mode == 3)
        sfText_setString(g->sidebar->upgrade->range_text->text, "8");
    sidebar_text_set_o(g->sidebar->upgrade);
}

void set_new_dps(turret_t *t)
{
    if (t->mode == 0)
        t->dps -= 100000;
    if (t->mode == 1)
        t->dps -= 100000;
    if (t->mode == 2)
        t->dps -= 500000;
    if (t->mode == 3)
        t->dps -= 500000;
}

void upgrade_event_extend(element_t *e, sfEvent event)
{
    if (button_is_clicked(e->game->sidebar->upgrade->delete_b, e->win, event)) {
        sfVector2f t_posf = sfSprite_getPosition
                (e->game->turret_list[e->game->turret_selected]->turret);
        float h =  (float)(1080.0 / (float)(get_len_array(e->game->map) - 1));
        int y_t = (int) (t_posf.y / h + 1);
        int x_t = (int)(t_posf.x / h);
        e->game->map[y_t][x_t] = 'I';
        turret_t *turret = e->game->turret_list[e->game->turret_selected];
        my_tab_rm_line((void **) e->game->turret_list,
                        e->game->turret_selected);
        e->game->turret_selected = -1;
        turret_destroy(turret);
    }
}

void upgrade_event(element_t *e, sfEvent event)
{
    if (e->game->turret_selected == -1) return;
    if (button_is_clicked(e->game->sidebar->upgrade->upgrade_b, e->win, event)
        && e->game->gold
        >= e->game->turret_list[e->game->turret_selected]->cost
        && !e->game->turret_list[e->game->turret_selected]->upgraded) {
        sound_set_status(e->click, "play");
        e->game->turret_list[e->game->turret_selected]->ad +=
                e->game->turret_list[e->game->turret_selected]->ad / 2;
        set_new_dps(e->game->turret_list[e->game->turret_selected]);
        e->game->turret_list[e->game->turret_selected]->upgraded = true;
        upgrade_update(e->game);
        e->game->gold -= e->game->turret_list[e->game->turret_selected]->cost;
    }
    upgrade_event_extend(e, event);
}