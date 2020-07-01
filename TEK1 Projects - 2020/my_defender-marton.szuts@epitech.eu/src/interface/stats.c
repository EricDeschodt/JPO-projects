/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** stats
*/

#include "defender.h"
#include "utils.h"

turret_t *get_turret(all_t *s_all)
{
    turret_t *temp = s_all->s_turret;
    while (temp != NULL) {
        if ((temp->pos.x == s_all->s_selected.pos2.x) &&
        temp->pos.y == s_all->s_selected.pos2.y)
            return (temp);
        temp = temp->next;
    }
    return (NULL);
}

void display_turret_stats2(all_t *s_all)
{
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_selected.tur->dmg_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_selected.tur->rof_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_selected.tur->sell_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_selected.tur->upg_price_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_selected.tur->lvl_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_selected.tur->xp_txt, NULL);
}

void display_abilities(all_t *s_all, abilities_t *abilities)
{
    if (s_all->s_texture.seconds >= 0.03
    && s_all->s_texture.bounce == 0 && s_all->s_game.pause == 0) {
        s_all->s_texture.alpha += 5;
        sfClock_restart(s_all->s_texture.clock);
    } else if (s_all->s_texture.seconds >= 0.03
    && s_all->s_texture.bounce == 1 && s_all->s_game.pause == 0) {
        s_all->s_texture.alpha -= 5;
        sfClock_restart(s_all->s_texture.clock);
    } if (s_all->s_texture.alpha >= 150)
        s_all->s_texture.bounce = 1;
    else if (s_all->s_texture.alpha <= 0)
        s_all->s_texture.bounce = 0;
    if (abilities->bought == 0) sfRectangleShape_setFillColor(abilities->
        rectangle, (sfColor){213, 178, 64, s_all->s_texture.alpha});
    if (s_all->s_selected.tur->level == 4)
        sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        abilities->rectangle, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window, abilities->under, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window, abilities->upgrade, NULL);
    sfRenderWindow_drawText(s_all->s_game.window, abilities->name, NULL);
}

void display_turret_stats(all_t *s_all)
{
    if (s_all->s_selected.type == 'O' && s_all->s_selected.tur != NULL &&
    s_all->s_selected.tur->draw_stat == 1) {
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->range_txt, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->b_speed_txt, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_selected.tur->r_speed_txt, NULL);
        display_turret_stats2(s_all);
    } if (s_all->s_selected.type == 'O' && s_all->s_selected.tur != NULL) {
        abilities_t *abilities = s_all->s_selected.tur->abilities;
        for (; abilities != NULL; abilities = abilities->next) {
            display_abilities(s_all, abilities);
        }
    }
}

void set_txt_sizes(turret_t *new)
{
    sfText_setPosition(new->b_speed_txt, (sfVector2f){1600, 405});
    sfText_setPosition(new->range_txt, (sfVector2f){1600, 260});
    sfText_setPosition(new->rof_txt, (sfVector2f){1600, 329});
    sfText_setPosition(new->dmg_txt, (sfVector2f){1850, 260});
    sfText_setPosition(new->r_speed_txt, (sfVector2f){1850, 330});
    sfText_setPosition(new->sell_txt, (sfVector2f){1850, 935});
    sfText_setCharacterSize(new->rof_txt, 20);
    sfText_setCharacterSize(new->dmg_txt, 20);
    sfText_setCharacterSize(new->range_txt, 20);
    sfText_setCharacterSize(new->b_speed_txt, 20);
    sfText_setCharacterSize(new->r_speed_txt, 20);
}