/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** win
*/

#include "runner.h"
#include "map.h"

void render_win_txt(controll_t *s_controll)
{
    s_controll->s_interface.end.win = sfText_create();
    sfText_setString(s_controll->s_interface.end.win, "You Won!");
    sfText_setCharacterSize(s_controll->s_interface.end.win, 100);
    sfText_setPosition(s_controll->s_interface.end.win,
    (sfVector2f){720, 100});
    sfText_setFont(s_controll->s_interface.end.win, s_controll->font);
}

void win_move(controll_t *s_controll)
{
    if (s_controll->s_runner.pos.x < 2000)
        s_controll->s_runner.pos.x += s_controll->s_runner.secconds * 130;
    if (s_controll->s_jelly.pos.x > -500)
        s_controll->s_jelly.pos.x -= s_controll->s_jelly.secconds * 10;
    sfSprite_setPosition(s_controll->s_runner.sprite,
    s_controll->s_runner.pos);
    sfSprite_setPosition(s_controll->s_jelly.sprite,
    s_controll->s_jelly.pos);
}

void show_win(controll_t *s_controll)
{
    buttons_t *temp;
    buttons_t *temp2;
    sfRenderWindow_clear(s_controll->s_game.window, sfBlack);
    if (s_controll->s_slide.slide != 0) s_controll->s_slide.slide = 0;
    animation(s_controll), setpos_background(s_controll);
    s_controll->s_interface.end.strscore =
    my_put_strnbr(s_controll->s_interface.end.score_int);
    display_background(s_controll), display_runner(s_controll);
    temp = get_last_node(s_controll->s_pause), write_score(s_controll);
    win_move(s_controll), display_jelly(s_controll);
    temp2 = temp->next;
    temp->next = NULL;
    display_pause(s_controll);
    temp->next = temp2;
    display_end_txts(s_controll), check_on_button(s_controll);
    sfRenderWindow_display(s_controll->s_game.window);
}

void random_init(controll_t *s_controll)
{
    int i = 0;
    srand(time(NULL));
    i = rand() % 2;
    switch (i) {
        case 0 :
        init_map(s_controll, "maps/map1");
        break;
        case 1 :
        init_map(s_controll, "maps/map2");
        break;
        case 2 :
        init_map(s_controll, "maps/map3");
        break;
    }
}

void winning_check(controll_t *s_controll)
{
    if (s_controll->s_monster == NULL && s_controll->s_obstacle == NULL &&
    s_controll->s_obstacle == NULL) {
        if (s_controll->s_game.infinite == 0) {
            s_controll->s_game.scene = 5;
            s_controll->s_interface.end.score_int =
            s_controll->s_interface.distance_int *
            s_controll->s_interface.nb_coin_int;
            s_controll->s_interface.end.strscore =
            my_put_strnbr(s_controll->s_interface.end.score_int);
            sfText_setString(s_controll->s_interface.end.score,
            s_controll->s_interface.end.strscore);
        }
        else random_init(s_controll);
    }
}