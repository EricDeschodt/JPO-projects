/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** menu_display3
*/

#include "my.h"

void hitbox_menu_3_bis(all_t *all)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);
    if ((mouse_pos.x >= all->pos_menu.quit.x && mouse_pos.x <=
        all->pos_menu.quit.x + 209) && (mouse_pos.y >= all->pos_menu.quit.y
        && mouse_pos.y <= all->pos_menu.quit.x - 200)) sfSprite_setTexture
            (all->sp_button.quit, all->tx_button.quit_w, sfTrue);
    else sfSprite_setTexture(all->sp_button.quit, all->tx_button.quit, sfTrue);
    if ((mouse_pos.x >= all->pos_menu.levels.x && mouse_pos.x <=
        all->pos_menu.levels.x + 209) && (mouse_pos.y >= all->pos_menu.levels.y
        && mouse_pos.y <= all->pos_menu.levels.x - 500))
        sfSprite_setTexture
            (all->sp_button.restart, all->tx_button.restart_w, sfTrue);
    else sfSprite_setTexture
            (all->sp_button.restart, all->tx_button.restart, sfTrue);
}

void hitbox_menu_3(all_t *all)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);
    if ((mouse_pos.x >= all->pos_menu.ia.x && mouse_pos.x <=
        all->pos_menu.ia.x + 209) && (mouse_pos.y >= all->pos_menu.ia.y
        && mouse_pos.y <= all->pos_menu.ia.x - 350))
        sfSprite_setTexture
            (all->sp_button.menu, all->tx_button.menu_w, sfTrue);
    else sfSprite_setTexture
            (all->sp_button.menu, all->tx_button.menu, sfTrue);
    if ((mouse_pos.x >= all->pos_menu.level1.x && mouse_pos.x <=
        all->pos_menu.level1.x + 209) && (mouse_pos.y >= all->pos_menu.level1.y
        && mouse_pos.y <= all->pos_menu.level1.x - 650)) sfSprite_setTexture
            (all->sp_button.play, all->tx_button.play_w, sfTrue);
    else sfSprite_setTexture(all->sp_button.play,
        all->tx_button.play, sfTrue);
    hitbox_menu_3_bis(all);
}

void hitbox_menu_2_bis(all_t *all, sfVector2i mouse_pos)
{
    if ((mouse_pos.x >= all->pos_menu.quit.x && mouse_pos.x <=
        all->pos_menu.quit.x + 209) && (mouse_pos.y >= all->pos_menu.quit.y
        && mouse_pos.y <= all->pos_menu.quit.x - 200)) sfSprite_setTexture
            (all->sp_button.your, all->tx_button.your_w, sfTrue);
    else sfSprite_setTexture(all->sp_button.your, all->tx_button.your, sfTrue);
    if ((mouse_pos.x >= all->pos_menu.levels.x && mouse_pos.x <=
        all->pos_menu.levels.x + 209) && (mouse_pos.y >= all->pos_menu.levels.y
        && mouse_pos.y <= all->pos_menu.levels.x - 500)) sfSprite_setTexture
            (all->sp_button.level2, all->tx_button.level2_w, sfTrue);
    else sfSprite_setTexture
            (all->sp_button.level2, all->tx_button.level2, sfTrue);
    if ((mouse_pos.x >= all->pos_menu.back.x && mouse_pos.x <=
        all->pos_menu.back.x + 209) && (mouse_pos.y >= all->pos_menu.back.y
        && mouse_pos.y <= all->pos_menu.back.x - 50)) sfSprite_setTexture
            (all->sp_button.back, all->tx_button.back_w, sfTrue);
    else sfSprite_setTexture(all->sp_button.back, all->tx_button.back, sfTrue);
}

void hitbox_menu_2(all_t *all)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(all->window);
    if ((mouse_pos.x >= all->pos_menu.ia.x && mouse_pos.x <=
        all->pos_menu.ia.x + 209) && (mouse_pos.y >= all->pos_menu.ia.y
        && mouse_pos.y <= all->pos_menu.ia.x - 350))
        sfSprite_setTexture
            (all->sp_button.level3, all->tx_button.level3_w, sfTrue);
    else sfSprite_setTexture
        (all->sp_button.level3, all->tx_button.level3, sfTrue);
    if ((mouse_pos.x >= all->pos_menu.level1.x && mouse_pos.x <=
        all->pos_menu.level1.x + 209) && (mouse_pos.y >= all->pos_menu.level1.y
        && mouse_pos.y <= all->pos_menu.level1.x - 650)) sfSprite_setTexture
            (all->sp_button.level1, all->tx_button.level1_w, sfTrue);
    else sfSprite_setTexture(all->sp_button.level1,
        all->tx_button.level1, sfTrue);
    hitbox_menu_2_bis(all, mouse_pos);
}

void menu_display2(all_t *all)
{
    if (all->my_int.speed == 0) {
        hitbox_menu_3(all);
        sfRenderWindow_drawSprite(all->window, all->sp_button.play, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.restart, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.menu, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.quit, NULL);
        sfRenderWindow_drawText(all->window, all->write.skull_txt, NULL);
    }
    if (all->my_int.menu == 5) {
        hitbox_menu_3(all);
        sfRenderWindow_drawSprite(all->window, all->sp_button.restart, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.menu, NULL);
        sfRenderWindow_drawSprite(all->window, all->sp_button.quit, NULL);
        sfRenderWindow_drawText(all->window, all->write.skull_txt, NULL);
        if (list_end_map(all) == 0)
            sfRenderWindow_drawText(all->window, all->write.game_over, NULL);
        else
            sfRenderWindow_drawText(all->window, all->write.victory, NULL);
    }
}