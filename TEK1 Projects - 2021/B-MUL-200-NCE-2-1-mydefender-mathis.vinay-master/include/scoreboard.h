/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Handling scorebard interactions
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SCOREBOARD_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SCOREBOARD_H

#include "../include/libs.h"

typedef struct {
    char **board_tab;
    text_t *board_text;
    text_t *board_title;
    sprite_t *return_btn;
    int last_mode;
}scoreboard_t;

scoreboard_t *scoreboard_create(void);
void scoreboard_load(scoreboard_t *score, char *scorepath);
void scoreboard_destroy(scoreboard_t *score);
void scoreboard_display(scoreboard_t *score, sfRenderWindow *win);
void scoreboard_set_last_mode(scoreboard_t *score, int mode);
void scoreboard_add_score(char *path, int s);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SCOREBOARD_H
