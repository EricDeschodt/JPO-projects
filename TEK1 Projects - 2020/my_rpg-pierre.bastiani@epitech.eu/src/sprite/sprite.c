/*
** EPITECH PROJECT, 2020
** sprite
** File description:
** rpg
*/

#include "../../include/include.h"

void draw(s_game *game, s_sprite *sprite, players *player)
{
    sfRenderWindow *win = game->window;
    if (game->statment == 2) {
        print_map(win, player, game);
        print_player(win, player);
        for (int i = 0; player->pnj[i] != NULL; i++)
            print_pnj(win, player->pnj[i], player);
        draw_game_inv(game, sprite, win);
        if (game->inventory != 0)
            print_inventory(win, player);
    }
    draw2(game, sprite, win, player);
    draw3(game, sprite, win);
    draw4(game, sprite, win);
    draw5(game, sprite, win);
}

void draw2(s_game *game, s_sprite *sprite, sfRenderWindow *win,
players *player)
{
    if (game->statment >= 10 && game->statment != 15)
        print_map(win, player, game);
    for (int i = 0; player->mob[i] != NULL; i++) {
        if (player->mob[i]->state == 1)
            print_combat(game, player, player->mob[i]);
        if (player->mob[i]->state == 0 && game->statment == 2 &&
        game->inventory == 0)
            print_mob(win, player->mob[i], player);
    }
    if (game->statment == 15)
        sfRenderWindow_drawSprite(win, player->sprit_lose, NULL);
    if (game->statment == 16)
        sfRenderWindow_drawSprite(win, player->sprit_end, NULL);
    if (game->statment == 3) {
        sfRenderWindow_drawSprite(win, sprite->bckg_menu, NULL);
        sfRenderWindow_drawSprite(win, sprite->play_button, NULL);
        sfRenderWindow_drawSprite(win, sprite->option_button, NULL);
        sfRenderWindow_drawSprite(win, sprite->how_tp, NULL);
        sfRenderWindow_drawSprite(win, sprite->quit_button_pressed, NULL);
    }
}

void draw3(s_game *game, s_sprite *sprite, sfRenderWindow *win)
{
    if (game->statment == 5) {
        sfRenderWindow_drawSprite(win, sprite->bckg_menu, NULL);
        sfRenderWindow_drawSprite(win, sprite->play_button, NULL);
        sfRenderWindow_drawSprite(win, sprite->option_button_press, NULL);
        sfRenderWindow_drawSprite(win, sprite->how_tp, NULL);
        sfRenderWindow_drawSprite(win, sprite->quit_button, NULL);
    }
    if (game->statment == 7) {
        sfRenderWindow_drawSprite(win, sprite->bckg_menu, NULL);
        sfRenderWindow_drawSprite(win, sprite->play_button, NULL);
        sfRenderWindow_drawSprite(win, sprite->option_button, NULL);
        sfRenderWindow_drawSprite(win, sprite->how_tp_click, NULL);
        sfRenderWindow_drawSprite(win, sprite->quit_button, NULL);
    }
}

void draw4(s_game *game, s_sprite *sprite, sfRenderWindow *win)
{
    if (game->statment == 1) {
        sfRenderWindow_drawSprite(win, sprite->bckg_menu, NULL);
        sfRenderWindow_drawSprite(win, sprite->how_tp, NULL);
        sfRenderWindow_drawSprite(win, sprite->play_pressed, NULL);
        sfRenderWindow_drawSprite(win, sprite->option_button, NULL);
        sfRenderWindow_drawSprite(win, sprite->quit_button, NULL);
    }
    if (game->statment == 0) {
        sfRenderWindow_drawSprite(win, sprite->bckg_menu, NULL);
        sfRenderWindow_drawSprite(win, sprite->play_button, NULL);
        sfRenderWindow_drawSprite(win, sprite->option_button, NULL);
        sfRenderWindow_drawSprite(win, sprite->quit_button, NULL);
        sfRenderWindow_drawSprite(win, sprite->how_tp, NULL);
    }
}

void draw5(s_game *game, s_sprite *sprite, sfRenderWindow *win)
{
    if (game->statment == 8) {
        sfRenderWindow_drawSprite(win, sprite->sprite_bck_option, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_musique, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_menu_opt, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_volume_p, NULL);
        sfRenderWindow_drawSprite(win, sprite->sprite_volume_m, NULL);
        if (game->sound == 1 && game->sound_modif < 100) {
            game->sound_modif += 10;
            game->sound = 0;
            sfMusic_setVolume(game->Music_game, game->sound_modif);
        }
        if (game->sound == 2 && game->sound_modif > 0) {
            game->sound_modif -= 10;
            game->sound = 0;
            sfMusic_setVolume(game->Music_game, game->sound_modif);
        }
    } if (game->statment == 9) {
        sfRenderWindow_drawSprite(game->window, sprite->bck_htp, NULL);
        sfRenderWindow_drawSprite(game->window, sprite->sprite_menu_opt, NULL);
    }
}