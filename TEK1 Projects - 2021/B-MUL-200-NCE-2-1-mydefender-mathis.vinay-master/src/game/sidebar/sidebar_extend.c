/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** extension for sidebar
*/

#include "../../../include/game/sidebar.h"
#include "../../../include/game/main_game.h"

void upgrade_display(upgrade_t *u, sfRenderWindow * win, bool upgraded)
{
    sprite_display(u->upgrade, win);
    if (!upgraded) {
        sprite_display(u->adds, win);
        text_display(u->d_dps_text, win);
        text_display(u->up_dmg_text, win);
        text_display(u->cost_text, win);
        button_display(u->upgrade_b, win, true);
    }
    button_display(u->delete_b, win, true);
    sfRenderWindow_drawSprite(win, u->turret_image, NULL);
    text_display(u->turret_text, win);
    text_display(u->ad_text, win);
    text_display(u->range_text, win);
    text_display(u->dps_text, win);
}

void upgrade_destroy(upgrade_t *u)
{
    text_destroy(u->up_dmg_text);
    text_destroy(u->d_dps_text);
    text_destroy(u->ad_text);
    text_destroy(u->range_text);
    text_destroy(u->dps_text);
    text_destroy(u->cost_text);
    text_destroy(u->turret_text);
    sprite_destroy(u->upgrade_b);
    sprite_destroy(u->delete_b);
    sprite_destroy(u->upgrade);
    sprite_destroy(u->adds);
    sfSprite_destroy(u->turret_image);
    free(u->up_dmg_str);
    free(u->dps_str);
    free(u->ad_str);
    free(u->range_str);
    free(u->d_dps_str);
    free(u->cost_str);
    free(u);
}