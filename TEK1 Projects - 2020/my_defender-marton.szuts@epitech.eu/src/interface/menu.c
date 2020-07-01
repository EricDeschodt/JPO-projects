/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** menu+
*/

#include "defender.h"

void init_menu(all_t *s_all)
{
    s_all->s_menu.sp_background = sfSprite_create();
    s_all->s_menu.tx_background =
        sfTexture_createFromFile("sprites/background.png", NULL);
    sfSprite_setTexture(s_all->s_menu.sp_background,
        s_all->s_menu.tx_background, sfTrue);
    s_all->s_menu.main_theme = sfMusic_createFromFile("sounds/main_theme.ogg");
    sfMusic_play(s_all->s_menu.main_theme);
    sfMusic_setLoop(s_all->s_menu.main_theme, sfTrue);
    sfMusic_setVolume(s_all->s_menu.main_theme, 60);
    s_all->s_menu.about = sfSprite_create();
    s_all->s_menu.about_tx =
        sfTexture_createFromFile("sprites/about.png", NULL);
    s_all->s_menu.settings = sfSprite_create();
    s_all->s_menu.settings_tx =
        sfTexture_createFromFile("sprites/settings.png", NULL);
    sfSprite_setTexture(s_all->s_menu.about, s_all->s_menu.about_tx, sfTrue);
    sfSprite_setTexture(s_all->s_menu.settings,
        s_all->s_menu.settings_tx, sfTrue);
    sfSprite_setPosition(s_all->s_menu.about, (sfVector2f){0, -30});
}

void list_menu_buttons(all_t *s_all)
{
    button_tab_init(s_all->s_buttons_tab.tab);
    button_tab2_init(s_all->s_buttons_tab.tab2);
    s_all->s_buttons = NULL;
    for (int i = 0, y = 120; i != 12; i++, y += 100) {
        if (i == 8)
            y = 600;
        if (i < 8) s_all->s_buttons = push_back_buttons(s_all, y, 0, i);
        else if (i > 7) s_all->s_buttons = push_back_buttons(s_all, y, 1, i);
    }
}

void display_menu_buttons(all_t *s_all)
{
    int i = 0;
    node_buttons_t *tmp = s_all->s_buttons->begin;
    if (s_all->s_game.pause == 1 && s_all->s_game.scene == 1)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_buttons->black, NULL);
    while (tmp != NULL) {
        i++;
        menu_buttons_hitbox(tmp, s_all);
        if (tmp->who == 0 && s_all->s_game.scene == 0)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        else if (tmp->who == 1 && s_all->s_game.scene == 1 &&
        s_all->s_game.pause == 1 && s_all->s_player.defeat != 1)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        if ((s_all->s_game.scene == -1 || s_all->s_game.scene == 6
        || s_all->s_game.scene == 4 || s_all->s_game.scene == 3
        || s_all->s_game.scene == 5 || s_all->s_player.defeat == 1)
        && tmp->who == 1 && i == 12)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}

void display_menu(all_t *s_all)
{
    if (s_all->s_game.scene == 6)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_menu.about, NULL);
    if (s_all->s_game.scene == 0)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_menu.sp_background, NULL);
    if (s_all->s_game.scene == 4)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_menu.settings, NULL);
    if (s_all->s_game.scene == 3) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_menu.statistics, NULL);
        display_statistics(s_all);
    } if (s_all->s_game.scene == 5)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_menu.handbook, NULL);
    display_menu_buttons(s_all);
    display_settings_buttons(s_all);
}