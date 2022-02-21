/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** backgrounds header
*/
#ifndef B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_BACKGROUNDS_H
#define B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_BACKGROUNDS_H

#include "../include/graphical_funcs.h"

typedef struct {
    int vitesse;
    sfTexture *t_background;
    sfSprite *background;
    sfTexture *t_distantground;
    sfSprite *distantground;
    sfTexture *t_middleground;
    sfSprite *middleground;
    sfTexture *t_foreground;
    sfSprite *foreground;
} backgrounds_t;

backgrounds_t *create_backgrounds();
backgrounds_t *animate_backgrounds(backgrounds_t *b, int v);
backgrounds_t *display_backgrounds(sfRenderWindow *window, backgrounds_t *b);
void destroy_backgrounds(backgrounds_t *b);

#endif //B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_BACKGROUNDS_H
