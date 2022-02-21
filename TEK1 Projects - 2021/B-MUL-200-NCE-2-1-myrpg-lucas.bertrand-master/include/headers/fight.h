/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

//init_fight.c
protagonist_t *before_fight(protagonist_t *fighter, protagonist_t *player, int top);
void after_fight(protagonist_t *fighter, protagonist_t *palyer);
int init_fight(sfRenderWindow *window, scene_t *area, char **map);
int transition(sfRenderWindow *window, scene_t *area, char **map);

//create_fight.c
void destroy_fight(scene_t *fight);
void create_fight_three(scene_t *fight, bool pause);
void create_fight_two(scene_t *fight, bool pause);
int create_fight_one(sfRenderWindow *window,int max,
                     protagonist_t *chara, bool pause);

//draw_fight.c
void draw_inventory_fight(sfRenderWindow *window, char *inventory,
                          object_t *item, object_t *board);
int draw_fight_three(sfRenderWindow *window, scene_t *fight, int *ret);
void draw_fight_two(sfRenderWindow *window, scene_t *fight, int *ret, int max);
int draw_fight_one(sfRenderWindow *window, scene_t *fight, int max);

//fight_event.c
int analyse_events_fight(sfRenderWindow *window, sfEvent event,
                     scene_t *fight, int max);
int button_is_clicked_inventory_fight(scene_t *fight, sfVector2i click_pos);
int button_is_clicked_attack(scene_t *fight, sfVector2i click_position, int max);
int button_is_clicked_fight(sfRenderWindow *window, scene_t *fight, sfVector2i click_position);

//attack.c
void weak(scene_t *fight);
void defense(sfRenderWindow *window, scene_t *fight);
void animattack(sfRenderWindow *window, scene_t *fight);
int animattack_enemy(sfRenderWindow *window, scene_t *fight, int *ret);
int choose_attack(sfRenderWindow *window, scene_t *fight, int ret);

//enemy_fight.c
int victory(scene_t *fight);
void manage_damage(scene_t *player);
void enemy_damage(sfRenderWindow *window, scene_t *fight);
int enemy_fight(sfRenderWindow *window, scene_t *fight, int atk);

//verif_fight.c
int verif_enemy_attack(scene_t *fight);
int verif_attack(scene_t *fight);
int verif_mana(scene_t *fight, int i);
int verif_victory(sfRenderWindow *window, scene_t *fight,
                  int *ret, int max);
int verif_click(sfRenderWindow *window, scene_t *fight, int max);

//game_over.c
int button_is_clicked_game_over(scene_t *game_over, sfVector2i click_position);
int analyse_events_game_over(sfRenderWindow *window, sfEvent event,
                             scene_t *game_over);
void game_over_draw(sfRenderWindow *window, scene_t *game_over);
void destroy_game_over(scene_t *game_over);
void game_over(sfRenderWindow *window);
