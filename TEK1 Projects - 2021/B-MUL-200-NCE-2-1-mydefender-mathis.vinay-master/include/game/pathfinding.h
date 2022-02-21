/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** Functions to move
*/

#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_PATHFINDING_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_PATHFINDING_H

bool move_ac(main_game_t *game, int i, int x, int y);
bool move_bd(main_game_t *game, int i, int x, int y);
bool move_r(main_game_t *game, int i, int x, int y);
bool move_q(main_game_t *game, int i, int x, int y);
bool move_e(main_game_t *game, int i, int x, int y);
bool move_f(main_game_t *game, int i, int x, int y);
bool move_g(main_game_t *game, int i, int x, int y);
bool move_h(main_game_t *game, int i, int x, int y);

bool move_enemy_basics(main_game_t *game, int i, int x, int y);
bool move_enemy_start(main_game_t *game, int i, int x, int y);
bool move_enemy_angle(main_game_t *game, int i, int x, int y);


#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_PATHFINDING_H
