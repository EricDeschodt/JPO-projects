/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** menu3
*/

#include "defender.h"
#include "utils.h"

void menu_release_selector4(all_t *s_all, int i)
{
    if (i == 11 && s_all->s_game.scene == 1 && s_all->s_game.pause == 1
    && s_all->s_player.defeat == 0) {
        if (s_all->s_settings->sound == 1)
                sfSound_play(s_all->s_sounds.button);
        s_all->s_game.lost_anim = 0; s_all->s_side_menu.draw = 0, s_all->
        s_hard_arrow.stat = 1, s_all->s_game.transition = 0, s_all->s_game.
        pause = 1, s_all->s_selected.on = 0, s_all->s_game.eric = 1;
        sfSprite_setTexture(s_all->s_buttons->begin->sprite,
        s_all->s_buttons->begin->texture, sfTrue);
    } if (i == 9 && s_all->s_game.scene == 1 && s_all->s_game.pause == 1
    && s_all->s_player.defeat != 1) { restart_level(s_all);
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    } if (i == 8 && s_all->s_game.scene == 1 && s_all->s_game.pause == 1
    && s_all->s_player.defeat != 1)
        s_all->s_game.pause = 0, sfSound_play(s_all->s_sounds.button);
    if (i == 7 && s_all->s_game.scene == 0) {
        sfRenderWindow_close(s_all->s_game.window), write_statistics(s_all);
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button); }
}

void defeat(all_t *s_all, int i)
{
    if (i == 11 && s_all->s_game.scene == 1 && s_all->s_game.pause == 1
    && s_all->s_player.defeat == 1) {
        end_game(s_all);
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    }
}

void menu_release_selector3(all_t *s_all, int i)
{
    if (i == 6 && s_all->s_game.scene == 0) {
        s_all->s_game.transition = 6, s_all->s_game.lost_anim = 0;
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    } if (i == 4 && s_all->s_game.scene == 0) {
        s_all->s_game.transition = 4, s_all->s_game.lost_anim = 0;
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    } if (i == 10 && s_all->s_game.scene == 1 && s_all->s_game.pause == 1
    && s_all->s_player.defeat == 0) {
        end_game(s_all);
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    } if (i == 3 && s_all->s_game.scene == 0) {
        actualize_stats(s_all), write_statistics(s_all);
        s_all->s_game.transition = 3, s_all->s_game.lost_anim = 0;
        if (s_all->s_settings->sound == 1)
            sfSound_play(s_all->s_sounds.button);
    } menu_release_selector4(s_all, i);
    defeat(s_all, i);
}