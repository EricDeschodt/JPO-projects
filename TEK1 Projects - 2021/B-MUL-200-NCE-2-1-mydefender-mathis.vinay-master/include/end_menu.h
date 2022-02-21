/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** handles the end menu
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_END_MENU_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_END_MENU_H

#include "../include/libs.h"

typedef struct {
    sprite_t *replay_button;
    sprite_t *main_menu_button;
    sprite_t *exit_button;
    sprite_t *score_button;
    sprite_t *htp_button;
    text_t *your_score_text;
    char *your_score_str;
} end_game_t;

void endgame_add_your_score(end_game_t *endGame, int score);
void end_game_destroy(end_game_t *end_game);
void end_game_display(end_game_t *end_game, sfRenderWindow *win);
end_game_t *end_game_create(void);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_END_MENU_H
