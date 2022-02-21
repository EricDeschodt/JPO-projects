/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

//inventory.c
char *filled_inventory(char *save);
int check_inventory(scene_t *area);
int wrong_item(scene_t *area, int i);
int choose_object(scene_t *area, int i);

//chest.c
char **chest_down(object_t *chara, int *move,
                  scene_t *area, char **map);
char **chest_right(object_t *chara, int *move,
                   scene_t *area, char **map);
char **chest_left(object_t *chara, int *move,
                  scene_t *area, char **map);
char **chest_up(object_t *chara, int *move,
                scene_t *area, char **map);
char **chest(object_t *chara, int *move,
             scene_t *area, char **map);

//get_item.c
void item_labo(scene_t *area, int x, int y);
void item_crypt3(scene_t *area, int x, int y);
void item_crypt2(scene_t *area, int x, int y);
void item_crypt1(scene_t *area, int x, int y);
void get_item(scene_t *area, char **map, int x, int y);

//health_item.c
void health_item_10(protagonist_t *player);
void health_item_25(protagonist_t *player);
void health_item_50(protagonist_t *player);
void health_item_max(protagonist_t *player);

//magic_item.c
void magic_item_5(protagonist_t *player);
void magic_item_15(protagonist_t *player);
void magic_item_30(protagonist_t *player);
void magic_item_max(protagonist_t *player);

//attack_item.c
int choose_object_fight(scene_t *fight, int i);
void attack_up_1(protagonist_t *player);
void attack_up_3(protagonist_t *player);
void defense_up_1(protagonist_t *player);
void defense_up_3(protagonist_t *player);
