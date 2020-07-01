/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** menu_display2
*/

#include "my.h"

void set_pos_button(pos_menu_t *pos_menu, sp_button_t *sp_button)
{
    sfSprite_setPosition(sp_button->levels, pos_menu->levels);
    sfSprite_setPosition(sp_button->ia, pos_menu->ia);
    sfSprite_setPosition(sp_button->quit, pos_menu->quit);
    sfSprite_setPosition(sp_button->level1, pos_menu->level1);
    sfSprite_setPosition(sp_button->level2, pos_menu->levels);
    sfSprite_setPosition(sp_button->level3, pos_menu->ia);
    sfSprite_setPosition(sp_button->your, pos_menu->quit);
    sfSprite_setPosition(sp_button->back, pos_menu->back);
    sfSprite_setPosition(sp_button->play, pos_menu->level1);
    sfSprite_setPosition(sp_button->restart, pos_menu->levels);
    sfSprite_setPosition(sp_button->menu, pos_menu->ia);
}

void hitbox_menu_1_bis(all_t *all, sfVector2i mouse_pos)
{
    if ((mouse_pos.x >= all->pos_menu.quit.x && mouse_pos.x <=
        all->pos_menu.quit.x + 209) && (mouse_pos.y >= all->pos_menu.quit.y
        && mouse_pos.y <= all->pos_menu.quit.x - 200)) sfSprite_setTexture
            (all->sp_button.quit, all->tx_button.quit_w, sfTrue);
    else sfSprite_setTexture
            (all->sp_button.quit, all->tx_button.quit, sfTrue);
    if ((mouse_pos.x >= all->pos_menu.levels.x && mouse_pos.x <=
        all->pos_menu.levels.x + 209) && (mouse_pos.y >= all->pos_menu.levels.y
        && mouse_pos.y <= all->pos_menu.levels.x - 500)) sfSprite_setTexture
            (all->sp_button.levels, all->tx_button.levels_w, sfTrue);
    else sfSprite_setTexture
            (all->sp_button.levels, all->tx_button.levels, sfTrue);
}

void hitbox_menu_1(all_t *all)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);
    if ((mouse_pos.x >= all->pos_menu.ia.x && mouse_pos.x <=
        all->pos_menu.ia.x + 209) && (mouse_pos.y >= all->pos_menu.ia.y
        && mouse_pos.y <= all->pos_menu.ia.x - 350 && all->my_int.ia == 0))
        sfSprite_setTexture
            (all->sp_button.ia, all->tx_button.ia_off_w, sfTrue);
    else if (all->my_int.ia == 0) sfSprite_setTexture
            (all->sp_button.ia, all->tx_button.ia_off, sfTrue);
    if ((mouse_pos.x >= all->pos_menu.ia.x && mouse_pos.x <=
        all->pos_menu.ia.x + 209) && (mouse_pos.y >= all->pos_menu.ia.y
        && mouse_pos.y <= all->pos_menu.ia.x - 350 && all->my_int.ia == 1))
        sfSprite_setTexture
            (all->sp_button.ia, all->tx_button.ia_on_w, sfTrue);
    else if (all->my_int.ia == 1) sfSprite_setTexture
            (all->sp_button.ia, all->tx_button.ia_on, sfTrue);
    hitbox_menu_1_bis(all, mouse_pos);
}

void night_day_cycle(all_t *all)
{
    if (all->my_int.alpha < 255 && all->my_int.day != 1
        && all->clock.seconds_cycle >= 1) all->my_int.alpha += 4;
    if (all->my_int.alpha > 0 && all->my_int.day == 1) all->my_int.alpha -= 3;
    if (all->my_int.alpha >= 252) all->my_int.day = 1;
    else if (all->my_int.alpha <= 0) { all->my_int.day = 0;
        if (all->clock.seconds_cycle > 1)
            sfClock_restart(all->clock.clock_cycle);
    } if ((list_end_map(all) == 1) && all->my_int.menu != 0)
        reset_menu(all);
    if (all->clock.seconds_total >= 49
        && all->my_int.menu != 0 && all->my_int.speed != 0) {
        all->my_int.reset = 1,
        sfClock_restart(all->clock.clock_total);
    }
    all->color = sfColor_fromRGBA(255, 200, 100, all->my_int.alpha);
    sfRectangleShape_setFillColor(all->rectangle, all->color);
    sfSprite_setColor(all->background.background1_2, all->color);
    sfSprite_setColor(all->background2.background2_1_2, all->color);
}

void draw_menu_1(all_t *all)
{
    if (all->my_int.skull == 0 && all->my_int.menu == 5)
        all->my_int.menu = 0;
    if (all->my_int.menu == 1) {
        hitbox_menu_1(all);
        sfRenderWindow_drawSprite(all->window, all->sp_button.levels, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.ia, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.quit, NULL);
        sfRenderWindow_drawText(all->window, all->write.text, NULL);
    } else if (all->my_int.menu == 2) {
        hitbox_menu_2(all);
        sfRenderWindow_drawSprite(all->window, all->sp_button.level1, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.level2, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.level3, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.your, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.back, NULL);
        sfRenderWindow_drawText(all->window, all->write.text, NULL);
    } menu_display2(all);
}