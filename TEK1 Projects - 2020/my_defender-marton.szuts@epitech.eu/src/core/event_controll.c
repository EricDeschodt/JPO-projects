/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** event_controll
*/

#include "defender.h"

void event_controll_buttons2(all_t *s_all)
{
    if (s_all->s_game.scene == 1 && s_all->s_game.pause != 1) {
        click_sell_button(s_all);
        hitbox_pause_button(s_all), hitbox_wave_button(s_all);
        place_turret(s_all), click_selected_turret(s_all);
        hitbox_slider_arrow(s_all), hitbox_change_targetting_next(s_all);
        hitbox_change_targetting_back(s_all), hitbox_upgrade_button(s_all);
        if (s_all->s_selected.tur != NULL) {
            hitbox_change_targetting_next_turret(s_all,
                s_all->s_selected.tur->target);
            hitbox_change_targetting_back_turret(s_all,
                s_all->s_selected.tur->target);
        } click_support(s_all);
        hitbox_abilities(s_all);
    }
}

void event_controll_buttons(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtMouseButtonPressed) {
        menu_press_buttons(s_all);
        if (s_all->s_game.scene == 4)
            settings_press_buttons(s_all);
        event_controll_buttons2(s_all);
        map_editor_click(s_all), map_selector_click(s_all);
        custom_map_selector_click(s_all);
    } else if (s_all->s_game.event.type == sfEvtMouseButtonReleased) {
        custom_map_selector_release(s_all);
        map_selector_release(s_all), menu_release_buttons(s_all);
        release_slider_arrow(s_all), release_pause_button(s_all);
        release_wave_button(s_all), release_sell_button(s_all);
        release_upgrade_button(s_all), map_editor_release(s_all);
    }
}

void event_controll(all_t *s_all)
{
    static int pause = 0;
    if (s_all->s_game.event.type == sfEvtClosed) {
        sfRenderWindow_close(s_all->s_game.window);
        write_statistics(s_all);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == 1 && pause == 0
    && s_all->s_game.scene == 1 && s_all->s_player.defeat == 0) {
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
        pause = 1;
        if (s_all->s_game.pause == 0)
            s_all->s_game.pause = 1;
        else
            s_all->s_game.pause = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == 0)
        pause = 0;
    event_controll_buttons(s_all);
}