/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** pos_init
*/

#include "my.h"

void init_pos_menu(pos_menu_t *pos_menu)
{
    pos_menu->level1.x = 860;
    pos_menu->level1.y = 140;
    pos_menu->levels.x = 860;
    pos_menu->levels.y = 290;
    pos_menu->ia.x = 860;
    pos_menu->ia.y = 440;
    pos_menu->quit.x = 860;
    pos_menu->quit.y = 590;
    pos_menu->back.x = 860;
    pos_menu->back.y = 740;
}

void init_pos(pos_t *pos)
{
    pos->pos_michael.x = 350;
    pos->pos_michael.y = 520;
    pos->pos_crouch.x = 350;
    pos->pos_crouch.y = 630;
    pos->pos_hat.x = 435;
    pos->pos_hat.y = 580;
}

void init_pos_background2(background_pos_t *pos)
{
    pos->pos_layer1_2.x = 0;
    pos->pos_layer1_2.y = -46;
    pos->pos2_layer1_2.x = 1920;
    pos->pos2_layer1_2.y = -46;
    pos->pos2_layer5.x = 1920;
    pos->pos2_layer5.y = 0;
}

void init_pos_background(background_pos_t *pos)
{
    pos->pos_layer1.x = 0;
    pos->pos_layer1.y = 0;
    pos->pos_layer2.x = 0;
    pos->pos_layer2.y = -285;
    pos->pos_layer3.x = 0;
    pos->pos_layer3.y = 0;
    pos->pos_layer4.x = 0;
    pos->pos_layer4.y = 0;
    pos->pos_layer5.x = 0;
    pos->pos_layer5.y = 0;
    pos->pos2_layer1.x = 1920;
    pos->pos2_layer1.y = 0;
    pos->pos2_layer2.x = 1920;
    pos->pos2_layer2.y = -285;
    pos->pos2_layer3.x = 1920;
    pos->pos2_layer3.y = 0;
    pos->pos2_layer4.x = 1920;
    pos->pos2_layer4.y = 0;
    init_pos_background2(pos);
}
