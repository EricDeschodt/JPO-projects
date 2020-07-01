/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** slider3
*/

#include "defender.h"

void slider_on_abilities(all_t *s_all)
{
    turret_t *tmp = s_all->s_turret;
    for (; tmp != NULL; tmp = tmp->next) {
        abilities_t *abilities = tmp->abilities;
        for (; abilities != NULL; abilities = abilities->next) {
            sfRectangleShape_setPosition(abilities->rectangle, (sfVector2f)
            {sfRectangleShape_getPosition(abilities->rectangle).x - 50,
            sfRectangleShape_getPosition(abilities->rectangle).y});
            sfSprite_setPosition(abilities->upgrade, (sfVector2f)
            {sfSprite_getPosition(abilities->upgrade).x - 50,
            sfSprite_getPosition(abilities->upgrade).y});
            sfSprite_setPosition(abilities->under, (sfVector2f)
            {sfSprite_getPosition(abilities->under).x - 50,
            sfSprite_getPosition(abilities->under).y});
            sfText_setPosition(abilities->name, (sfVector2f)
            {sfText_getPosition(abilities->name).x - 50,
            sfText_getPosition(abilities->name).y});
        } tmp->pos_xp.x -= 50, sfText_setPosition(tmp->name, (sfVector2f){s_all
        ->s_info_text.pos_title.x, s_all->s_info_text.pos_title.y - 20});
        sfRectangleShape_setPosition(tmp->xp_bar, tmp->pos_xp);
        sfRectangleShape_setPosition(tmp->under, tmp->pos_xp); }
}

void slider_off_abilities(all_t *s_all)
{
    turret_t *tmp = s_all->s_turret;
    for (; tmp != NULL; tmp = tmp->next) {
        abilities_t *abilities = tmp->abilities;
        for (; abilities != NULL; abilities = abilities->next) {
            sfRectangleShape_setPosition(abilities->rectangle, (sfVector2f)
            {sfRectangleShape_getPosition(abilities->rectangle).x + 50,
            sfRectangleShape_getPosition(abilities->rectangle).y});
            sfSprite_setPosition(abilities->upgrade, (sfVector2f)
            {sfSprite_getPosition(abilities->upgrade).x + 50,
            sfSprite_getPosition(abilities->upgrade).y});
            sfSprite_setPosition(abilities->under, (sfVector2f)
            {sfSprite_getPosition(abilities->under).x + 50,
            sfSprite_getPosition(abilities->under).y});
            sfText_setPosition(abilities->name, (sfVector2f)
            {sfText_getPosition(abilities->name).x + 50,
            sfText_getPosition(abilities->name).y});
        } tmp->pos_xp.x += 50, sfText_setPosition(tmp->name, (sfVector2f){s_all
        ->s_info_text.pos_title.x, s_all->s_info_text.pos_title.y - 20});
        sfRectangleShape_setPosition(tmp->xp_bar, tmp->pos_xp);
        sfRectangleShape_setPosition(tmp->under, tmp->pos_xp);
    }
}