/*
** EPITECH PROJECT, 2020
** statment
** File description:
** rpg
*/

#include "../include/include.h"

void check_statment(s_game *game, s_sprite *sprite, players *player)
{
    if (game->statment != 2 && game->statment != 6 && game->statment < 8) {
        if ((game->mouse.x > sprite->vect_play.x && game->mouse.x <= sprite->vect_play.x + sprite->rect_play.width)
        && (game->mouse.y > sprite->vect_play.y && game->mouse.y <= sprite->vect_play.y + sprite->rect_play.height))
            game->statment = 1;
        else if ((game->mouse.x > sprite->vect_quit.x && game->mouse.x <= sprite->vect_quit.x + sprite->rect_quit.width)
        && (game->mouse.y > sprite->vect_quit.y && game->mouse.y <= sprite->vect_quit.y + sprite->rect_quit.height)) {
            game->statment = 3;
            if (game->event_stat.type == sfEvtMouseButtonPressed)
                game->statment = 4;
        }
        else if ((game->mouse.x > sprite->vect_option.x && game->mouse.x <= sprite->vect_option.x + sprite->rect_option.width)
        && (game->mouse.y > sprite->vect_option.y && game->mouse.y <= sprite->vect_option.y + sprite->rect_option.height)){
            game->statment = 5;
            if (game->event_stat.type == sfEvtMouseButtonPressed) {
                game->statment = 8;
                game->option = 1;
            }
        }
        else if ((game->mouse.x > sprite->vect_htp.x && game->mouse.x <= sprite->vect_htp.x + sprite->rect_htp.width)
        && (game->mouse.y > sprite->vect_htp.y && game->mouse.y <= sprite->vect_htp.y + sprite->rect_htp.height)) {
            game->statment = 7;
            if (game->event_stat.type == sfEvtMouseButtonPressed)
                game->statment = 9;
        }
        else
            game->statment = 0;
        if (game ->statment == 1 && game->event_stat.type == sfEvtMouseButtonPressed) {
                game->statment = 2;
        }
    }
    check_2(game, sprite, player);
}

void check_2(s_game *game, s_sprite *sprite, players *player)
{
    if (game->statment == 8) {
        if ((game->mouse.x > sprite->vect_volume_p.x && game->mouse.x <= sprite->vect_volume_p.x + sprite->rect_volume_p.width)
        && (game->mouse.y > sprite->vect_volume_p.y && game->mouse.y <= sprite->vect_volume_p.y + sprite->rect_volume_p.height)) {
            if (game->event_stat.type == sfEvtMouseButtonPressed)
                game->sound = 1;
        }
        else if ((game->mouse.x > sprite->vect_volume_m.x && game->mouse.x <= sprite->vect_volume_m.x + sprite->rect_volume_m.width)
        && (game->mouse.y > sprite->vect_volume_m.y && game->mouse.y <= sprite->vect_volume_m.y + sprite->rect_volume_m.height)) {
            if (game->event_stat.type == sfEvtMouseButtonPressed)
                game->sound = 2;
        }
    }
    if ((game->mouse.x > sprite->vect_menu_opt.x && game->mouse.x <= sprite->vect_menu_opt.x + sprite->rect_menu_opt.width)
    && (game->mouse.y > sprite->vect_menu_opt.y && game->mouse.y <= sprite->vect_menu_opt.y + sprite->rect_menu_opt.height)) {
        if (game->event_stat.type == sfEvtMouseButtonPressed)
            game->statment = 0;
    }
    if (game->inventory >= 1) {
        if ((game->mouse.x > sprite->vect_exit_invt.x && game->mouse.x <= sprite->vect_exit_invt.x + sprite->rect_exit_invent.width)
        && (game->mouse.y > sprite->vect_exit_invt.y && game->mouse.y <= sprite->vect_exit_invt.y + sprite->rect_exit_invent.height)) {
            game->inventory = 4;
            if (game->event_stat.type == sfEvtMouseButtonPressed)
                game->statment = 4;
        }
        else if ((game->mouse.x > sprite->vect_menu_invt.x && game->mouse.x <= sprite->vect_menu_invt.x + sprite->rect_menu_invent.width)
            && (game->mouse.y > sprite->vect_menu_invt.y && game->mouse.y <= sprite->vect_menu_invt.y + sprite->rect_menu_invent.height)) {
            game->inventory = 3;
            if (game->event_stat.type == sfEvtMouseButtonPressed)
                game->statment = 0;
        }
        else if ((game->mouse.x > sprite->vect_croix.x && game->mouse.x <= sprite->vect_croix.x + sprite->rect_croix.width)
        && (game->mouse.y > sprite->vect_croix.y && game->mouse.y <= sprite->vect_croix.y + sprite->rect_croix.height)) {
            game->inventory = 2;
            if (game->event_stat.type == sfEvtMouseButtonPressed)
                game->inventory = 0;
        }
        else
            game->inventory = 1;
    }
    if (game->statment == 16 && game->event_stat.type == sfEvtMouseButtonPressed) {
        if (game->mouse.x < 1627 && game->mouse.y > 438 && game->mouse.y < 508) {
            game->statment = 2;
            player->state = (player->inv->troph == false) ? 19: 20;
            player->pos_x = 5366;
            player->pos_y = 2800;
        }
        if (game->mouse.x > 720 && game->mouse.y > 700 && game->mouse.y < 764)
            game->statment = 4;
    }
}