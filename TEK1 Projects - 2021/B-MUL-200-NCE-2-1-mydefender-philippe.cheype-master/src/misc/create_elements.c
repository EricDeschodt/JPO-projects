/*
** EPITECH PROJECT, 2021
** myDefender (Workspace)
** File description:
** create_elements
*/

#include "defender.h"

sfCircleShape *create_body(sfVector2f pos, int radius, sfColor out, sfColor in)
{
    sfCircleShape *body;

    pos.x -= radius;
    pos.y -= radius;
    body = sfCircleShape_create();
    sfCircleShape_setOutlineColor(body, out);
    sfCircleShape_setFillColor(body, in);
    sfCircleShape_setOutlineThickness(body, 1.0);
    sfCircleShape_setPosition(body, pos);
    sfCircleShape_setRadius(body, radius);
    return (body);
}

sfRectangleShape *create_angle(sfVector2f pos, int radius,  \
                                sfColor out, sfColor in)
{
    sfRectangleShape *angle;
    sfVector2f size = { 0, radius * 1.5 };

    angle = sfRectangleShape_create();
    sfRectangleShape_setOrigin(angle, size);
    sfRectangleShape_setPosition(angle, pos);
    sfRectangleShape_setSize(angle, size);
    sfRectangleShape_setFillColor(angle, out);
    sfRectangleShape_setOutlineColor(angle, in);
    sfRectangleShape_setOutlineThickness(angle, 1.0);
    return (angle);
}
