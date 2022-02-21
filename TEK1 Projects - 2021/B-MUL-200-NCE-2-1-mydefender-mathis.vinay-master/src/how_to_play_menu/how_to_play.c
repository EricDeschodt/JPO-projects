/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** how to play menu
*/

#include "../../include/how_to_play.h"

void how_to_play(how_t *htp)
{
    htp->htp = text_create("Protecc\tis\ta\tTower\tDefense\ttype\tof\t"
                            "game!\n\n"
                            "You\tmust\tdefend\tyour\tland\tby\tplacing\t"
                            "turrets"
                            "\nand\t"
                            "killing\tenemies\nthat\tinvade\tyour\tland\t!"
                            "\nOnce\tthey\tmade\ttheir\tway\tthrough,\tyou"
                            "\tloose"
                            "\thealth,\nif\tyour\thealth\tfalls\tdown\t"
                            "to\tZERO\tyou\tLOOSE!\n"
                            "Check\tout\tour\tMANUAL\tto\tknow\tmore\tabout\t"
                            "Invaders.\n"
                            "Click\ton\tTowers\tto\taccess\tthe\tupgrade\tmenu!"
                            "\n\nWho\tknows\twhen\tthe\t"
                            "Great\tInvasion\tstops"
                            "...\n", "C", sfWhite, false);
    text_set_outline(htp->htp, sfBlack, 1);
    text_set_pos(htp->htp, 850, 450, 40);
}

how_t *create_htp(void)
{
    how_t *htp = malloc(sizeof(how_t));
    htp->htp_title = text_create("How To PLay ?", "C", sfWhite, false);
    text_set_outline(htp->htp_title, sfBlack, 2);
    text_set_pos(htp->htp_title, 900, 100, 50);
    htp->return_button = button_create("assets/gui/return_button.png", "C");
    sprite_set_pos(htp->return_button, 960, 850, 1);
    how_to_play(htp);
    htp->last_mode = 0;
    htp->manual_button = button_create("assets/gui/compendium_button.png", "C");
    sprite_set_pos(htp->manual_button, 1700, 100, 1);
    return htp;
}

void htp_display(how_t *htp, sfRenderWindow *win)
{
    button_display(htp->return_button, win, true);
    button_display(htp->manual_button, win, true);
    text_display(htp->htp, win);
    text_display(htp->htp_title, win);
}

void htp_destroy(how_t *htp)
{
    text_destroy(htp->htp);
    text_destroy(htp->htp_title);
    sprite_destroy(htp->return_button);
    sprite_destroy(htp->manual_button);
    free(htp);
}