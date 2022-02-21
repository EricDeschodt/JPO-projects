/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** functions for the main menu
*/

#include "../../include/main_menu.h"

main_menu_t *main_menu_create(void)
{
    main_menu_t *menu = malloc(sizeof(main_menu_t));
    menu->logo = sprite_create("assets/gui/logo.png", "C", false, true);
    sprite_set_pos(menu->logo, 960, 380, (float)0.8);
    menu->play_button = button_create("assets/gui/play_button.png", "C");
    sprite_set_pos(menu->play_button, 960, 725, 1);
    menu->exit_button = button_create
    ("assets/gui/exit_button.png", "C");
    sprite_set_pos(menu->exit_button, 960, 950, 1);
    menu->credits = text_create
        ("credits : Mathis Vinay, Jolan Brizard\n{EPITECH}.", "W", sfWhite,
            false);
    text_set_pos(menu->credits, 70, 990, 16);
    menu->setting_b = button_create("assets/gui/setting_button.png", "C");
    sprite_set_pos(menu->setting_b, 960, 835, 1);
    return menu;
}

void main_menu_display(main_menu_t *menu, sfRenderWindow *win)
{
    sprite_display(menu->logo, win);
    button_display(menu->exit_button, win, true);
    button_display(menu->play_button, win, true);
    button_display(menu->setting_b, win, true);
    text_display(menu->credits, win);
}

void main_menu_destroy(main_menu_t *menu)
{
    sprite_destroy(menu->logo);
    sprite_destroy(menu->play_button);
    sprite_destroy(menu->exit_button);
    text_destroy(menu->credits);
    sprite_destroy(menu->setting_b);
    free(menu);
}