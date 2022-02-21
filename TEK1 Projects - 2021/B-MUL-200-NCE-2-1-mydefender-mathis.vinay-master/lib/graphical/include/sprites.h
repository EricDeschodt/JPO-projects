/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** a struct to handle a sprite and his texture
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SPRITES_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SPRITES_H

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "textures.h"
#include "../../strings/include/strings.h"

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

sprite_t *sprite_create(char const *filepath, char const *pos, bool
is_repeted, bool is_smooth);
void sprite_display(sprite_t *element, sfRenderWindow *win);
void sprite_destroy(sprite_t *sprite);
void sprite_set_pos(sprite_t *sprite, float x, float y, float scale);
void sprite_set_origin(sprite_t *sprite, char const *pos);
void sprite_add_pos(sprite_t *sprite, float x, float y, float scale);
void sprite_set_texturerect_pos(sprite_t *sprite, int x, int y);
void sprite_add_texturerect_pos(sprite_t *sprite, int x, int y);
void sprite_set_texturerect_size(sprite_t *sprite, int x, int y);
void sprite_add_texturerect_size(sprite_t *sprite, int x, int y);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_SPRITES_H
