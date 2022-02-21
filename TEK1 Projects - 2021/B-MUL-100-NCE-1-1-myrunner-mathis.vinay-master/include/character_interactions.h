/*
** EPITECH PROJECT, 2021
** B-MUL-100-NCE-1-1-myrunner-mathis.vinay
** File description:
** header for the character interactions
*/

#ifndef B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_CHARACTER_INTERACTIONS_H
#define B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_CHARACTER_INTERACTIONS_H

#include "map.h"
#include "character.h"

bool animate_map(map_t *map, character_t *chr, int v);
short get_block(map_t *map, float y, float x);
short get_crn_blk(map_t *map, character_t *chr, short corner,
bool should_below);
bool chr_apply_gravity(map_t *map, character_t *chr, float v, float angle);

#endif //B_MUL_100_NCE_1_1_MYRUNNER_MATHIS_VINAY_CHARACTER_INTERACTIONS_H
