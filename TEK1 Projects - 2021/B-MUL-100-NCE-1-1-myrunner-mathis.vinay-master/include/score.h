/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** a struct for text
*/
#ifndef B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_score_H
#define B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_score_H

#include <SFML/Graphics.h>
#include "my.h"

typedef struct {
    sfFont *font;
    sfText *text;
    sfText *label;
    char *string;
} score_t;

score_t *create_score(char const *fontfile, char const *texte);
score_t *add_score(score_t *score);
void destroy_score(score_t *score);

#endif //B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_score_H
