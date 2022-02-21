/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** elements
*/

#ifndef ELEMENTS_H_
#define ELEMENTS_H_

#ifndef INCLUDES_H_
#define INCLUDES_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#endif /* INCLUDES_H_ */

#ifndef MENUS_H_
#define MENUS_H_

typedef struct button_s {
    sfRectangleShape *rect;
    sfFloatRect pos_size;
    sfText *text;
} button_t;

typedef struct slider_s {
    sfRectangleShape *slider;
    button_t *b;
} slider_t;

typedef struct menu_s {
    sfVector2f *pos_onclick;
    button_t *button;
    slider_t *slide;
    sfVector2f size;
    sfVector2f *pos;
    sfMusic *music;
    sfSprite *map;
    int state;
} menu_t;

#endif /* MENUS_H_ */

#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_

typedef struct info_s {
    sfText *killed_t;
    sfVector2i check;
    sfText *money_t;
    sfText *score_t;
    sfClock *clock;
    sfText **shop;
    int killed;
    int money;
    int score;
} info_t;

typedef struct clone_s {
    sfRectangleShape *rect;
    sfVector2f index;
} clone_t;

typedef struct items_s {
    sfRectangleShape ***overlay;
    sfRectangleShape *filter;
    sfRectangleShape **rect;
    sfCircleShape **circle;
    sfVector2f offset;
    sfVector2f size;
    sfVector2f *pos;
    clone_t temp;
    info_t info;
    int state;
} items_t;

typedef struct stats_s {
    float max_range;
    float is_slowed;
    float shot_by;
    float damage;
    float price;
    float speed;
    float row;
    int level;
} stats_t;

typedef struct bullet_s {
    sfRectangleShape *bullet;
    int is_exploding;
    sfVector2f motion;
    sfClock *clock;
    int frame;
    int type;
    int row;
    int stop;
    struct bullet_s *next, *prev, *head;
} bullet_t;

typedef struct health_s {
    sfRectangleShape *background;
    sfRectangleShape *bar;
    sfVector2f points;
} health_t;

typedef struct objects_s {
    sfRectangleShape **action;
    sfRectangleShape *radius;
    sfIntRect random_texture;
    sfFloatRect pos_size;
    sfClock *frame_clock;
    health_t health;
    stats_t stats;
    clone_t body;
    int stop;
    int frame;
    struct objects_s *next, *head, *prev;
} obj_t;

typedef struct play_s {
    sfVector2f *pos;
    sfVector2f *pos_onclick;
    button_t bg;
    button_t *rect;
} play_t;

typedef struct wave_s {
    button_t *skip_timer;
    button_t *time_left;
    sfClock *start_clock;
    sfClock *timer;
    int mem_kills;
    int skip;
    int status;
    int wave;
} wave_t;

typedef struct game_s {
    sfVector2f check;
    items_t **it;
    bullet_t *bl;
    wave_t *wave;
    menu_t *mn;
    sfMusic **sound;
    obj_t *tw;
    obj_t *en;
    int life_percent;
    sfText *life_percent_t;
    health_t *life;
} game_t;

#endif /* GAMEPLAY_H_ */

#endif /* ELEMENTS_H_ */
