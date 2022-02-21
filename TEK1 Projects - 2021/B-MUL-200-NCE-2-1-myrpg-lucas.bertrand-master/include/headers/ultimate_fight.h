/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

//create_ultimate_fight.c
protagonist_t *before_ultimate_fight(protagonist_t *fighter, protagonist_t *stat);
void destroy_ultimate_fight(scene_t * fight);
void create_ultimate_fight_three(scene_t *fight);
void create_ultimate_fight_two(scene_t *fight);
int create_ultimate_fight_one(sfRenderWindow *window, protagonist_t *stat,
                              sound_t *music);

//draw_ultimate_fight.c
void draw_inventory_ultimate_fight(sfRenderWindow *window, char *inventory,
                                   object_t *item, object_t *board);
int draw_ultimate_fight_three(sfRenderWindow *window, scene_t *fight,
                              int *ret, sound_t *music);
void draw_ultimate_fight_two(sfRenderWindow *window, scene_t *fight);
int draw_ultimate_fight_one(sfRenderWindow *window, scene_t *fight,
                            sound_t *music);

//ultimate_fight_event.c
int analyse_event_ultimate_fight(sfRenderWindow *window, sfEvent event, scene_t *fight);
int button_is_clicked_inventory_ultimate_fight(scene_t *fight, sfVector2i click_pos);
int choose_ultimate_attack(sfRenderWindow *window,
                           scene_t * fight, int ret);
int button_is_clicked_ultimate_attack(scene_t *fight, sfVector2i click_position);
int button_is_clicked_ultimate_fight(sfRenderWindow *window, scene_t *fight, sfVector2i click_position);

//animation.c
void ultimate_weak(scene_t *fight);
void ultimate_defense(scene_t *fight);
void ultimate_animattack(sfRenderWindow *window, scene_t *fight);
void epilepsie(scene_t *fight);
int epilepsie_lazer(sfRenderWindow *window, scene_t *fight, sound_t *music);

//ultimate_enemy_fight.c
void ultimate_manage_damage(scene_t *fight);
void ultimate_enemy_damage(scene_t *fight);
int ultimate_enemy_fight(sfRenderWindow *window, scene_t *fight, sound_t *music);
int dodge(scene_t *fight);
void restore(scene_t *fight);

//verif_ultimate_fight.c
int choose_object_ultimate_fight(scene_t *fight, int i);
int verif_ultimate_click(sfRenderWindow *window, scene_t *fight);
int ultimate_verif_enemy_attack(scene_t *fight);
int ultimate_verif_attack(scene_t *fight);
int ultimate_verif_mana(scene_t *fight, int i);
