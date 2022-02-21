/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

//main.c
void int_to_str(char *s, int n, int size);
sfRenderWindow *createMyWindow(unsigned int width, unsigned int height);
int main(int ac, char **av);

//lib.c
void my_putchar(char const c);
void my_putstr(char *str);
int my_strlen(char const *str);
int my_getnbr(char const *str, int i);
int my_strcmp(char const *s1, char const *s2);

//my_strcnmp.c
int my_strncmp(char const *s1, char const *s2, int n);

//my_str_to_word_array.c
bool is_separator(char c);
int get_word_number(char const *str);
int get_wordlen(char const *str, int i);
char *fill_tab(char const *str, int *pos);
char **my_str_to_word_array(char const *str);

//create.c
sound_t *create_sound(const char *filepath, sfBool loop);
button_t *init_button(sfVector2f position, sfVector2f size);
text_t *create_text(char *text, sfVector2f pos,
                    int size, sfColor color);
protagonist_t *define_stat(int *stat, char *save);
struct_time_t *create_time();

//object.c
sfVector2f create_v2f(float x, float y);
sfIntRect create_rect_int(int top, int left, int width, int height);
object_t *create_object(char *path_to_spritesheet, sfVector2f pos,
                                  sfIntRect rect, sfVector2f scale);
void destroy_object(sfSprite *sprite, sfTexture *texture);

//time.c
void time_restart(struct_time_t *times);
void time_increase(struct_time_t *times);

//destroy.c
void destroy_sound(sfSound *sound, sfSoundBuffer *buffer);
void destroy_text(sfText *text, sfFont *font);

//buttons_state.c
int text_color(text_t *text);
int three_states_button(button_t *button, text_t *text, int pos);
void put_button_back(button_t *button, text_t *text, int pos);

//music_pause.c
void music_menu_pause(scene_t *menu, sfEvent event, sfVector2i click_position);
void music_area_pause(scene_t *area, sfEvent event, sfVector2i click_position);

//open_save.c
char *find_music(char *save);
char *find_sprite(char *save);
void open_map(sfRenderWindow *window, char *save, char *filepath);
void read_save(sfRenderWindow *window, char *save);
void open_save(sfRenderWindow *window);

//save.c
void verif_save(sfRenderWindow *window, scene_t *area);
void convert(protagonist_t *chara, char stat[6][10], char **map);
void save(protagonist_t *chara, char **map, char code);
