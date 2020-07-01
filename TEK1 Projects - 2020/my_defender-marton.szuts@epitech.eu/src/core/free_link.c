/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** free_link
*/

#include "defender.h"
#include "utils.h"

tuto_t *free_mobs(tuto_t *head)
{
    tuto_t *temp = NULL;
    while (head != NULL) {
        temp = head->next;
        sfSprite_destroy(head->sprite);
        if (head->snow != NULL) {
            sfSprite_destroy(head->snow);
            sfTexture_destroy(head->snow_text);
            sfShader_destroy(head->shader);
            sfCircleShape_destroy(head->light);
            sfClock_destroy(head->clock2);
            sfRectangleShape_destroy(head->life_bar);
        }
        sfClock_destroy(head->clock);
        free(head);
        head = temp;
    } return (NULL);
}

support_t *free_support(support_t *head)
{
    support_t *temp = NULL;
    while (head != NULL) {
        temp = head->next;
        sfSprite_destroy(head->sprite);
        sfTexture_destroy(head->texture);
        if (head->type == 'S') {
            sfTexture_destroy(head->texture_base);
            sfSprite_destroy(head->sprite_base);
        }
        free(head);
        head = temp;
    } return (NULL);
}

turret_t *free_turret(turret_t *head)
{
    turret_t *temp = NULL;
    while (head != NULL) {
        temp = head->next;
        sfSprite_destroy(head->sprite), sfSprite_destroy(head->sprite_c);
        sfTexture_destroy(head->texture);
        sfSprite_destroy(head->bullet), sfTexture_destroy(head->text_bullet);
        sfTexture_destroy(head->texture_c), clear_list_target(head->target);
        sfText_destroy(head->dmg_txt), sfText_destroy(head->rof_txt);
        sfText_destroy(head->range_txt), sfText_destroy(head->sell_txt);
        sfText_destroy(head->upg_price_txt), sfText_destroy(head->r_speed_txt);
        free(head);
        head = temp;
    } return (NULL);
}