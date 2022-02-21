/*
** EPITECH PROJECT, 2020
** B-MUL-100-NCE-1-1-myhunter-mathis.vinay
** File description:
** header for graphicals functions
*/
#ifndef B_MUL_100_NCE_1_1_MYHUNTER_MATHIS_VINAY_GRAPHICAL_FUNCS_H
#define B_MUL_100_NCE_1_1_MYHUNTER_MATHIS_VINAY_GRAPHICAL_FUNCS_H

#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

bool is_sprite_on_hover(sfSprite *sprite, sfRenderWindow *window);
struct sfRenderWindow *create_window(char const *name);
sfSprite *create_background(sfTexture *texture);
sfSprite *animate_background(sfSprite *b, int v);

#endif //B_MUL_100_NCE_1_1_MYHUNTER_MATHIS_VINAY_GRAPHICAL_FUNCS_H
