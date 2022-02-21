/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** interface struct
*/

#ifndef B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_INTERFACE_H
#define B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_INTERFACE_H

#include <SFML/Graphics.h>
#include <stdlib.h>

typedef struct {
    sfFont *font;
    sfTexture *logo_text;
    sfSprite * logo;
    sfTexture *play_text;
    sfTexture *replay_text;
    sfSprite *play;
    sfText *end_label;
} interface_t;

interface_t *create_interface(void);
void display_interface(sfRenderWindow *win, interface_t *i, short menu);
void destroy_interface(interface_t *interface);

#endif //B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_INTERFACE_H
