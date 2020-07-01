/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** background
*/

#include "runner.h"

void render_background(controll_t *scontroll)
{
    render_layer1(scontroll), render_layer1_bis(scontroll);
    render_layer2(scontroll), render_layer2_bis(scontroll);
    render_layer3(scontroll), render_layer3_bis(scontroll);
    render_layer4(scontroll), render_layer4_bis(scontroll);
    render_layer5(scontroll), render_layer5_bis(scontroll);
    render_layer6(scontroll), render_layer6_bis(scontroll);
    render_layer7(scontroll), render_layer8(scontroll);
}

void display_background(controll_t *s_controll)
{
    layers_display1(s_controll);
    layers_display2(s_controll);
}

void setpos_background(controll_t *s_controll)
{
    layers_setpos1(s_controll);
    layers_setpos2(s_controll);
}

void move_layers(controll_t *s_controll)
{
    move_layer_1(s_controll);
    move_layer_2(s_controll);
    move_layer_3(s_controll);
    move_layer_4(s_controll);
    move_layer_5(s_controll);
    move_layer_6(s_controll);
}