/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** menu_display
*/

#include "my.h"

void set_menu_texture(sp_button_t *sp_button, tx_button_t *tx_button)
{
    sfSprite_setTexture(sp_button->levels, tx_button->levels, sfTrue);
    sfSprite_setTexture(sp_button->ia, tx_button->ia_off, sfTrue);
    sfSprite_setTexture(sp_button->quit, tx_button->quit, sfTrue);
    sfSprite_setTexture(sp_button->level1, tx_button->level1, sfTrue);
    sfSprite_setTexture(sp_button->level2, tx_button->level2, sfTrue);
    sfSprite_setTexture(sp_button->level3, tx_button->level3, sfTrue);
    sfSprite_setTexture(sp_button->your, tx_button->your, sfTrue);
    sfSprite_setTexture(sp_button->back, tx_button->back, sfTrue);
    sfSprite_setTexture(sp_button->restart, tx_button->restart, sfTrue);
    sfSprite_setTexture(sp_button->play, tx_button->play, sfTrue);
    sfSprite_setTexture(sp_button->menu, tx_button->menu, sfTrue);
}

void sprite_menu_init(sp_button_t *sp_button)
{
    sp_button->levels = sfSprite_create();
    sp_button->ia = sfSprite_create();
    sp_button->quit = sfSprite_create();
    sp_button->level1 = sfSprite_create();
    sp_button->level2 = sfSprite_create();
    sp_button->level3 = sfSprite_create();
    sp_button->your = sfSprite_create();
    sp_button->back = sfSprite_create();
    sp_button->menu = sfSprite_create();
    sp_button->restart = sfSprite_create();
    sp_button->play = sfSprite_create();
}

void texture_menu_init2(tx_button_t *tx_button)
{
    tx_button->level1 = sfTexture_createFromFile("buttons/LEVEL1.png", NULL);
    tx_button->level2 = sfTexture_createFromFile("buttons/LEVEL2.png", NULL);
    tx_button->level3 = sfTexture_createFromFile("buttons/LEVEL3.png", NULL);
    tx_button->your = sfTexture_createFromFile("buttons/YOUR.png", NULL);
    tx_button->back = sfTexture_createFromFile("buttons/BACK.png", NULL);
    tx_button->level1_w =
        sfTexture_createFromFile("buttons/LEVEL1_W.png", NULL);
    tx_button->level2_w =
        sfTexture_createFromFile("buttons/LEVEL2_W.png", NULL);
    tx_button->level3_w =
        sfTexture_createFromFile("buttons/LEVEL3_W.png", NULL);
    tx_button->your_w = sfTexture_createFromFile("buttons/YOUR_W.png", NULL);
    tx_button->back_w = sfTexture_createFromFile("buttons/BACK_W.png", NULL);
}

void texture_menu_init(tx_button_t *tx_button)
{
    tx_button->menu = sfTexture_createFromFile("buttons/MENU.png", NULL);
    tx_button->restart = sfTexture_createFromFile("buttons/RESTART.png", NULL);
    tx_button->play = sfTexture_createFromFile("buttons/PLAY.png", NULL);
    tx_button->menu_w = sfTexture_createFromFile("buttons/MENU_W.png", NULL);
    tx_button->restart_w =
        sfTexture_createFromFile("buttons/RESTART_W.png", NULL);
    tx_button->play_w = sfTexture_createFromFile("buttons/PLAY_W.png", NULL);
    tx_button->levels = sfTexture_createFromFile("buttons/LEVELS.png", NULL);
    tx_button->ia_on = sfTexture_createFromFile("buttons/IA_ON.png", NULL);
    tx_button->ia_off = sfTexture_createFromFile("buttons/IA_OFF.png", NULL);
    tx_button->quit = sfTexture_createFromFile("buttons/QUIT.png", NULL);
    tx_button->levels_w =
        sfTexture_createFromFile("buttons/LEVELS_W.png", NULL);
    tx_button->ia_on_w = sfTexture_createFromFile("buttons/IA_ON_W.png", NULL);
    tx_button->ia_off_w =
        sfTexture_createFromFile("buttons/IA_OFF_W.png", NULL);
    tx_button->quit_w = sfTexture_createFromFile("buttons/QUIT_W.png", NULL);
    texture_menu_init2(tx_button);
}

void init_button(all_t *all)
{
    sprite_menu_init(&all->sp_button);
    texture_menu_init(&all->tx_button);
    set_menu_texture(&all->sp_button, &all->tx_button);
    init_pos_menu(&all->pos_menu);
    set_pos_button(&all->pos_menu, &all->sp_button);
}