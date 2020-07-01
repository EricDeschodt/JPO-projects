/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** render
*/

#include "runner.h"
#include "map.h"

void render_menu(controll_t *s_controll)
{
    init_buttons(s_controll);
    init_pause(s_controll);
    init_levels(s_controll);
    render_background(s_controll);
    render_title(s_controll);
    render_dead(s_controll);
}

void render_interface(controll_t *s_controll)
{
    render_coin_interface(s_controll);
    render_texts(s_controll);
}

void render_texts(controll_t *s_controll)
{
    s_controll->s_interface.nb_coin_int = 0;
    s_controll->font = sfFont_createFromFile("fonts/font.ttf");
    render_nbcoins_txt(s_controll);
    render_nbcoins_int(s_controll);
    render_distace_int(s_controll);
    render_ditance_txt(s_controll);
    end_txt_lose_gameover(s_controll);
    render_final_score_txt(s_controll);
    render_final_score_int(s_controll);
    render_win_txt(s_controll);
    render_best_txt(s_controll);
    render_best_int(s_controll);
}

void render_sprites(controll_t *s_controll, char *filepath)
{
    render_stopped(s_controll);
    render_jump(s_controll);
    render_slide(s_controll);
    render_jelly(s_controll);
    render_runner(s_controll);
    init_map(s_controll, filepath);
}

void render_sounds(controll_t *s_controll)
{
    background_sound(s_controll);
    jump_sound(s_controll);
    slide_sound(s_controll);
    coin_sound(s_controll);
}