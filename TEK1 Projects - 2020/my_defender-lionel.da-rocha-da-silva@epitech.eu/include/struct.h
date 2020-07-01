/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** my_list
*/

#ifndef MY_LIST_H_
#define MY_LIST_H_

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

typedef struct temp
{
    int j;
    int k;
    int n;
    int x;
    int y;
    char c;
} s_var;

typedef sfVector2f v2;

typedef sfRenderWindow rw;

typedef struct button_states_t
{
    sfTexture *texture_idle;
    sfTexture *texture_hover;
    sfTexture *texture_clicked;
} button_states;

typedef struct Button
{
    sfRectangleShape *rect_shape;
    sfTexture *texture_idle;
    sfTexture *texture_hover;
    sfTexture *texture_clicked;
    sfSprite *sprite;
    sfText *text;
    sfFloatRect rect;
    sfBool selected;
    sfVector2f pos;
    sfBool released;
    sfSound *sound;
    sfSound *clk_sound;
    const sfSoundBuffer *buffer;
    const sfSoundBuffer *clk_sound_buffer;
    int id;
    void (*click_event[10])(void *);
} Button;

typedef enum object_type
{
    LAND,
    ROAD,
    TOWER,
    CASTLE,
} e_type;

typedef enum monster_type
{
    DEVIL,
    KNIGHT,
    ASSASIN,
} m_type;

typedef enum moveset
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
} e_move;

typedef enum movement
{
    MOVING,
    STANDING,
} t_move;

typedef enum tower_type
{
    NONE,
    CANON,
    ICE,
    MAGIC,
    TESLA,
} tw_type;

typedef enum tower_level
{
    ZERO,
    ONE,
    TWO,
    THREE,
} tw_lvl;

typedef struct map_ground
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    e_type type;
} s_map;

typedef struct castle
{
    sfTexture *texture[3];
    sfSprite *sprite;
    sfVector2f pos;
    e_type type;
    int life;
    sfFont *font;
    sfText *text;
} s_castle;

typedef struct monsters
{
    sfTexture *textures[4];
    sfSprite *sprite;
    sfText *text;
    sfFont *font;
    sfVector2f text_pos;
    sfVector2f pos;
    m_type type;
    sfClock *clock;
    sfTime time;
    sfClock *moveclock;
    sfTime movetime;
    sfClock *atk_clock;
    sfTime atk_time;
    float atk_sec;
    float seconds;
    int life;
    float atk;
    float t_life;
    sfIntRect rect;
    int x;
    int y;
    float speed;
    sfBool dead;
    e_move moves;
    t_move state;
    sfBool attacked;
    sfColor color;
    sfBool blink;
    sfBool killed;
    sfBool xp;
    sfRectangleShape *life_bar;
} s_mob;

typedef struct tower
{
    int id;
    int lvl;
    int price;
    float atk;
    float dot_dmg;
    float time;
    float slow;
    float cd;
    float range;
    char *s_lvl;
    char *s_dmg;
    char *s_range;
    sfColor color;
    sfColor f_color;
    sfSprite *sprite;
    sfVector2f pos;
    sfText *text_atk;
    sfText *text_range;
} t_tower;

typedef struct slot
{
    void (*on_slot_hover)(void *, struct slot *, rw *);
    sfFloatRect rect;
    sfRectangleShape *shape_contour;
    sfRectangleShape *shape_selected;
    sfVector2f pos;
    sfSprite *sprite_tower;
    sfSprite *sprite;
    sfSprite *sprite_placable;
    sfTexture *texture;
    sfTexture *texture_placable;
    sfClock *clock;
    sfTime time;
    t_tower *tower;
    float range;
    float seconds;
    int is_tower;
    int is_selected;
    int id;
    sfColor color;
    sfColor f_color;
    sfCircleShape *area;
} s_slot;

typedef struct linked_list
{
    s_map *map;
    struct linked_list *next;
} l_list;

typedef struct linked_list_t
{
    s_slot *tower[6];
    tw_type type;
    struct linked_list_t *next;
} t_list;

typedef enum menu_state
{
    MENU,
    GAME,
    GAMEOVER
} e_menu_state;

typedef enum menu_pages
{
    LEVELS,
    SCORE,
    GUIDE,
    SETTINGS,
    NEG = -1
} e_menu_pages;

typedef enum maps
{
    MAP1,
    MAP2,
    MAP3,
    MAP4,
    MAP5,
} e_map;

typedef enum castle_state
{
    FULL,
    HALF,
    DESTROYED,
} c_states;

typedef struct page_level
{
    sfText *title;
    Button *b_map1;
    Button *b_map2;
    Button *b_map3;
    Button *b_map4;
    Button *b_map5;

} page_level_t;

typedef struct page_score
{
    sfText *title;
    char *best;
    sfText *bestscores;
} page_score_t;

typedef struct page_guide
{
    sfText *title;

} page_guide_t;

typedef struct page_settings
{
    Button *up;
    Button *down;
    sfText *title;
    sfText *framerate;
    sfText *title_volume;
    sfText *title_frame;
} page_settings_t;

typedef struct menu_s
{
    Button *button_return;
    Button *button_play;
    Button *button_levels;
    Button *button_score;
    Button *button_guide;
    Button *button_settings;
    Button *button_quit;
    page_level_t *level;
    page_score_t *score;
    page_guide_t *guide;
    page_settings_t *settings;
    e_menu_pages pages_state;
    sfSprite *menu_bg;
    sfSprite *pages_bg;
    sfMusic *music;
} menu_t;

typedef struct game_pause
{
    sfBool paused;
    sfText *title;
    sfSprite *bg;
    Button *b_res;
    Button *b_guide;
    Button *b_menu;
    Button *b_sett;
    Button *b_quit;
} game_pause_t;

typedef enum visited_cases
{
    PREV,
    NEXT,
} e_case;

typedef struct path_finding
{
    e_case move;
    sfVector2f pos;
} s_path;

typedef struct slot_arg
{
    s_slot *s;
    t_tower *t;
} a_slot_arg;

typedef struct tower_menu
{
    int slot_id;
    sfBool is_active;
    s_slot *slot;
    sfText *title;
    sfText *text_atk;
    sfText *text_slow;
    sfText *text_freez;
    sfText *text_dot;
    sfText *price_dam;
    sfText *price_slow;
    sfText *price_dot;
    sfText *price_freez;
    t_tower *t_tower_dam;
    t_tower *t_tower_slow;
    t_tower *t_tower_dot;
    t_tower *t_tower_freez;
    Button *button_dam;
    Button *button_slow;
    Button *button_dot;
    Button *button_freez;
    sfSprite *sprite_bg;
    sfSprite *sel_tower;
    sfSprite *coins;
} t_tower_menu;

typedef struct wave_tab
{
    s_mob *mob;
    s_path grid[21][41];
} s_wave;

typedef struct vol_slider
{
    sfRectangleShape *bg;
    sfRectangleShape *fr;
    sfVector2f size;
    float percentage;
    float x;
} vol_slider;

typedef struct castle_life
{
    sfSprite *sprite;
    sfTexture *texture;
    v2 pos;
    sfRectangleShape *hp;
    sfIntRect rect;
    int life;
} s_life;

typedef struct waves
{
    sfSprite *sprite;
    sfTexture *texture;
    v2 pos;
    int w_nb;
    int t_waves;
    sfText *text;
    sfFont *font;
} s_waves;

typedef struct money
{
    sfSprite *sprite;
    sfTexture *texture;
    v2 pos;
    int gold;
    sfText *text;
    sfFont *font;
    char *money;
} s_gld;

typedef struct hud_score
{
    int score;
    sfFont *font;
    sfText *text;
} s_scr;

typedef struct topbar
{
    sfSprite *sprite;
    sfTexture *texture;
    s_life *life;
    s_waves *waves;
    s_gld *gold;
    s_scr *score;
} s_hud;

typedef struct gameover_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfFont *font;
    sfText *gameover;
    sfText *best_scores_t;
    sfText *best_scores;
    Button *menu;
    Button *restart;
    Button *quit;
    sfBool check_score;
} s_go;

typedef struct game_content
{
    rw *window;
    sfBool released;
    sfVector2u w_size;
    sfEvent event;
    sfVideoMode mode;
    e_menu_state state;
    menu_t *menu;
    t_tower_menu tower_m;
    game_pause_t g_pause;
    e_map levels;
    c_states castle_states;
    sfInt32 paused_time;
    float m;
    l_list *maps[5];
    s_castle *castles[5];
    sfBool paused;
    s_wave ****enemies;
    s_wave ****b_enemies;
    s_path ***grid;
    t_list **slots;
    t_list **b_slots;
    sfEvent e;
    unsigned int framerate;
    int wave_nbs[4];
    int w_nb;
    int w_len[5];
    Button *w_button;
    sfBool sent;
    char *guide;
    vol_slider volume;
    s_hud *hud;
    s_hud *b_hud;
    s_go *gameover;
    int score;
    int bestscores[3];
    char *best;
    sfMusic *music;
    Button *b_tower_upgrade;
    sfBool upgr;
} s_game;

#endif
