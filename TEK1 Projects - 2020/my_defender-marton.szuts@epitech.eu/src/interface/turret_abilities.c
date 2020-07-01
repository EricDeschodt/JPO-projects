/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_abilities
*/

#include "defender.h"

void init_node_abilities(abilities_t *node, int nb)
{
    if (nb == 0) {
        sfRectangleShape_setPosition(node->rectangle, (sfVector2f){1430, 597});
        sfSprite_setPosition(node->upgrade, (sfVector2f){1435, 600});
        sfSprite_setPosition(node->under, (sfVector2f){1435, 600});
        sfText_setPosition(node->name, (sfVector2f){1505, 620});
    } if (nb == 1) {
        sfRectangleShape_setPosition(node->rectangle, (sfVector2f){1675, 597});
        sfSprite_setPosition(node->upgrade, (sfVector2f){1680, 600});
        sfSprite_setPosition(node->under, (sfVector2f){1680, 600});
        sfText_setPosition(node->name, (sfVector2f){1775, 620});
    } if (nb == 2) {
        sfRectangleShape_setPosition(node->rectangle, (sfVector2f){1430, 692});
        sfSprite_setPosition(node->upgrade, (sfVector2f){1435, 695});
        sfSprite_setPosition(node->under, (sfVector2f){1435, 695});
        sfText_setPosition(node->name, (sfVector2f){1505, 710});
    } if (nb == 3) {
        sfRectangleShape_setPosition(node->rectangle, (sfVector2f){1675, 692});
        sfSprite_setPosition(node->upgrade, (sfVector2f){1680, 695});
        sfSprite_setPosition(node->under, (sfVector2f){1680, 695});
        sfText_setPosition(node->name, (sfVector2f){1755, 710}); }
}

void init_turret1(abilities_t *node, int type, all_t *s_all, int nb)
{
    if (type == 1)
        sfSprite_setTexture(node->under, s_all->s_texture.square, sfTrue);
    if (type == 1 && nb == 0) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret1_dual, sfTrue);
        sfText_setString(node->name, "      Double gun\n  Atk speed x1.25");
    } if (type == 1 && nb == 1) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret1_large, sfTrue);
        sfText_setString(node->name, " Large caliber\nDamage x1.25");
    } if (type == 1 && nb == 2) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret1_foundation, sfTrue);
        sfText_setString(node->name, "     Foundation\nTracking speed x1.5");
    } if (type == 1 && nb == 3) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret1_value, sfTrue);
        sfText_setString(node->name, "      Jackpot!\nGive you 100 coins");
    }
}

void init_turret2(abilities_t *node, int type, all_t *s_all, int nb)
{
    if (type == 2)
        sfSprite_setTexture(node->under, s_all->s_texture.triangle, sfTrue);
    if (type == 2 && nb == 0) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret2_speed, sfTrue);
        sfText_setString(node->name, "    V8 engine\nTracking speed x1.5");
    } if (type == 2 && nb == 1) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret2_heavy, sfTrue);
        sfText_setString(node->name, "Heavy weapons\nDamage x1.25");
    } if (type == 2 && nb == 2) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret2_long, sfTrue);
        sfText_setString(node->name, "    Long barrel\n   Range x1.25");
    } if (type == 2 && nb == 3) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret2_killshot, sfTrue);
        sfText_setString(node->name, "      Killshot\n Atk speed x1.25");
    }
}

void init_turret3(abilities_t *node, int type, all_t *s_all, int nb)
{
    if (type == 3)
        sfSprite_setTexture(node->under, s_all->s_texture.hexa, sfTrue);
    if (type == 3 && nb == 0) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret3_shrapnel, sfTrue);
        sfText_setString(node->name, "     Shrapnel\n  Damage x1.25");
    } if (type == 3 && nb == 1) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret3_long, sfTrue);
        sfText_setString(node->name, "     BBC\nRange x1.25");
    } if (type == 3 && nb == 2) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret3_foundation, sfTrue);
        sfText_setString(node->name, "     Foundation\nTracking speed x1.5");
    } if (type == 3 && nb == 3) {
        sfSprite_setTexture(node->upgrade,
        s_all->s_texture.turret3_speed, sfTrue);
        sfText_setString(node->name, "    Berzerk mod\n  Atk speed x1.5");
    }
}

abilities_t *push_front_abilities(all_t *s_all, abilities_t *head, int type)
{
    static int nb = 0;
    abilities_t *node = malloc(sizeof(abilities_t));
    node->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(node->rectangle, (sfVector2f){237, 88});
    sfRectangleShape_setFillColor(node->rectangle,
        (sfColor){213, 178, 64, 150});
    node->upgrade = sfSprite_create(), node->under = sfSprite_create();
    node->bought = 0, node->id = nb;
    node->name = sfText_create();
    sfText_setColor(node->name, (sfColor){200, 200, 200, 200});
    sfText_setFont(node->name, s_all->s_game.font);
    sfText_setCharacterSize(node->name, 17);
    init_turret1(node, type, s_all, nb), init_turret2(node, type, s_all, nb);
    init_turret3(node, type, s_all, nb), init_turret4(node, type, s_all, nb);
    sfSprite_setColor(node->under, (sfColor){255, 255, 255, 150});
    init_node_abilities(node, nb);
    node->next = head;
    if (nb == 3) nb = 0;
    else nb++;
    return (node);
}