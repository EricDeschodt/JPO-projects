/*
** EPITECH PROJECT, 2020
** include
** File description:
** rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct doors {
    sfTexture *text_cave;
    sfSprite *sprit_cave;
    sfTexture *text_tree;
    sfSprite *sprit_tree;
    sfTexture *text_door;
    sfSprite *sprit_door;
    sfTexture *text_door2;
    sfSprite *sprit_door2;
} doors;

typedef struct inventory {
    bool pick;
    bool key;
    bool map;
    bool troph;
    sfTexture *text_troph;
    sfTexture *text_key;
    sfTexture *text_punch;
    sfTexture *text_kick;
    sfTexture *text_map;
    sfTexture *text_pick;
    sfTexture *text_strangle;
    sfTexture *text_head;
    sfSprite *sprit_troph;
    sfSprite *sprit_key;
    sfSprite *sprit_punch;
    sfSprite *sprit_kick;
    sfSprite *sprit_map;
    sfSprite *sprit_pick;
    sfSprite *sprit_strangle;
    sfSprite *sprit_head;
    sfSprite *xp_bar;
    sfTexture **text_xp_bar;
    int lvl;
    sfText *lvl_txt;
    int xp;
    sfText *xp_txt;
} inventory;

typedef struct nb_util {
    int cur;
    int max;
} nb_util;

typedef struct pos {
    int x;
    int y;
} pos;

typedef struct mobs {
    int segment;
    int state;
    int recompense;
    int d;
    pos *posi;
    sfClock *clock_attaque;
    sfTexture *text;
    sfSprite *sprit;
    int life_sacha;
    int life_ennemi;
    int life_max_enne;
    int statu_ennemi;
    sfSprite **life_sprit;
    sfTexture **life_text;
    sfVector2f vect_life;
    sfSprite **sprit_life_enmi;
    sfTexture **text_life_enmi;
    sfVector2f vect_life_enmi;
    sfSprite *sprite_kick;
    sfIntRect rec_kick;
    sfVector2f vec_kick;
    sfText *nb_kick;
    sfSprite *sprite_punch;
    sfIntRect rec_punch;
    sfVector2f vec_punch;
    sfText *nb_punch;
    sfSprite *sprite_strangle;
    sfIntRect rec_strangle;
    sfVector2f vec_strangle;
    sfText *nb_strangle;
    sfSprite *sprite_headbut;
    sfIntRect rec_headbut;
    sfVector2f vec_headbut;
    sfText *nb_head;
    sfSprite *ennemi;
    sfVector2f vect_ennemi;
    sfSprite *sacha_f;
    sfVector2f vect_sacha_f;
    sfSprite *attack;
    sfText *txt_win;
    sfTexture *text_win;
    sfSprite *sprit_win;
    sfFont *font;
} mobs;

// state == 0 : idle
// state == 1 : intercating
// state == 2 : end

typedef struct pnjs {
    int segment;
    int state;
    int d;
    int stay;
    pos *posi;
    sfTexture *text;
    sfSprite *sprit;
    char **discus;
    sfClock *clock;
    sfText *text_struct;
    sfFont *font;
    sfTexture *text_bubble;
    sfSprite *sprit_bubble;
} pnjs;

typedef struct anim {
    int d;
    int i;
    sfTexture **text_punch;
    sfSprite *sprit_punch;
    sfTexture **text_kick;
    sfSprite *sprit_kick;
    sfTexture **text_head;
    sfSprite *sprit_head;
    sfTexture **text_strangle;
    sfSprite *sprit_strangle;
    sfTexture **text_enem;
    sfSprite *sprit_enem;
} anim;

typedef struct players {
    sfMusic *loading;
    int combat;
    int pos_x;
    int pos_y;
    char **map;
    sfTexture **text_up;
    sfSprite **sprit_up;
    sfTexture **text_down;
    sfSprite **sprit_down;
    sfTexture **text_left;
    sfSprite **sprit_left;
    sfTexture **text_right;
    sfSprite **sprit_right;
    sfClock *clock;
    int rot;
    int d;
    sfTexture *text_back;
    sfSprite *sprit_back;
    sfText *charg;
    sfFont *font;
    int max;
    int current;
    sfEvent event;
    sfTexture ***map_text;
    sfSprite ***map_sprit;
    pos ***pos_s;
    sfClock *move_player;
    int state;
    pnjs **pnj;
    mobs **mob;
    int current_mob;
    nb_util *kick;
    nb_util *punch;
    nb_util *headbut;
    nb_util *strangle;
    anim *ani;
    inventory *inv;
    doors *door;
    sfTexture *text_lose;
    sfSprite *sprit_lose;
    sfTexture *text_end;
    sfSprite *sprit_end;
} players;

typedef struct {
    sfMusic *Music_game;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfVector2f mouse;
    sfEvent event_stat;
    int statment;
    int inventory;
    int option;
    int sound;
    int sound_modif;
} s_game;

typedef struct {
    sfSprite *sprite_souris;
    sfIntRect rect_souris;
    sfSprite *bck_htp;
    sfIntRect rect_bck_htp;
    sfSprite *bckg_menu;
    sfMusic *click;
    sfSprite *sprite_croix;
    sfSprite *sprite_croix_p;
    sfIntRect rect_croix;
    sfIntRect rect_croix_p;
    sfSprite *sprite_inventaire;
    sfSprite *sprite_exit_invent;
    sfSprite *sprite_exit_invent_p;
    sfSprite *sprite_menu_invent_p;
    sfSprite *sprite_menu_invent;
    sfIntRect rect_inventaire;
    sfIntRect rect_menu_invent;
    sfIntRect rect_menu_invent_p;
    sfIntRect rect_exit_invent;
    sfIntRect rect_exit_invent_p;
    sfVector2f vect_menu_invt;
    sfVector2f vect_exit_invt;
    sfVector2f vect_croix;
    sfSprite *how_tp_click;
    sfIntRect rect_htp_click;
    sfVector2f vect_htp_click;
    sfSprite *how_tp;
    sfIntRect rect_htp;
    sfVector2f vect_htp;
    sfSprite *quit_button;
    sfIntRect rect_quit;
    sfVector2f vect_quit;
    sfSprite *quit_button_pressed;
    sfIntRect rect_quit_press;
    sfVector2f vect_quit_press;
    sfSprite *sprite_musique;
    sfSprite *sprite_volume_p;
    sfSprite *sprite_volume_m;
    sfSprite *sprite_menu_opt;
    sfIntRect rect_musique;
    sfIntRect rect_volume_p;
    sfIntRect rect_volume_m;
    sfIntRect rect_menu_opt;
    sfVector2f vect_musique;
    sfVector2f vect_volume_p;
    sfVector2f vect_volume_m;
    sfVector2f vect_menu_opt;
    sfFont *font2;
    sfSprite *sprite_bck_option;
    sfIntRect rect_bck_option;
    sfSprite *option_button;
    sfIntRect rect_option;
    sfVector2f vect_option;
    sfSprite *option_button_press;
    sfIntRect rect_option_press;
    sfVector2f vect_option_press;
    sfText *text_musique;
    sfSprite *play_button;
    sfSprite *play_pressed;
    sfSprite *play_click;
    sfIntRect rect_play_click;
    sfIntRect rect_play;
    sfVector2f vect_play;
    sfVector2f vect_play_click;
} s_sprite;

void fight_(s_game *game, mobs *mob, players *player);
void fight_2_(s_game *game, mobs *mob, players *player);
void fight_3_(s_game *game, mobs *mob, players *player);
void draw_game_inv(s_game *game, s_sprite *sprite, sfRenderWindow *win);
void draw2(s_game *game, s_sprite *sprite, sfRenderWindow *win,
players *player);
void draw3(s_game *game, s_sprite *sprite, sfRenderWindow *win);
void draw4(s_game *game, s_sprite *sprite, sfRenderWindow *win);
void draw5(s_game *game, s_sprite *sprite, sfRenderWindow *win);
void draw(s_game *game, s_sprite *sprite, players *player);
void init_sprite2_2(s_sprite *sprite);
void init_sprite_5_5(s_sprite *sprite);
void init_sprite_3_3(s_sprite *sprite);
void init_mob_sprite(mobs *mob, char *filepath, pos *posi);
void init_charg(players *player);
void init_door(players *player);
void print_door(sfRenderWindow *window, players *player, s_game *game);
void init_inventory(players *player);
void print_inventory(sfRenderWindow *window, players *player);
void init_animation(players *player);
void print_anim(sfRenderWindow *window, mobs *mob, players *player);
void print_mob(sfRenderWindow *window, mobs *mob, players *player);
void check_2(s_game *game, s_sprite *sprite, players *player);
void print_util(sfRenderWindow *window, mobs *mob, players *player);
char *str_add(char *str1, char *str2, char *str3);
void init_util_text(mobs *mob);
pnjs *pnj_champ();
void init_nb_util(players *player);
mobs *mob_spawn1();
void init_mob(players *player);
void print_combat(s_game *game, players *player, mobs *mob);
void init_p_sprit(players *player);
void rot_player(players *player, int rot);
void print_player(sfRenderWindow *window, players *player);
void print_pnj(sfRenderWindow *window, pnjs *pnj, players *player);
void init_pnj(players *player);
char *int_to_char(int nb);
void draw_charg(players *player, sfRenderWindow *window);
void cine(players *player, s_game *game);
pnjs *init_bubble(pnjs *pnj);
pnjs *pnj_merlin();
pnjs *pnj_spawn1();
pnjs *pnj_spawn2();
pnjs *pnj_spawn3();
pnjs *pnj_spawn4();
pnjs *pnj_cave();
pnjs *pnj_monster_cave();
pnjs *pnj_easter_egg();
void init_pnj_sprite(pnjs *pnj, char *filepath, pos *posi);

//src/life/init_life.c
void init_life(mobs *mob);
void init_life2(s_sprite *sprite);
void init_life_ennemi(mobs *mob);
void init_ennemi_2(s_sprite *sprite);

//src/life/life.c
void life(mobs *mob);

//src/map/map.c
players *init_player();
players *init_player2(players *player);
int init_text_map(players *player, int nb_line, char **map,
sfRenderWindow *window);
void init_sprit_map(players *player, int nb_line, char **map,
sfRenderWindow *window);
void init_map(players *player, sfRenderWindow *window, s_game *game);
void print_map(sfRenderWindow *window, players *player, s_game *game);

//src/map/utils_colli.c
int is_solid(char c);
int is_collide_y_dec(players *player);
int is_collide_x_dec(players *player);
int is_collide_y_inc(players *player);
int is_collide_x_inc(players *player);

//src/map/utils.map.c
sfIntRect *get_rect(int left, int top, int hidth, int width);
sfIntRect *nb_text(char c);
sfIntRect *nb_text2(char c);
void poll_event_map(sfRenderWindow *window, players *player, s_game *game);

//src/map/utils_player.c
pos *pos_player(players *player);
//src/map/utils_state.c
pos *convert_pos(int x, int y);
int check_in(players *player, pos *a, pos *b);
void get_status(players *player, s_game *game);

//src/sprite/init_sprite.c
sfSprite *sprite_creator(char *filepath);
void init_sprite(s_sprite *sprite);
void init_sprite2(s_sprite *sprite);
void init_sprite_3(s_sprite *sprite);
void init_sprite_4(s_sprite *sprite);
void init_sprite_5(s_sprite *sprite);
void init_sprite_6(s_sprite *sprite);

//src/utils
int my_strlen(char *str);
char *add_to_str(char *str, char *add, int pos, int error);
char *get_fin(char *str);
int get_pos(char *buf, int pos);
char *get_next_line(int fd);
void my_putchar(char a);
int my_putstr(char const *str);
int	my_strcmp(char *str, char *str2);
void update(sfRenderWindow *window);
void mouse(s_game *game, s_sprite *sprite);

//src/.c
void init_game(s_game *game, s_sprite *sprite);
int window(s_game *game, s_sprite *sprite);
void check_statment(s_game *game, s_sprite *sprite, players *player);

// Combat //
int fight(s_game *game, mobs *mob, players *player);
int fight_2(s_game *game, mobs *mob, players *player);
int fight_3(s_game *game, mobs *mob, players *player);
void init_fight(mobs *mob);

//check_mouse.c //
int check_mouse1(s_game *game, mobs *mob, players *player);
int check_mouse2(s_game *game, mobs *mob, players *player);
int check_mouse3(s_game *game, mobs *mob, players *player);
int check_mouse4(s_game *game, mobs *mob, players *player);

//end_fight.c //
void end_fight_player(s_game *game, mobs *mob, players* player);
void end_fight_ennemie(s_game *game, mobs *mob, players* player);
void check_end(s_game *game, mobs *mob, players* player);
void check_util(mobs *mob, players *player, int option);
void check_util2(mobs *mob, players *player, int option);


//spawn enemy //
mobs *mob_spawn1();
mobs *mob_pioche();
mobs *mob_champ_1();
mobs *mob_champ_2();
mobs *mob_champ_3();
mobs *mob_boss_one();
mobs *mob_three_lave();
mobs *mob_four_lave();
mobs *mob_boss_final();

//spawn good png //
pnjs *pnj_merlin();
pnjs *pnj_spawn1();
pnjs *pnj_spawn2();
pnjs *pnj_spawn3();
pnjs *pnj_spawn4();
pnjs *pnj_cave();
pnjs *pnj_mineur();
pnjs *pnj_mineur_2();
pnjs *pnj_one_lave();
pnjs *pnj_two_lave();
pnjs *pnj_champ_1();
pnjs *pnj_champ_2();
pnjs *pnj_easter_egg2();
pnjs *pnj_two_lave2();
pnjs *pnj_ange_1();
pnjs *pnj_ange_2();
pnjs *pnj_ange_3();
pnjs *pnj_ange_4();
pnjs *pnj_ange_5();
pnjs *pnj_ange_6();
pnjs *pnj_ange_7();
pnjs *pnj_ange_8();
pnjs *pnj_ange_9();
pnjs *pnj_ange_10();
pnjs *pnj_easter_egg_fin1();
pnjs *pnj_easter_egg_fin2();
pnjs *init_bubble(pnjs *pnj);

#ifndef my
#define my


#endif /* !my */