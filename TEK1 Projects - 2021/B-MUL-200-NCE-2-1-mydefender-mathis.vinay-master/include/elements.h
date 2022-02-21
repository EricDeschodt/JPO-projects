/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a struct containing all elements of the code
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_ELEMENTS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_ELEMENTS_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "../lib/graphical/include/graphical.h"
#include "main_menu.h"
#include "background.h"
#include "level_menu.h"
#include "game/main_game.h"
#include "end_menu.h"
#include "pause_menu.h"
#include "scoreboard.h"
#include "how_to_play.h"
#include "settings.h"

typedef struct {
    int mode;
    sfRenderWindow *win;
    main_menu_t *main;
    level_menu_t *level;
    back_ground_t *back;
    main_game_t *game;
    end_game_t *end;
    pause_menu_t *pause;
    scoreboard_t *score;
    how_t *htp;
    manual_t *manual;
    sound_t *click;
    sound_t *rollover;
    sfMusic *music_menu;
    sfMusic *music_garden;
    sfMusic *music_mountain;
    sfMusic *music_beach;
    setting_t *setting;
} element_t;

element_t *elements_create();
void elements_display(element_t *e);
void element_display_x(element_t *e);
void element_events_handling(element_t *e);
void elements_animate(element_t *e);
void elements_destroy(element_t *e);
void setting_update_sound_down(element_t *e);
void setting_update_sound_up(element_t *e);
void setting_update_music_up(element_t *e);
void setting_update_music_down(element_t *e);
void setting_update_game_down(element_t *e);
void setting_update_game_up(element_t *e);
void sounds_create(element_t *e);
void sounds_destroy(element_t *e);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_ELEMENTS_H
