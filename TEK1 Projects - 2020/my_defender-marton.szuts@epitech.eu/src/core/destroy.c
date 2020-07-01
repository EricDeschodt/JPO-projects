/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** destroy
*/

#include "defender.h"
#include "utils.h"

void destroy_regroup(all_t *s_all)
{
    destroy_music(s_all);
}

int mob_destroy_animation(tuto_t *s_tuto)
{
    s_tuto->scale.x -= (s_tuto->seconds + 0.04);
    s_tuto->scale.y -= (s_tuto->seconds + 0.04);
    sfSprite_setScale(s_tuto->sprite, s_tuto->scale);
    return (0);
}

tuto_t *free_node(tuto_t *s_tuto, tuto_t *prev, tuto_t *temp3, all_t *s_all)
{
    tuto_t *temp = s_tuto->next;
    if (temp == NULL) {
        if (s_tuto->scale.x > 0.1 && s_tuto->scale.y > 0.1)
            mob_destroy_animation(s_tuto);
        else {
            prev->next = s_tuto->next;
            sfClock_destroy(s_tuto->clock);
            sfSprite_destroy(s_tuto->sprite), free(s_tuto);
        } return (NULL);
    } if (s_tuto != temp3) {
        if (s_tuto->scale.x > 0.1 && s_tuto->scale.y > 0.1) {
            mob_destroy_animation(s_tuto);
            return (s_tuto->next);
        } else if (prev != NULL && s_tuto != NULL) {
            prev->next = s_tuto->next, sfSprite_destroy(s_tuto->sprite);
            sfClock_destroy(s_tuto->clock), free(s_tuto);
        } return (prev->next);
    } else return (destroy_mob_head(s_tuto, temp3, s_all));
}

void free_node2(all_t *s_all, tuto_t *temp, int id)
{
    if (temp->scale.x > 0.1 && temp->scale.y > 0.1) {
        mob_destroy_animation(temp);
        return;
    }
    else {
        sfSprite_destroy(temp->sprite);
        sfClock_destroy(temp->clock);
        free(temp);
        if (id == 1) s_all->s_wave_c.round = NULL;
        if (id == 2) s_all->s_wave_c.square = NULL;
        if (id == 3) s_all->s_wave_c.triangle = NULL;
    }
}

void check_destroy_ball(all_t *s_all, int id)
{
    tuto_t *temp2, *tmp3 = s_all->s_tuto, *temp = s_all->s_tuto;
    if (id == 1) temp = s_all->s_wave_c.round, tmp3 = s_all->s_wave_c.round;
    if (id == 2) temp = s_all->s_wave_c.square, tmp3 = s_all->s_wave_c.square;
    if (id == 3) {
        temp = s_all->s_wave_c.triangle, tmp3 = s_all->s_wave_c.triangle;
    } temp2 = tmp3;
    while (temp != NULL) {
        if (my_if(temp)) losing_life(s_all);
        if (temp->state == -1 && (linked_len(s_all, id) > 1) && temp != tmp3) {
            temp = destroy_part1(s_all, temp2, tmp3, temp);
            continue;
        } else if (temp->state == -1 && (linked_len(s_all, id) == 1)) {
            destroy_part2(s_all, id, temp);
            break;
        } if (temp->state == -1 && (linked_len(s_all, id) > 1)
        && temp == tmp3) {
            temp = destroy_part3(s_all, tmp3, temp);
            continue;
        } temp2 = temp, temp = temp->next;
    }
}