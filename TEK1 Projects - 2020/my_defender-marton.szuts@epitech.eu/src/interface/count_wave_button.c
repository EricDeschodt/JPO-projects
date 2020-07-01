/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** count_wave_button
*/

#include "defender.h"
#include "utils.h"

void init_count_wave_button(all_t *s_all)
{
    char *new = malloc(sizeof(char) * 5);
    new[0] = '/', new[1] = '\0';
    my_strcat(new, strnbr(s_all->s_wave_c.nb_waves));
    s_all->s_wave_c.base = new;
    s_all->s_wave_c.sprite = sfSprite_create();
    s_all->s_wave_c.text = sfText_create();
    s_all->s_wave_c.texture =
    sfTexture_createFromFile("sprites/buttons/count_w2.png", NULL);
    sfSprite_setTexture(s_all->s_wave_c.sprite,
    s_all->s_wave_c.texture, sfTrue);
    sfText_setFont(s_all->s_wave_c.text, s_all->s_game.font);
    s_all->s_wave_c.strwave = strnbr(0);
    my_strcat(s_all->s_wave_c.strwave, new);
    sfText_setString(s_all->s_wave_c.text, s_all->s_wave_c.strwave);
    sfSprite_setScale(s_all->s_wave_c.sprite, (sfVector2f){0.75, 0.75});
    sfSprite_setPosition(s_all->s_wave_c.sprite, (sfVector2f){160, 23});
    sfText_setPosition(s_all->s_wave_c.text, (sfVector2f){221, 30});
    s_all->s_wave_c.min = 0, s_all->s_wave_c.strwave = NULL;
}

void display_count_wave_button(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_wave_c.sprite, NULL);
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_wave_c.text, NULL);
}