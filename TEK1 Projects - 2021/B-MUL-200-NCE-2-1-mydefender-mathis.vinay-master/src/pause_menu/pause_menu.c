/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handles the pause menu
*/

#include "../../include/pause_menu.h"

pause_menu_t *pause_menu_create(void)
{
    pause_menu_t *p = malloc(sizeof(pause_menu_t));
    p->exit_button = button_create("assets/gui/exit_button.png", "C");
    p->main_menu_button = button_create("assets/gui/menu_button.png", "C");
    p->resume_button = button_create("assets/gui/resume_button.png", "C");
    p->shade = sprite_create("assets/gui/shade.png", "C", false, false);
    p->restart_button = button_create("assets/gui/restart_button.png", "C");
    p->htp_button = button_create("assets/gui/help_button.png", "C");
    p->cadre = sprite_create("assets/gui/pause_fond.png", "C", false, false);
    p->setting_b = button_create("assets/gui/setting_button.png", "C");
    sprite_set_pos(p->setting_b, 250, 840, 1);
    sprite_set_pos(p->htp_button, 250, 950, 1);
    sprite_set_pos(p->exit_button, 960, 670, 1);
    sprite_set_pos(p->main_menu_button, 960, 560, 1);
    sprite_set_pos(p->restart_button, 960, 450, 1);
    sprite_set_pos(p->resume_button, 960, 340, 1);
    sprite_set_pos(p->shade, 0, 0, 100);
    sprite_set_pos(p->cadre, 960, 505, 1);
    return p;
}

void pause_menu_display(pause_menu_t *pause_menu, sfRenderWindow *win)
{
    sprite_display(pause_menu->shade, win);
    sprite_display(pause_menu->cadre, win);
    button_display(pause_menu->resume_button, win, true);
    button_display(pause_menu->exit_button, win, true);
    button_display(pause_menu->main_menu_button, win, true);
    button_display(pause_menu->htp_button, win, true);
    button_display(pause_menu->restart_button, win, true);
    button_display(pause_menu->setting_b, win, true);
}

void pause_menu_destroy(pause_menu_t *pause_menu)
{
    sprite_destroy(pause_menu->cadre);
    sprite_destroy(pause_menu->exit_button);
    sprite_destroy(pause_menu->main_menu_button);
    sprite_destroy(pause_menu->resume_button);
    sprite_destroy(pause_menu->shade);
    sprite_destroy(pause_menu->htp_button);
    sprite_destroy(pause_menu->restart_button);
    sprite_destroy(pause_menu->setting_b);
    free(pause_menu);
}