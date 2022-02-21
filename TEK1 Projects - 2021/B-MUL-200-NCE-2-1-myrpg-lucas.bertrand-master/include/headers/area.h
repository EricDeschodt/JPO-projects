/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

//create_area.c
void destroy_area(scene_t *area);
void create_area_three(scene_t *area);
void create_area_two(scene_t *area, char code);
void create_area_one(sfRenderWindow *window, char **file,
                     int *stat, char *save);

//draw_area.c
void draw_inventory(sfRenderWindow *window, char *inventory,
                    object_t *item);
void draw_pause(sfRenderWindow *window, scene_t *area);
void draw_tile(sfRenderWindow *window, char **map,
               object_t *tile, int *move);
int draw_area_two(sfRenderWindow *window, scene_t *area,
                  char **map, int ret);
void draw_area_one(sfRenderWindow *window, scene_t *area, char **map);


//area_event.c
int verif_fight(scene_t *area, char **map);
void menu_pause(scene_t *area, sfEvent event);
int analyse_events_area(sfRenderWindow *window, sfEvent event,
                        scene_t *area, char **map);
int button_is_clicked_inventory(scene_t *area, sfVector2i click_pos);
int button_is_clicked_pause(sfRenderWindow *window, sfEvent event,
                            scene_t *area, char **map);

//tile.c
int boundaries_up(object_t *protagonist, int *move);
int boundaries_right(object_t *protagonist, int *move);
int boundaries_left(object_t *protagonist, int *move);
int boundaries_down(object_t *protagonist, int *move);

//move.c
int up(object_t *protagonist, struct_time_t *time,
       int *move, char **map);
void right(object_t *protagonist, struct_time_t *time,
           int *move, char **map);
void down(object_t *protagonist, struct_time_t *time,
          int *move, char **map);
void left(object_t *protagonist, struct_time_t *time,
          int *move, char **map);
int move(scene_t *area, int ret, char **map);

//bordure.c
void move_update(protagonist_t *player, sfVector2f pos);
int bordure_up(object_t *chara, int *move, char **map);
int bordure_right(object_t *chara, int *move, char **map);
int bordure_down(object_t *chara, int *move, char **map);
int bordure_left(object_t *chara, int *move, char **map);


//next_map.c
int init_boss_fight(sfRenderWindow *window, scene_t *area, char next_code);
void modif_save_boss(sfRenderWindow *window, scene_t *area,
                     char **map, char next_code);
void next_map_boss(sfRenderWindow *window, scene_t *area,
                   char code, char **map);
int modif_save(sfRenderWindow *window, scene_t *area,
               int i, char **map);
int next_map(sfRenderWindow *window, scene_t *area, char code, char **map);
