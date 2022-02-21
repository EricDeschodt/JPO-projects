/*
** EPITECH PROJECT, 2021
** B-MUL-200-NCE-2-1-mydefender-mathis.vinay
** File description:
** gets and calculate the angle
*/

#include "../../../include/game/turrets.h"
#include "../../../include/game/main_game.h"

double to_degrees(double radian)
{
    double degrees = radian * 180 / M_PI;
    return degrees;
}

float get_angle(float x, float y, float x1, float y1)
{
    float angle = (float) to_degrees(atan2f(x1 - x, y - y1));
    return angle;
}