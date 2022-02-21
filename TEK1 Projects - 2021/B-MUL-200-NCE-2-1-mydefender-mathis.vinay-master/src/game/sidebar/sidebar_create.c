/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** create the sidebar upgrade mode
*/

#include "../../../include/game/sidebar.h"
#include "../../../include/game/main_game.h"

void texts_set_colors(upgrade_t *u)
{
    text_set_rgb_color(u->up_dmg_text, 237, 86, 0);
    text_set_rgb_color(u->ad_text, 237, 86, 0);
    text_set_rgb_color(u->d_dps_text, 229, 229, 229);
    text_set_rgb_color(u->dps_text, 229, 229, 229);
    text_set_rgb_color(u->range_text, 229, 229, 229);
    text_set_rgb_color(u->cost_text, 255, 221, 0);
    text_set_rgb_color(u->turret_text, 229, 229, 229);
    text_set_outline_rgb_color(u->up_dmg_text, 225, 173, 66);
    text_set_outline_rgb_color(u->ad_text, 225, 173, 66);
    text_set_outline_rgb_color(u->d_dps_text, 81, 81, 81);
    text_set_outline_rgb_color(u->dps_text, 81, 81, 81);
    text_set_outline_rgb_color(u->range_text, 81, 81, 81);
    text_set_outline_rgb_color(u->cost_text, 112, 106, 0);
    text_set_outline_rgb_color(u->turret_text, 81, 81, 81);
}

void texts_setting_position(upgrade_t *u)
{
    text_set_pos(u->d_dps_text, 1820, 408, 30);
    text_set_pos(u->up_dmg_text, 1820, 352, 30);
    text_set_pos(u->ad_text, 1580, 352, 30);
    text_set_pos(u->dps_text, 1580, 408, 30);
    text_set_pos(u->range_text, 1620, 465, 30);
    text_set_pos(u->cost_text, 1790, 465, 30);
    text_set_pos(u->turret_text, 1725, 200, 34);
    text_set_outline(u->turret_text, sfBlack, 3);
    text_set_outline(u->ad_text, sfBlack, 3);
    text_set_outline(u->range_text, sfBlack, 3);
    text_set_outline(u->dps_text, sfBlack, 3);
    text_set_outline(u->cost_text, sfBlack, 3);
    text_set_outline(u->up_dmg_text, sfBlack, 3);
    text_set_outline(u->d_dps_text, sfBlack, 3);
}

void load_stats(upgrade_t *u)
{
    u->ad_str = malloc(sizeof(char) * 100);
    u->range_str = malloc(sizeof(char) * 100);
    u->dps_str = malloc(sizeof(char) * 100);
    u->cost_str = malloc(sizeof(char) * 100);
    u->up_dmg_str = malloc(sizeof(char) * 100);
    u->d_dps_str = malloc(sizeof(char) * 100);
    u->ad_text = text_create(int_to_str(u->ad_str, 1), "CO", sfWhite, false);
    u->dps_text = text_create(int_to_str(u->dps_str, 2), "CO", sfWhite, false);
    u->range_text = text_create(int_to_str(u->range_str, 3), "CO", sfWhite,
                                false);
    u->cost_text = text_create(int_to_str(u->cost_str, 4), "CE", sfWhite,
                                false);
    u->up_dmg_text = text_create(int_to_str(u->up_dmg_str, 1), "CE", sfWhite,
                                    false);
    u->turret_text = text_create("Turret Name", "C", sfWhite, true);
    u->d_dps_text = text_create(int_to_str(u->d_dps_str, 2), "CE", sfWhite,
                                false);
    texts_setting_position(u);
}

void sidebar_text_set_o(upgrade_t *up)
{
    text_set_origin(up->cost_text, "CE");
    text_set_origin(up->d_dps_text, "CE");
    text_set_origin(up->up_dmg_text, "CE");
    text_set_origin(up->range_text, "CO");
    text_set_origin(up->dps_text, "CO");
    text_set_origin(up->ad_text, "CO");
    text_set_origin(up->turret_text, "C");
}

upgrade_t *upgrade_create(void)
{
    upgrade_t *upgrade = malloc(sizeof(upgrade_t));
    upgrade->turret_image = sfSprite_create();
    upgrade->upgrade_b = button_create("assets/gui/upgrade_button.png", "C");
    upgrade->delete_b = button_create("assets/gui/destroy_button.png", "C");
    upgrade->upgrade = sprite_create("assets/gui/sidebar_upgrade.png", "NE",
                                        false, false);
    upgrade->adds = sprite_create("assets/gui/sidebar_upgrade_stats.png", "NE",
                                    false, false);
    sprite_set_pos(upgrade->upgrade_b, 1675, 580, (float)0.8);
    sprite_set_pos(upgrade->delete_b, 1675, 670, (float)0.8);
    sprite_set_pos(upgrade->upgrade, 1920, 0, 1);
    sprite_set_pos(upgrade->adds, 1920, 0, 1);
    sfVector2f pos = {1470, 170};
    sfSprite_setPosition(upgrade->turret_image, pos);
    load_stats(upgrade);
    return upgrade;
}