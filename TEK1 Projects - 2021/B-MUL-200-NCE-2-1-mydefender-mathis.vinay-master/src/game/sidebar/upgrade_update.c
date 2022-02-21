/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** update stats in regards of the turrets
*/

#include "../../../include/game/sidebar.h"
#include "../../../include/game/main_game.h"

void update_dps_up(main_game_t *g)
{
    if (g->turret_list[g->turret_selected]->mode == 0) {
        sfText_setString(g->sidebar->upgrade->dps_text->text, "0.4");
        sfText_setString(g->sidebar->upgrade->d_dps_text->text, "0.1");
    }
    if (g->turret_list[g->turret_selected]->mode == 1) {
        sfText_setString(g->sidebar->upgrade->dps_text->text, "0.8");
        sfText_setString(g->sidebar->upgrade->d_dps_text->text, "0.1");
    }
    if (g->turret_list[g->turret_selected]->mode == 2) {
        sfText_setString(g->sidebar->upgrade->dps_text->text, "2");
        sfText_setString(g->sidebar->upgrade->d_dps_text->text, "0.5");
    }
    if (g->turret_list[g->turret_selected]->mode == 3) {
        sfText_setString(g->sidebar->upgrade->dps_text->text, "1.5");
        sfText_setString(g->sidebar->upgrade->d_dps_text->text, "0.5");
    }
}

void update_dps(main_game_t *g)
{
    if (!g->turret_list[g->turret_selected]->upgraded) {
        if (g->turret_list[g->turret_selected]->mode == 0) {
            sfText_setString(g->sidebar->upgrade->dps_text->text, "0.5");
            sfText_setString(g->sidebar->upgrade->d_dps_text->text, "0.1");
        } else if (g->turret_list[g->turret_selected]->mode == 1) {
            sfText_setString(g->sidebar->upgrade->dps_text->text, "0.9");
            sfText_setString(g->sidebar->upgrade->d_dps_text->text, "0.1");
        }
        if (g->turret_list[g->turret_selected]->mode == 2) {
            sfText_setString(g->sidebar->upgrade->dps_text->text, "2.5");
            sfText_setString(g->sidebar->upgrade->d_dps_text->text, "0.5");
        } else if (g->turret_list[g->turret_selected]->mode == 3) {
            sfText_setString(g->sidebar->upgrade->dps_text->text, "2");
            sfText_setString(g->sidebar->upgrade->d_dps_text->text, "0.5");
        }
    } else
        update_dps_up(g);
}

void update_ad(main_game_t *g)
{
    sfText_setString(g->sidebar->upgrade->up_dmg_text->text,
    int_to_str(g->sidebar->upgrade->up_dmg_str,
    g->turret_list[g->turret_selected]->ad / 2));
}

void update_name(main_game_t *g)
{
    if (g->turret_list[g->turret_selected]->mode == 0)
        sfText_setString(g->sidebar->upgrade->turret_text->text,
        "Basic Turret");
    if (g->turret_list[g->turret_selected]->mode == 1)
        sfText_setString(g->sidebar->upgrade->turret_text->text,
        "Double Turret");
    if (g->turret_list[g->turret_selected]->mode == 2)
        sfText_setString(g->sidebar->upgrade->turret_text->text,
                            "Rocket Addict");
    if (g->turret_list[g->turret_selected]->mode == 3)
        sfText_setString(g->sidebar->upgrade->turret_text->text, "Kraber");
}

void update_image(main_game_t *g)
{
    if (g->turret_list[g->turret_selected]->mode == 0)
        sfSprite_setTexture(g->sidebar->upgrade->turret_image,
                                g->texture_list[6], sfFalse);
    if (g->turret_list[g->turret_selected]->mode == 1)
        sfSprite_setTexture(g->sidebar->upgrade->turret_image,
                                g->texture_list[7], sfFalse);
    if (g->turret_list[g->turret_selected]->mode == 2)
        sfSprite_setTexture(g->sidebar->upgrade->turret_image,
                                g->texture_list[8], sfFalse);
    if (g->turret_list[g->turret_selected]->mode == 3)
        sfSprite_setTexture(g->sidebar->upgrade->turret_image,
                                g->texture_list[9], sfFalse);
}