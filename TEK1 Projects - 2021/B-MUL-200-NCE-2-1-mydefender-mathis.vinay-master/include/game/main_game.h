/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** game menu hearder
*/
#ifndef B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_MAIN_GAME_H
#define B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_MAIN_GAME_H

#include <math.h>
#include "../../lib/graphical/include/graphical.h"
#include "../../lib/tabs/include/tabs.h"
#include "../../lib/linked_lists/include/linked_lists.h"
#include "../time.h"
#include "init_enemies.h"
#include "turrets.h"
#include "sidebar.h"

typedef struct {
    char **map;
    _time_t *time;
    sfTexture **texture_list;
    sprite_t *map_tampon;
    sprite_t *t_indic;
    sprite_t *range_indicator;
    enemy_t **enemy_list;
    turret_t **turret_list;
    sidebar_t *sidebar;
    int turret_selected;
    int nb_enemies;
    int nb_turrets;
    double difficulty;
    double offset;
    double homogenity;
    int row_max;
    int col_max;
    int hp;
    int gold;
    int wave;
    int volume;
} main_game_t;

main_game_t *main_game_create(int volume);
void main_game_init(main_game_t *game, char *mappath);
bool main_game_animate(main_game_t *game);
void
main_game_display(main_game_t *game, sfRenderWindow *win, bool should_animate);
void main_game_destroy(main_game_t *game, bool is_full);
int *get_start_pos(char **map);

bool choice_enemy_type(main_game_t *game, enemy_t *enemy);

void texts_set_colors(upgrade_t *u);

bool is_inmap(char **map, sfVector2f position);
bool is_spwnd(enemy_t **enemies);
bool are_all_enemies_dead(enemy_t **enemies, char **map);
enemy_t **
create_enemy_list(main_game_t *game);
void add_difficulty(main_game_t *g, double degree);
bool animate_enemies(main_game_t *g);
void display_enemies(main_game_t *game, sfRenderWindow *win);
void pathfinder(main_game_t *g, int i, double v);
void map_display(main_game_t *game, sfRenderWindow *win);
void turret_indicator_display(main_game_t *g, sfRenderWindow *win);
bool is_map_case_correct(main_game_t *g, sfVector2i m_pos);
sfVector2i
get_proper_pos(main_game_t *g, sfVector2i m_pos, bool is_turret);
int get_row_index(main_game_t *game, sfSprite *enemy);
int get_col_index(main_game_t *game, sfSprite *enemy);
sfTexture **create_texturelist(void);
void sidebar_init(sidebar_t *sidebar, main_game_t *game);
void upgrade_update(main_game_t *g);

turret_t **turret_add(main_game_t *g, sfVector2i mouse_pos, int mode);
void turret_display(main_game_t *game, sfRenderWindow *win);
void turret_animate(main_game_t *game);
turret_t *turret_create(main_game_t *g, sfVector2f pos, int mode);
void turret_set(main_game_t *g, turret_t *turret, sfVector2f pos);
void turret_trigger(main_game_t *g);
void turret_fire(main_game_t *g, turret_t *t, enemy_t *e);
void turret_place(main_game_t *g, sfEvent event, sfRenderWindow *win, int t_nb);

sfVector2f get_nearest_coords(main_game_t *g, turret_t *t, int index);
int get_nearest_index(main_game_t *g, turret_t *t);
double calculate(turret_t *t, sfVector2f e_pos);
void set_mouse_indicator(main_game_t *game, sfRenderWindow *win, int mode,
sfVector2i pos);

bullet_t *bullet_create(main_game_t *g, turret_t *t, enemy_t *enemy);
bullet_t **bullet_add(main_game_t *g, turret_t *t, enemy_t *enemy);
void bullets_animate(main_game_t *g, int vitess);
void
sidebar_display(main_game_t *g, sfRenderWindow *win, bool should_animate);
void bullet_display(main_game_t *g, sfRenderWindow *win);

#endif //B_MUL_200_NCE_2_1_MYDEFENDER_MATHIS_VINAY_MAIN_GAME_H
