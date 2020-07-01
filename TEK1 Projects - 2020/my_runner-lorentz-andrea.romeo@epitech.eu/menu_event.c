/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** menu_event
*/

#include "my.h"

void menu_events2_bis(all_t *all)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);
    if ((mouse_pos.x >= all->pos_menu.quit.x && mouse_pos.x <=
        all->pos_menu.quit.x + 209) && (mouse_pos.y >= all->pos_menu.quit.y
        && mouse_pos.y <= all->pos_menu.quit.x - 200)) {
        all->my_int.menu = 0, all->my_int.reset = 1, all->my_int.level = 4;
        all->my_int.skull = 0;
    }
    if ((mouse_pos.x >= all->pos_menu.level1.x && mouse_pos.x <= all
        ->pos_menu.level1.x + 209) && (mouse_pos.y >= all->pos_menu.level1.y
        && mouse_pos.y <= all->pos_menu.level1.x - 650)) {
        all->my_int.menu = 0, all->my_int.reset = 1, all->my_int.level = 1;
        all->my_int.skull = 0;
    }
}

void menu_events3(sfEvent event, all_t *all, sfVector2i mouse_pos)
{
    if (event.type == sfEvtMouseButtonPressed
        && (all->my_int.speed == 0 || all->my_int.menu == 5)) {
        if ((mouse_pos.x >= all->pos_menu.quit.x && mouse_pos.x <=
            all->pos_menu.quit.x + 209) && (mouse_pos.y >= all->pos_menu.quit.y
            && mouse_pos.y <= all->pos_menu.quit.x - 200)) sfRenderWindow_close
            (all->window), print_top_score(all);
        if ((mouse_pos.x >= all->pos_menu.levels.x && mouse_pos.x <=
            all->pos_menu.levels.x + 209) && (mouse_pos.y >= all->pos_menu
            .levels.y && mouse_pos.y <= all->pos_menu.levels.x - 500)) {
            all->my_int.reset = 1, all->my_int.speed = 200;
            all->my_int.skull = 0, print_top_score(all), all->my_int.menu = 0;
        } if ((mouse_pos.x >= all->pos_menu.ia.x && mouse_pos.x <=
            all->pos_menu.ia.x + 209) && (mouse_pos.y >= all->pos_menu.ia.y
            && mouse_pos.y <= all->pos_menu.ia.x - 350)) { all->my_int.menu = 1;
            all->my_int.speed = 200, all->my_int.level = 0, reset_menu(all);
            print_top_score(all);
        } if ((mouse_pos.x >= all->pos_menu.level1.x && mouse_pos.x <=
            all->pos_menu.level1.x + 209) && (mouse_pos.y >= all->pos_menu
            .level1.y && mouse_pos.y <= all->pos_menu.level1.x - 650))
            all->my_int.speed = 200; }
}

void menu_events2(sfEvent event, all_t *all)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);
    if (event.type == sfEvtMouseButtonPressed && all->my_int.menu == 2) {
        if ((mouse_pos.x >= all->pos_menu.back.x && mouse_pos.x <=
        all->pos_menu.back.x + 209) && (mouse_pos.y >= all->pos_menu.back.y
        && mouse_pos.y <= all->pos_menu.back.x - 50))
            all->my_int.menu = 1;
        if ((mouse_pos.x >= all->pos_menu.ia.x && mouse_pos.x <=
            all->pos_menu.ia.x + 209) && (mouse_pos.y >= all->pos_menu.ia.y
            && mouse_pos.y <= all->pos_menu.ia.x - 350)) {
            all->my_int.menu = 0, all->my_int.reset = 1, all->my_int.level = 3;
            all->my_int.skull = 0;
        } if ((mouse_pos.x >= all->pos_menu.levels.x && mouse_pos.x <=
            all->pos_menu.levels.x + 209) && (mouse_pos.y >= all->pos_menu
            .levels.y && mouse_pos.y <= all->pos_menu.levels.x - 500)) {
            all->my_int.menu = 0, all->my_int.reset = 1, all->my_int.level = 2;
            all->my_int.skull = 0;
        }
        menu_events2_bis(all);
    }
}

void menu_events(sfEvent event, all_t *all)
{
    menu_events2(event, all);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);
    if (event.type == sfEvtMouseButtonPressed && all->my_int.menu == 1) {
        if ((mouse_pos.x >= all->pos_menu.ia.x && mouse_pos.x <=
        all->pos_menu.ia.x + 209) && (mouse_pos.y >= all->pos_menu.ia.y
        && mouse_pos.y <= all->pos_menu.ia.x - 350 && all->my_int.ia == 0))
            all->my_int.ia = 1;
        else if ((mouse_pos.x >= all->pos_menu.ia.x && mouse_pos.x <=
        all->pos_menu.ia.x + 209) && (mouse_pos.y >= all->pos_menu.ia.y
        && mouse_pos.y <= all->pos_menu.ia.x - 350 && all->my_int.ia == 1))
            all->my_int.ia = 0;
        if ((mouse_pos.x >= all->pos_menu.quit.x && mouse_pos.x <=
        all->pos_menu.quit.x + 209) && (mouse_pos.y >= all->pos_menu.quit.y
        && mouse_pos.y <= all->pos_menu.quit.x - 200))
            sfRenderWindow_close(all->window);
        if ((mouse_pos.x >= all->pos_menu.levels.x && mouse_pos.x <=
        all->pos_menu.levels.x + 209) && (mouse_pos.y >= all->pos_menu.levels.y
        && mouse_pos.y <= all->pos_menu.levels.x - 500))
            all->my_int.menu = 2;
    } menu_events3(event, all, mouse_pos);
}