/*
** EPITECH PROJECT, 2019
** ducky
** File description:
** ducky
*/

#ifndef _DUCKY_
#define _DUCKY_

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "my.h"
#include "struct.h"
#include "time.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void analyse_events(sfRenderWindow *window, s_show *image);
int render_window(sfRenderWindow *window, s_show image);
void load_sprites(s_show *image);
void destroy(sfRenderWindow *window, s_show *image);
void display(sfRenderWindow *window, s_show *image);
void move_rect(sfIntRect *rect, int offset, int max_value);
void load_background(s_show *image);
void move_duck(s_show *image);
void shoot_duck(sfRenderWindow *window, s_show *image);
int scoreboard(s_show *image);
void update_score(s_show *image);
char *my_revstr(char *str);
void dead_duck(s_show *image);
void draw_dead(sfRenderWindow *window, s_show *image);
int load_sound(s_show *image);
void load_crosshair(s_show *image);
void draw_heart(s_show *image);
void load_life(s_show *image);
void display_gameover(sfRenderWindow *window, s_show *image);
void load_fixed(s_show *image);
void analyse_gameover_events(sfRenderWindow *window, s_show *image);
void load_gameover_text(s_show *image);
void load_animations(s_show *image);
void display_menu(sfRenderWindow *window, s_show *image);
void load_play_text(s_show *image);
void load_exit(s_show *image);
void game_loop(sfRenderWindow *window, s_show *image);
void init_struct(s_show *image);
void load_duck_rev(s_show *image);
void check_dog(sfRenderWindow *window, s_show *image);
void move_duck_rev(s_show *image);
void move_rev(sfIntRect *rect, int offset, int max_value);
void shoot_duck_rev(sfRenderWindow *window, s_show *image);
void draw_dead_rev(sfRenderWindow *window, s_show *image);
void load_dog(s_show *image);
void move_dog(s_show *image);
void move_rect_dog(sfIntRect *rect, int offset, int max_value);
void draw_dog(sfRenderWindow *window, s_show *image);
void move_rev_dog(sfIntRect *rect, int offset, int max_value);
void load_dog_rev(s_show *image);
void move_dog_rev(s_show *image);
void draw_dog_rev(sfRenderWindow *window, s_show *image);
void load_duck_down(s_show *image);
void move_duck_down(s_show *image);
void move_up(sfIntRect *rect, int offset, int max_value);
void load_restart_text(s_show *image);
void save_score(s_show *image);
void load_best_score(s_show *image);
void update_best_score(s_show *image);
void read_best_score(s_show *image);
void start_game(s_show *image);
void check_bird(sfRenderWindow *window, s_show *image);
void display_text(sfRenderWindow *window, s_show *image);
void init_params(s_show *image);
void destroy_sprites(s_show *image);
void write_help_msg(int ac, char **av);
void destroy_menu(s_show *image);
void destroy_gameover(s_show *image);

#endif
