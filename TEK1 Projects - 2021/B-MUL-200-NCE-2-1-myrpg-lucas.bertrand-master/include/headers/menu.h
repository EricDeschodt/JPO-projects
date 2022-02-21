/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

//create_menu.c
void destroy_menu(scene_t *menu);
void create_menu_two(scene_t *menu);
void create_menu_one(sfRenderWindow *window);

//draw_menu.c
void draw_menu_one(sfRenderWindow *window, scene_t *menu);
void draw_menu_two(sfRenderWindow *window, scene_t *menu, bool *option);

//menu_event.c
int analyse_events_menu_two(sfRenderWindow *window, sfEvent event,
                            scene_t *menu, int ret);
int analyse_events_menu_one(sfRenderWindow *window, sfEvent event,
                            scene_t *menu, bool *option);
int button_is_clicked_menu_one(scene_t *menu, sfVector2i click_position);
int button_is_clicked_menu_two(scene_t *menu, sfVector2i click_position);
int button_is_clicked_option(scene_t *menu, sfVector2i click_position);

//option.c
int verif_option(scene_t *menu, int i);
void eric_mode(void);
void reset_map(char *filepath, char **map);
void verif_map(int i);
void erase_save(void);
