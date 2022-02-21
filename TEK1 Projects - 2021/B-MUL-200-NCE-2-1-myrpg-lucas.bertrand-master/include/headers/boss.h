/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

//create_boss_ficht.c
void destroy_boss_fight(scene_t *fight, protagonist_t *chara, int max);
void create_boss_fight_three(scene_t *fight, int max);
void create_boss_fight_two(scene_t *fight, int max);
int create_boss_fight_one(sfRenderWindow *window, int *pos,
                          int max, protagonist_t *chara);

//draw_boos_fight.c
int draw_boss_fight_three(sfRenderWindow *window, scene_t *fight, int *ret);
void draw_boss_fight_two(sfRenderWindow *window, scene_t *fight, int *ret, int max);
int draw_boss_fight_one(sfRenderWindow *window, scene_t *fight, int max);

//enemy_boss_fight.c
void boss_anim(sfRenderWindow *window, scene_t *fight);
int animattack_boss(sfRenderWindow *window, scene_t *fight, int *ret);
int boss_victory(scene_t *fight);
void boss_damage(scene_t *fight);
int boss_fight(sfRenderWindow *window, scene_t *fight, int atk);

//verif_boss.c
int analyse_events_boss_fight(sfRenderWindow *window, sfEvent event,
                              scene_t *fight, int max);
protagonist_t *before_boss_fight(protagonist_t *fighter, protagonist_t *player, int top);
void after_boss_fight(protagonist_t *fighter, protagonist_t *player);
int verif_boss_victory(sfRenderWindow *window, scene_t *fight,
                       int *ret, int max);
int verif_boss_click(sfRenderWindow *window, scene_t *fight, int max);
