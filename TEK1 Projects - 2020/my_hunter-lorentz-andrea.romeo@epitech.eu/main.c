/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** main
*/

#include "my.h"

void setup(all_t *all)
{
    all->video_mode.width = 800;
    all->video_mode.height = 600;
    all->video_mode.bitsPerPixel = 32;
    all->window = sfRenderWindow_create(all->video_mode, "Duck Hunt",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(all->window, 60);
    sfRenderWindow_setMouseCursorVisible(all->window, 0);
    srand(time(0));
}

void main_game(sfEvent event, all_t *all)
{
    sfText_setString(all->write.text4, all->write.round_count_text);
    if (all->my_int.main_menu == 0) {
        if (all->my_int.menu_check == 1)
            sfSound_stop(all->sound.menu), all->my_int.menu_check = 0;
        if (all->my_int.state == 0)
            clock_init(&all->clock), all->my_int.state++;
        clock_set(all), main_if_clock(all, event), draw_cursor(all);
        sfSprite_setTextureRect(all->sprite2.overlay2, all->rect.red_duck);
        sfRenderWindow_display(all->window);
        if (all->my_int.shoot == 1)
            all->my_int.shoot = 0;
        if (all->my_int.shoot2 == 1)
            all->my_int.shoot2 = 0;
        if (all->my_int.score_int >= 100000) {
            all->pos.pos_score.x = 583;
            sfText_setPosition(all->write.text6, all->pos.pos_score);
        }
    }
}

void main_menu2(all_t *all)
{
    if (all->my_int.menu_check == 0) {
        sfSound_play(all->sound.menu);
        all->my_int.menu_check = 1;
    }
    if (all->my_int.gun_clock < 20) {
        sfRenderWindow_drawSprite(all->window, all->sprite.menu_arrow,
            NULL);
    }
    else if (all->my_int.gun_clock > 30)
        all->my_int.gun_clock = 0;
    if (all->my_int.menu_dog == 8) {
        all->rect.menu_dog.left = move_menu_dog(all->rect.menu_dog).left;
        all->my_int.menu_dog = 0;
    }
    sfText_setPosition(all->write.text1, all->pos.pos_menu_score);
    sfRenderWindow_drawSprite(all->window, all->sprite.menu_dog, NULL);
    sfRenderWindow_drawText(all->window, all->write.text1, NULL);
    sfRenderWindow_display(all->window);
}

void main_menu(sfEvent event, all_t *all)
{
    if (all->my_int.main_menu == 1) {
        if (all->my_int.begin != 1) {
            *all = init_game_over(all);
            main_init(all);
            all->my_int.begin = 1;
        }
        all->my_int.gun_clock++;
        all->my_int.menu_dog++;
        analyse_events(event, all);
        sfSprite_setTextureRect(all->sprite.menu_dog, all->rect.menu_dog);
        sfSprite_setPosition(all->sprite.main_menu, all->pos.pos_main_menu);
        sfSprite_setPosition(all->sprite.menu_arrow, all->pos.pos_menu_arrow);
        sfSprite_setPosition(all->sprite.menu_dog, all->pos.pos_menu_dog);
        sfRenderWindow_clear(all->window, sfBlack);
        sfRenderWindow_drawSprite(all->window, all->sprite.main_menu, NULL);
        main_menu2(all);
    }
}

int main(int ac, char **av)
{
    if (ac == 1) {
        sfEvent event;
        main_render_game(event);
    }
    else if (ac == 2 && my_strlen(av[1]) == 2
    && av[1][0] == '-' && av[1][1] == 'h')
        manual();
    return (0);
}
