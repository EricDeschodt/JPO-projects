/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** create / init the sidebar
*/

#include "../../../include/game/sidebar.h"
#include "../../../include/game/main_game.h"

void set_texts(sidebar_t *sidebar)
{
    sidebar->hp_str = malloc(sizeof(char) * 3 + 1);
    sidebar->hp_str = int_to_str(sidebar->hp_str, 0);
    sidebar->hp_text = text_create(sidebar->hp_str, "", sfRed, false);
    sidebar->gold_str = malloc(sizeof(char) * 1000000 + 1);
    sidebar->gold_str = int_to_str(sidebar->gold_str, 0);
    sidebar->gold_text = text_create(sidebar->gold_str, "NE", sfYellow, false);
    sidebar->wave_str = malloc(sizeof(char) * 1000000 + 1);
    sidebar->wave_str = int_to_str(sidebar->wave_str, 0);
    sidebar->wave_text = text_create(sidebar->wave_str, "", sfCyan, false);
    text_set_rgb_color(sidebar->wave_text, 0, 144, 255);
    text_set_rgb_color(sidebar->gold_text, 255, 221, 0);
    text_set_outline(sidebar->wave_text, sfBlue, 2);
    text_set_outline(sidebar->gold_text, sfBlue, 4);
    text_set_outline(sidebar->hp_text, sfBlue, 2);
    text_set_outline_rgb_color(sidebar->wave_text, 0, 78, 130);
    text_set_outline_rgb_color(sidebar->gold_text, 117, 107, 0);
    text_set_outline_rgb_color(sidebar->hp_text, 137, 2, 0);
    text_set_pos(sidebar->hp_text, 1545, 27, 44);
    text_set_pos(sidebar->gold_text, 1800, 723, 50);
    text_set_pos(sidebar->wave_text, 1850, 27, 44);
}

sidebar_t *sidebar_create(void)
{
    sidebar_t *sidebar = malloc(sizeof(sidebar_t));
    sidebar->fond = sprite_create("assets/gui/sidebar.png", "NE", false, false);
    sprite_set_pos(sidebar->fond, 1920, 0, 1);
    sidebar->shop = sprite_create("assets/gui/sidebar_shop.png", "NE", false,
    false);
    sprite_set_pos(sidebar->shop, 1920, 0, 1);
    sidebar->pause_button = button_create("assets/gui/pause_button.png", "SE");
    sprite_set_pos(sidebar->pause_button, 1879, 1000, (float)1.08);
    set_texts(sidebar);
    sidebar->turrets = radio_buttons_create(130, "assets/gui/turret_selection"
    ".png", 1673, 120);
    radio_buttons_append(sidebar->turrets, "assets/gui/basic_turret.png");
    radio_buttons_append(sidebar->turrets, "assets/gui/double_turret.png");
    radio_buttons_append(sidebar->turrets, "assets/gui/rocket_addict.png");
    radio_buttons_append(sidebar->turrets, "assets/gui/krabber.png");
    sidebar->upgrade = upgrade_create();
    return sidebar;
}

void sidebar_init(sidebar_t *sidebar, main_game_t *game)
{
    sidebar->hp_str = int_to_str(sidebar->hp_str, game->hp);
    sfText_setString(sidebar->hp_text->text, sidebar->hp_str);
    text_set_origin(sidebar->hp_text, "NE");
    sidebar->gold_str = int_to_str(sidebar->gold_str, game->gold);
    sfText_setString(sidebar->gold_text->text, sidebar->gold_str);
    text_set_origin(sidebar->gold_text, "NE");
    sidebar->wave_str = int_to_str(sidebar->wave_str, game->wave);
    sfText_setString(sidebar->wave_text->text, sidebar->wave_str);
    text_set_origin(sidebar->wave_text, "NO");
}

void sidebar_display(main_game_t *g, sfRenderWindow *win, bool should_animate)
{
    sprite_display(g->sidebar->fond, win);
    text_display(g->sidebar->hp_text, win);
    text_display(g->sidebar->gold_text, win);
    text_display(g->sidebar->wave_text, win);
    if (g->turret_selected == -1) {
        sprite_display(g->sidebar->shop, win);
        radio_buttons_display(g->sidebar->turrets, win, should_animate);
    } else
        upgrade_display(g->sidebar->upgrade, win,
                            g->turret_list[g->turret_selected]->upgraded);
    button_display(g->sidebar->pause_button, win, should_animate);
}

void sidebar_destroy(sidebar_t *sidebar)
{
    sprite_destroy(sidebar->fond);
    sprite_destroy(sidebar->pause_button);
    sprite_destroy(sidebar->shop);
    free(sidebar->hp_str);
    free(sidebar->gold_str);
    free(sidebar->wave_str);
    text_destroy(sidebar->hp_text);
    text_destroy(sidebar->gold_text);
    text_destroy(sidebar->wave_text);
    radio_buttons_destroy(sidebar->turrets);
    upgrade_destroy(sidebar->upgrade);
    free(sidebar);
}