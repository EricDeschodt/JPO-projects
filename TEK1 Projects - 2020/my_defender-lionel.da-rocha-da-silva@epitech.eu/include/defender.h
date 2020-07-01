/*
** EPITECH PROJECT, 2020
** defender
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
#include "get_next_line.h"
#include "my_string.h"
#include <math.h>

void create_world(s_game *game);
void analyse_events(s_game *game);
void update_world(s_game *game);
void draw_world(s_game *game);
void route_draw_calls(s_game *game);
void route_all_updates(s_game *game);
void free_ui(s_game *game);
sfBool get_key_down(sfKeyCode key);
sfBool on_key_released(sfKeyCode key, s_game **game);
void toggle_pause(s_game **game);
sfBool is_button_released(sfRenderWindow *w, sfMouseButton button, sfEvent e);
sfBool is_button_pressed(sfEvent *e, sfMouseButton button);
void on_click(s_game *d, s_slot *s, sfRenderWindow *w);
void on_slot_hover(void *data, s_slot *s, sfRenderWindow *w);
void on_drag(s_game *d, s_slot *s, sfRenderWindow *w);
char *to_string(int nb);
void push_back1(t_list **list, s_slot *data[], tw_type type);
void push_back(l_list **head, s_map *data);
l_list *pop_front(l_list *head);
l_list *pop_back(l_list *head);
int list_size(l_list *list);
l_list *free_list(l_list *head);
Button *button_create_selectable(char *button_text, sfVector2f pos,
    void (*OnClick)(void *), char *sprite_path);
sfBool is_mouse_hovering(sfFloatRect *rect, sfRenderWindow *window);
void    button_draw_selectable(sfRenderWindow *window,
    Button *button, void *arg, sfEvent e);
void    button_register_selectable(Button *button,
    sfRenderWindow *sfWindow, void *arg, sfEvent e);
Button *button_create(char *button_text, sfVector2f pos,
    void (*OnClick)(void *), char *sprite_path);
void    button_draw(sfRenderWindow *window, Button *button, void *arg,
    sfEvent e);
void    button_register(Button *button, sfRenderWindow *sfWindow, void *arg,
    sfEvent e);
void game_init(s_game *game);
s_map *create_map_object(char *filepath, sfVector2f pos, e_type type);
int find_flag(char c);
void create_map(s_game *game, char *path[], char *maps[], char *slots[]);
s_castle *create_castle_object(char *filepath[], sfVector2f pos, e_type type);
void create_castles(s_game *game);
s_mob *create_mob_object(char **filepath[], sfVector2f pos, e_type type);
void create_mob(s_game *game);
s_slot **create_slot_object(char *filepath[], sfVector2f pos);
Button *set_tower(t_tower *t, v2 pos);
t_tower *create_dam_tower(t_tower **t);
t_tower *create_slow_tower(t_tower **t);
t_tower *create_dot_tower(t_tower **t);
t_tower *create_freez_tower(t_tower **t);
void tower_menu_init(s_game *game);
void toggle_tower_menu(s_game *game, s_slot *s);
void tower_menu_draw(s_game *g);
void game_draw(s_game *game);
void update_map(s_game *game);
void draw_map(s_game *game);
void draw_castle(s_game *game);
void draw_mob(s_game *game);
void game_update(s_game *game);
void init_pause(s_game *game);
void pause_draw(s_game *game);
void pause_init_calls(s_game *g);
void run(s_game *game, int idx, int t);
void move_right_left(s_game *game, sfVector2i pos, int idx, int t);
void check_options(s_game *game, int idx, int t);
e_move check_pos(s_game *game, int idx, int t);
void move(s_game *game, int idx, int t);
void menu_init(s_game *game);
void menu_draw(s_game *game);
void menu_update(s_game *game);
void menu_init_buttons(s_game *game);
void menu_buttons_draw(s_game *game);
void page_levels_init(s_game *game);
void page_levels_update(s_game *game);
void page_levels_draw(s_game *game);
void page_score_init(s_game *game);
void page_score_update(s_game *game);
void page_score_draw(s_game *game);
void page_guide_init(s_game *game);
void page_guide_update(s_game *game);
void page_guide_draw(s_game *game);
void page_settings_init(s_game *game);
void page_settings_update(s_game *game);
void page_settings_draw(s_game *game);
void on_frame_up(void *d);
void on_frame_down(void *d);
sfText *text_center(sfText **text);
sfFont *load_font(const char *filename);
sfText *init_text(void);
sfText *put_text(sfText **text, const char *str, sfVector2f pos,
    int text_size);
int my_strlen(char *str);
char *my_revstr(char *str);
char *to_string(int nb);
void button_center_origin(Button **button);
void on_button_released(Button *button, void *arg, sfBool hovering);
sfBool mouse_button_down(sfRenderWindow *w, sfEvent e);
void map1(void *data);
void map2(void *data);
void map3(void *data);
void map4(void *data);
void map5(void *data);
void button_down(Button *button, sfRenderWindow *window, void *arg, sfEvent e);
void init_game_struct(s_game *game);
sfBool mouse_button_released(sfRenderWindow *w, sfEvent e);
void create_slot(s_slot **obj, v2 pos, char *filepath[], int i);
void on_click_levels(void *data);
void on_click_score(void *data);
void on_click_guide(void *data);
void on_click_settings(void *data);
void on_click_ret(void *data);
void on_quit(void *data);
void init_map(s_game *game);
void create_grid(s_game *game, s_var *tmp, int i);
s_wave *create_grid_struct(s_mob *mob, s_path **grid, int l);
int my_atoi(char *str);
void create_map_back(s_game *game, s_var *tmp, char *slots[], char *path[]);
char ***enemies_path();
void create_wave(s_game *game, int l, int k, char **path[]);
void move_switch(s_wave *w);
void game_init1(s_game *game);
void game_init2(s_game *game);
void read_guide(s_game *g);
void my_strcat(char *s1, char *s2);
void vol_init(s_game *g);
void vol_draw(s_game *g);
void vol_update(s_game *g);
int is_inRange(s_slot *slot, s_mob *mob);
s_life *castle_hud(s_game *game);
s_waves *wave_hud(s_game *game);
s_gld *gold_hud(s_game *game);
s_hud *create_hud(s_game *game);
void update_waves(s_game *game);
void update_gold(s_game *game);
void restart(s_game *game);
void on_menu(void *data);
void on_restart(void *data);
s_go *create_gameover(s_game *game);
void get_scores(s_game *game);
void gameover_update(s_game *game);
void draw_gameover(s_game *game);
s_scr *score_hud(s_game *game);
void atk_castle(s_game *game, int atk);
void on_upgrade_tower(void *d);
void button_register_h(Button *button, sfRenderWindow *window, sfEvent e,
                        sfBool enter);
int vol_update_press(s_game *g, int holding, int pressed);
void create_slot_pos(s_slot **obj, v2 pos, char *filepath[], int i);
void create_slot_rect(s_slot **obj, int i, sfColor white);
void create_dam(t_tower **t);
void create_slow(t_tower **t);
void create_dot(t_tower **t);
void create_freez(t_tower **t);
void tower_upgrade_init(t_tower_menu m, v2 pos, s_game *g);
void draw_map_slot(s_game *game);
void create_mob_obj(char **filepath[], s_mob *obj, e_type type);
void create_mob_e(s_game *game, int k, char ***path, int fd);
void game_update1(s_game *game);
void kill_mobs(s_game *game, int i);
void attack_update(s_game *game, t_list *tmp, float per);
void attack_update1(s_game *game, int i);
void attack_update2(s_game *game, t_list *tmp, int i, float per);
void attack_update3(s_game *game, int i, float per);
void attack_update4(s_game *game, t_list *tmp, int i, float per);
void game_init3(s_game *game, s_path tmp, int k);
int check_dead(s_game *game);
void game_loop(s_game *game);
void usage(void);

#endif
