/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** some functions to handle textures
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TEXTURES_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TEXTURES_H

#include <SFML/Graphics.h>

#include "../../files/include/files.h"

sfTexture *texture_create(char const *filepath, bool is_repeted, bool
is_smooth);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_TEXTURES_H
