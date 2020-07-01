/*
** EPITECH PROJECT, 2019
** CSFML
** File description:
** main_init
*/

#include "my.h"

void main_init2(all_t *all)
{
    int i = 0;
    for (; i != 3; i++)
        all->write.score[i] = '0';
    all->write.score[i] = '\0';
    sfText_setString(all->write.text6, all->write.score);
    sfText_setPosition(all->write.text6, all->pos.pos_score);
    sfSprite_setPosition(all->sprite2.perfect_s, all->pos.pos_perfect);
    all->write.top_score = open_read();
    sfText_setString(all->write.text1, all->write.top_score);
}

void main_init(all_t *all)
{
    all->my_int.x1 = 20;
    all->my_int.round_count = 1;
    all->my_int.score_int = 0;
    all->write.round_count_text = malloc(sizeof(char) * 5);
    all->write.score = malloc(sizeof(char) * 10);
    sfSprite_setPosition(all->sprite.dog, all->pos.pos_dog);
    sfSprite_setTextureRect(all->sprite.dog, all->rect.dog);
    sfText_setPosition(all->write.text3, all->pos.pos_round_text);
    sfText_setPosition(all->write.text4, all->pos.pos_round_text2);
    all->write.round_count_text = my_put_nbr(all->my_int.round_count,
        all->write.round_count_text);
    sfSprite_setPosition(all->sprite2.overlay, all->pos.pos_overlay);
    sfSprite_setPosition(all->sprite2.overlay2, all->pos.pos_overlay);
    sfText_setString(all->write.text4, all->write.round_count_text);
    sfText_setString(all->write.text5, all->write.round_count_text);
    sfText_setPosition(all->write.text5, all->pos.pos_round_nb);
    sfSprite_setPosition(all->sprite2.ammo, all->pos.pos_ammo);
    main_init2(all);
}