/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

//intro.c
void anim_intro(sfRenderWindow *window, scene_t *intro);
int analyse_event_intro(sfRenderWindow *window, sfEvent event,
                        scene_t *intro, int *i);
int draw_intro(sfRenderWindow *window, scene_t *intro);
void destroy_intro(scene_t *intro);
int create_intro(sfRenderWindow *window);

//dialogue.c
char *entry_labo_two(int x, int y);
void intro_dialogue(scene_t *intro, int i);
sfColor ending_color(int i);
void ending_dialogue(scene_t *ending, int i);

//story.c
char *entry_labo(int x, int y);
char *entry_3(int x, int y);
char *entry_2(int x, int y);
char *entry_1(int x, int y);
void entry(sfRenderWindow *window, scene_t *area, char **map);

//boss_intro.c
int boss_transition(sfRenderWindow *window, scene_t *boss);
int analyse_events_boss(sfRenderWindow *window, sfEvent event,
                        scene_t *boss, int *i);
int draw_boss(sfRenderWindow *window, scene_t *boss, char code);
void destroy_boss(scene_t *boss);
int create_boss(sfRenderWindow *window, char code, int left);

//boss_dialogue.c
char *boss_4(int i);
char *boss_3(int i);
char *boss_2(int i);
char *boss_1(int i);
void boss_dialogue(scene_t *boss, char code, int *i);

//after_boss.c
int analyse_events_after_boss(sfRenderWindow *window, sfEvent event, int *i);
int draw_after_boss(sfRenderWindow *window, scene_t *boss, char code);
void destroy_after_boss(scene_t *boss);
int create_after_boss(sfRenderWindow *window, char code, int left);

//after_boss_dialogue.c
char *before_ultimate_boss(int i);
char *after_boss_3(int i);
char *after_boss_2(int i);
char *after_boss_1(int i);
void after_boss_dialogue(scene_t *boss, char code, int *i);

//before_ultimate_fight.c
int analyse_events_before_ultimate_boss(sfRenderWindow *window, sfEvent event,
                                        scene_t *boss, int *i);
int draw_before_ultimate_boss(sfRenderWindow *window, scene_t *boss);
void destroy_before_ultimate_boss(scene_t *boss);
int create_before_ultimate_boss(sfRenderWindow *window, protagonist_t *stat);

//ending.c
int button_is_clicked_ending(scene_t *ending, sfVector2i click_pos);
int analyse_event_ending(sfRenderWindow *window, sfEvent event,
                         scene_t *ending, int *i);
int draw_ending(sfRenderWindow *window, scene_t *ending);
void destroy_ending(scene_t *ending);
int create_ending(sfRenderWindow *window);

//anim_ending.c
void player(scene_t *ending);
int light(scene_t *ending);
void last_attack(scene_t *ending);
void last_surprise(scene_t *ending);
void draw_ending_two(sfRenderWindow *window, scene_t *ending, int i);

//end.c
int end(sfRenderWindow *window);
void destroy_end(scene_t *end);
int draw_end(sfRenderWindow *window, scene_t *end);
int analyse_event_end(sfRenderWindow *window, sfEvent event, scene_t *end);
int button_is_clicked_end(scene_t *end, sfVector2i click_position);

//end_credit.c
int anim_end(scene_t *end);
void end_credit(scene_t *end);
