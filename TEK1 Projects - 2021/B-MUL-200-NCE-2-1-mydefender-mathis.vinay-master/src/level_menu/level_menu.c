/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Handles the level menu
*/

#include "../../include/level_menu.h"

void level_menu_create_x(level_menu_t *level_menu)
{
    level_menu->button_score =
            button_create("assets/gui/scoreboard.png", "C");
    sprite_set_pos(level_menu->button_score, 1500, 850, 1);
    level_menu->htp_button = button_create("assets/gui/help_button.png", "C");
    sprite_set_pos(level_menu->htp_button, 420, 850, 1);
}

level_menu_t *level_menu_create(void)
{
    level_menu_t *level_menu = malloc(sizeof(level_menu_t));
    level_menu->button_left = button_create("assets/gui/l_button.png", "C");
    sprite_set_pos(level_menu->button_left, 550, 370, (float) 1);
    level_menu->button_right = button_create("assets/gui/r_button.png", "C");
    sprite_set_pos(level_menu->button_right, 1350, 370, (float) 1);
    level_menu->button_return = button_create("assets/gui/return_button"
    ".png", "C");
    sprite_set_pos(level_menu->button_return, 960, 850, 1);
    level_menu->button_select = button_create("assets/gui/select_button"
    ".png", "C");
    sprite_set_pos(level_menu->button_select, 960, 725, 1);
    level_menu->shadow = sprite_create("assets/gui/shadow.png", "C", false,
    true);
    sprite_set_pos(level_menu->shadow, 960, 300, (float)0.55);
    level_menu_create_x(level_menu);
    level_menu->lvl = levels_create();
    level_menu->time = time_create();
    return level_menu;
}

void level_menu_init(level_menu_t *menu)
{
    menu->lvl->list_index = 0;
    levels_update(menu->lvl);
}

void level_menu_display(level_menu_t *level_menu, sfRenderWindow *win)
{
    sprite_display(level_menu->shadow, win);
    button_display(level_menu->button_select, win, true);
    button_display(level_menu->button_return, win, true);
    button_display(level_menu->button_left, win, true);
    button_display(level_menu->button_right, win, true);
    button_display(level_menu->button_score, win, true);
    button_display(level_menu->htp_button, win, true);
    levels_display(level_menu->lvl, win);
}

void level_menu_destroy(level_menu_t *level_menu)
{
    sprite_destroy(level_menu->button_right);
    sprite_destroy(level_menu->button_left);
    sprite_destroy(level_menu->button_return);
    sprite_destroy(level_menu->button_select);
    sprite_destroy(level_menu->shadow);
    sprite_destroy(level_menu->button_score);
    sprite_destroy(level_menu->htp_button);
    levels_destroy(level_menu->lvl);
    time_destroy(level_menu->time);
    free(level_menu);
}