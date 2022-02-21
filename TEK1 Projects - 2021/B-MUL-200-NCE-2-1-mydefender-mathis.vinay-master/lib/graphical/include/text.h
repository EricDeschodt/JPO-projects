/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a struct for handling text easily
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TEXT_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TEXT_H

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "textures.h"
#include "../../strings/include/strings.h"

typedef struct text {
    sfFont *font;
    sfText *text;
}text_t;

void text_set_pos(text_t *text, float x, float y, int size);
void text_set_origin(text_t *text, char const *pos);
float get_pos_o_text(sfText *text, char pos, char axe);
text_t *
text_create(char const *string, char const *pos, sfColor color, bool is_thin);
void text_display(text_t *text, sfRenderWindow *win);
void text_destroy(text_t *text);
char *int_to_str(char *str, int nb);
void text_set_outline(text_t *text, sfColor color, float thickness);
void text_set_outline_rgb_color(text_t *text, int red, int green, int blue);
void text_set_rgb_color(text_t *text, int red, int green, int blue);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TEXT_H
