/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#ifndef MACROS_H_
#define MACROS_H_

#define ERROR_CODE    84
#define SUCCESS_CODE  0

#define WIDTH         1920
#define HEIGHT        1080
#define PIXELS        32
#define FPS           60

#define BTN_HOVER     1.0125

#define NB_BUTTON     4

#define WAIT_FOR_BUTTON_RELEASE  while (sfMouse_isButtonPressed(0)) {}

#define __GET_POS_ON_CLICK(pos, size, scale) {    \
    pos.x + (size.x / scale - size.x) / 2,        \
    pos.y + (size.y / scale - size.y) / 2         \
}

#define __GET_MOUSE_POS(win) {                    \
    sfMouse_getPositionRenderWindow(win).x,       \
    sfMouse_getPositionRenderWindow(win).y        \
}

#define GET_POS_ON_CLICK   (sfVector2f)__GET_POS_ON_CLICK
#define GET_MOUSE_POS(win) (sfVector2f)__GET_MOUSE_POS(win)

#define CHECK_X(mouse_pos, pos, x1, x2)                               \
    (mouse_pos.x > pos.x + x1 && mouse_pos.x < pos.x + x2 ? 1 : 0)
#define CHECK_Y(mouse_pos, pos, y1, y2)                               \
    (mouse_pos.y > pos.y + y1 && mouse_pos.y < pos.y + y2 ? 1 : 0)

#define GET_TIME_EVERY_S(clock, s, div)                                    \
    (sfClock_getElapsedTime(clock).microseconds / div >= s ? 1 : 0)

#define X_OK (m_pos.x > temp.x && m_pos.x < temp.x + 64)
#define Y_OK (m_pos.y > temp.y && m_pos.y < temp.y + 64)

#endif /* MACROS_H_ */

#ifndef INCLUDES_H_
#define INCLUDES_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "elements.h"

#endif /* INCLUDES_H_ */

typedef struct framebuffer_s {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;

typedef struct vars_s {
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    sfVideoMode mode;
} vars_t;

//=======================//
//         GENERAL       //
//=======================//

// ------- Init -------- //
vars_t *vars_create(framebuffer_t *fb);
framebuffer_t *framebuffer_create(void);

// ------- Misc -------- //
void generate_random_seed(void);
void create_magic(items_t **it);

sfVector2f center_pos(sfVector2f pos);
sfTexture **get_button_textures(int i);
sfVector2f get_random_pos(int min, int max);
double get_angle(sfVector2i b, sfVector2i a);
sfRectangleShape ***create_terrain_overlay(void);
void set_menu_volume(menu_t *s_mn, menu_t *mn);
void print_framerate(vars_t *va, sfText *_FPS);
sfVector2f get_advancement(sfVector2f a, sfVector2f b);
sfRectangleShape *create_angle(sfVector2f pos, int r, sfColor out, sfColor in);
sfCircleShape *create_body(sfVector2f pos, int radius, sfColor out, sfColor in);

// ------ Create ------- //
sfText *create_text(sfVector2f pos, char *str, unsigned int size, sfColor col);
button_t *create_button(sfFloatRect pos_size, char *string, sfTexture *texture);
button_t *create_button_ns(sfFloatRect pos_size, char *string[],    \
                            sfTexture **texture, int i);
sfRectangleShape *create_rectangle(sfVector2f pos, sfVector2f s,        \
                                    sfTexture *tx, sfBool reset_rect);
slider_t *create_slider(sfFloatRect pos_size, char *string, \
                        sfTexture *texture, sfTexture *slider_texture);
void create_stats(items_t **it);

// ------ Destroy ------ //
void destroy_menu(menu_t *mn);
void destroy_slider(slider_t *slider);
void screen_end(framebuffer_t *fb, vars_t *va);

//=======================//
//          MENU         //
//=======================//

// ------- Menu -------- //
menu_t *init_menu(void);
void menu(framebuffer_t *fb, vars_t *va);
void game(framebuffer_t *fb, vars_t *va, menu_t *mn);
void settings(framebuffer_t *fb, vars_t *va, menu_t *mn);
void exit_game(framebuffer_t *fb, vars_t *va, menu_t *mn);
void high_score(framebuffer_t *fb, vars_t *va, menu_t *mn);

// -------Settings ------- //
int check_how_to_play(vars_t *va, play_t *py, button_t *btn, int j);
button_t *high_score_btn(void);
play_t *create_py(void);
play_t *init_py(button_t *btn);
void credits(vars_t *va, framebuffer_t *fb, menu_t *mn, int *ret);
void draw_play(vars_t *va, play_t *py, button_t *btn, int i);
void settings_button(button_t *btn, play_t *py, int opt, int i);
play_t *init_return(void);
void return_menu(vars_t *va, framebuffer_t *fb, menu_t *mn, int *ret);
//=======================//

// ---- Other Menus ---- //
void return_menu(vars_t *va, framebuffer_t *fb, menu_t *mn, int *ret);
void credits(vars_t *va, framebuffer_t *fb, menu_t *mn, int *ret);
void how_to_play(vars_t *va, framebuffer_t *fb, menu_t *mn, int *ret);

// ------- Init -------- //
menu_t *init_settings_menu(menu_t *mn);
void add_pos(menu_t *s_mn);
sfTexture **get_textures_for_buttons(void);
void set_slider_sizes(menu_t *s_mn, menu_t *mn);
void calculate_button_positions(menu_t *s_mn, sfFloatRect pos_size[2]);

// ------ Buttons ------ //
int check_if_return_is_pressed(int i);
void draw_settings_elements(vars_t *va, menu_t *s_mn);
int handle_interactions(vars_t *va, menu_t *s_mn, menu_t *mn);
void check_if_sound_interacted(menu_t *s_mn, menu_t *mn, int i, sfVector2f c);
void set_element_state(menu_t *s_mn, sfVector2f scale, sfVector2f pos, int i);

//=======================//
//          GAME         //
//=======================//

// ------ Pause  ------- //
int pause_menu(framebuffer_t *fb, vars_t *va, game_t *gm);
menu_t *create_pause_menu(void);
sfSprite *get_screenshot(sfRenderWindow *win);

// ------ Handle ------- //
void new_enemies(game_t *gm);
void display_terrain_overlay(vars_t *va, items_t **it, int opt);
health_t *handle_health_bar(sfVector2f pos, sfVector2f size);
sfIntRect handle_frames(obj_t *enem, sfIntRect text_rect);
sfIntRect small_zombie(obj_t *enem, sfIntRect text_rect);
sfIntRect big_zombie(obj_t *enem, sfIntRect text_rect);
void handle_animation(obj_t *enem);
void handle_tower_damaged(game_t *gm, obj_t *enem);
void handle_traps(game_t *gm, obj_t *enem, sfVector2f e_pos);
int handle_upgrade_tower(obj_t *tw, sfIntRect temp, sfTexture *texture);
int handle_hover_buttons(obj_t *tw, sfVector2f m_pos,   \
                            sfVector2f pos, sfColor colors[3]);
int handle_button(menu_t *p_mn, sfRenderWindow *win);

// ------- Init -------- //
game_t *init_game(void);
menu_t *create_env(void);
items_t **create_items(void);
void create_info(items_t **it);
void create_tower(items_t **it);
void create_store(items_t **it);
bullet_t *create_bullet(sfVector2f pos, sfVector2f motion, float type);
void create_magic(items_t **it);
void create_obscur_background(items_t **it);
obj_t *create_radius(obj_t *obj, game_t *gm);
void create_clone(items_t **it, int i, int j);
obj_t *init_object(sfVector2f pos, sfVector2f size, char *path);
void handle_skip_button(sfRenderWindow *win, wave_t *wave);
void set_button(menu_t *p_mn, sfVector2f offset, int opt, int i);

// -------- Bullet -------//
void check_if_enemy_in_lane(game_t *gm);
void update_bullets(sfRenderWindow *win, game_t *gm);
void handle_enemy_shot(game_t *gm);
void reduce_enemies_life(obj_t *blds, obj_t *enem, int trap);
void reduce_tower_life(obj_t *blds, obj_t *enem, sfVector2f blds_pos);
// --------- Add -------- //
void add_element(game_t *gm, int opt);
void bomb_opt(game_t *gm, obj_t *tower, sfVector2f pos);
void bonus_opt(game_t *gm, obj_t *tower, sfVector2f pos);
void tower_opt(game_t *gm, obj_t *tower, sfVector2f pos);
obj_t *tower_prep(sfVector2f pos, game_t *gm, sfIntRect pos_size);
obj_t *bomb_prep(sfVector2f pos, game_t *gm, sfIntRect pos_size);
obj_t *bonus_prep(sfVector2f pos, game_t *gm);

// -------- Check ------- //
void check_items(sfVector2f m_pos, game_t *gm);
void check_tower(vars_t *va, game_t *gm, int i, int j);
void check_bomb(vars_t *va, game_t *gm, int i, int j);
void check_bonus(vars_t *va, game_t *gm, int i, int j);
int check_draw(vars_t *va, play_t *btn, sfSprite *sprite);

// ------- Update ------- //
void update_towers(vars_t *va, obj_t *tw, game_t *gm);
void draw_tower_menu(vars_t *va, obj_t *tw);
void set_colors(obj_t *tw, sfColor colors[3]);
void check(obj_t *tw, sfVector2f pos, sfVector2f mouse_pos, game_t *gm);
sfIntRect handle_bonus(obj_t *temp, sfIntRect area, float bonus);
void update_enemies(vars_t *va, game_t *gm);
void update_elements(vars_t *va, game_t *gm);
void update_user_action(vars_t *va, game_t *gm);
void update_items(sfVector2f m_pos, game_t *gm, vars_t *va);
void handle_player_health_bar(sfRenderWindow *win, game_t *gm);
int create_area_bonus(game_t *gm, vars_t *va, int i, int j);
void reset_color(sfColor color, int i, int j, game_t *gm);
int is_a_forbiden_case(game_t *gm, sfVector2f m_pos);

#endif /* DEFENDER_H_ */
