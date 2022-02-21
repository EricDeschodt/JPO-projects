/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a structure to handle buttons
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_BUTTONS_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_BUTTONS_H

#include <SFML/Audio.h>
#include <stdbool.h>
#include "sprites.h"
#include "textures.h"

sprite_t *button_create(char *texture_name, char const *pos);
void button_display(sprite_t *button, sfRenderWindow *win, bool should_animate);
bool button_is_on_over(sprite_t *button, sfRenderWindow *win);
bool button_is_clicked(sprite_t *button, sfRenderWindow *win, sfEvent event);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_BUTTONS_H
