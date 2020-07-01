/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** turret_area
*/

#include "defender.h"
#include "utils.h"

void load_turret(turret_t *new, sfVector2f pos)
{
    new->text_bullet = sfTexture_createFromFile("sprites/bullet1.png", NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTexture(new->sprite_c, new->texture_c, sfTrue);
    sfSprite_setTexture(new->bullet, new->text_bullet, sfTrue);
    new->pos_c = (sfVector2f){pos.x + 60, pos.y + 60};
    new->pos_bullet = (sfVector2f){pos.x + 60, pos.y + 60};
    sfSprite_setPosition(new->sprite, pos), new->shoot = 0, new->hit = 0;
    sfSprite_setOrigin(new->sprite_c, (sfVector2f){60, 60});
    new->pos_c2 = (sfVector2f){pos.x + 120, pos.y + 60};
    sfSprite_setPosition(new->sprite_c, (sfVector2f){pos.x + 60, pos.y + 60});
    sfSprite_setOrigin(new->bullet, (sfVector2f){17, 17});
    sfSprite_setScale(new->bullet, (sfVector2f){0.3, 0.3});
    sfSprite_setPosition(new->bullet, new->pos_c);
    new->button = 0;
}

void get_turret_texts(turret_t *new, all_t *s_all)
{
    new->r_speed_txt = sfText_create(), new->range_txt = sfText_create();
    new->rof_txt = sfText_create(), new->dmg_txt = sfText_create();
    new->b_speed_txt = sfText_create(), new->sell_txt = sfText_create();
    sfText_setFont(new->r_speed_txt, s_all->s_game.font);
    sfText_setFont(new->range_txt, s_all->s_game.font);
    sfText_setFont(new->rof_txt, s_all->s_game.font);
    sfText_setFont(new->dmg_txt, s_all->s_game.font);
    sfText_setFont(new->b_speed_txt, s_all->s_game.font);
    sfText_setFont(new->sell_txt, s_all->s_game.font);
    new->r_speed_str = strnbr_float(new->r_speed), new->counter = 0;
    new->rof_str = strnbr_float(1 / new->rate_fire);
    new->b_speed_str = strnbr_float(new->bullet_speed);
    new->range_str = strnbr(new->range);
    new->dmg_str = strnbr(new->dmg), new->strsell = strnbr(new->sell);
    sfText_setString(new->r_speed_txt, new->r_speed_str);
    sfText_setString(new->range_txt, new->range_str);
    sfText_setString(new->rof_txt, new->rof_str);
    sfText_setString(new->dmg_txt, new->dmg_str);
    sfText_setString(new->b_speed_txt, new->b_speed_str);
    sfText_setString(new->sell_txt, new->strsell);
}

void get_turret_zone(all_t *s_all, t_select_t *temp)
{
    s_all->s_turret->zone = sfSprite_create();
    s_all->s_turret->zone_txt =
    sfTexture_createFromFile("sprites/zone_b.png", NULL);
    sfSprite_setTexture(s_all->s_turret->zone,
    s_all->s_turret->zone_txt, sfTrue);
    sfSprite_setScale(s_all->s_turret->zone, temp->scale);
    sfSprite_setPosition(s_all->s_turret->zone, (sfVector2f)
    {s_all->s_selected.pos2.x + 60, s_all->s_selected.pos2.y + 60});
    sfSprite_setOrigin(s_all->s_turret->zone, (sfVector2f){255, 255});
}

void get_turret_type(turret_t *new, all_t *s_all)
{
    if (new->type == 1) {
        new->r_speed = 2.5, new->rate_fire = 0.5, new->bullet_speed = 8.0;
        new->dmg = 34, new->range = 260, new->sell = 48, new->price = 48/2;
        new->text_bullet = sfTexture_createFromFile("sprites/bullet3.png",
        NULL);
    } if (new->type == 2) {
        new->r_speed = 1.8, new->rate_fire = 3.0, new->bullet_speed = 25.0;
        new->dmg = 150, new->range = 560, new->sell = 80, new->price = 80/2;
        new->text_bullet = sfTexture_createFromFile("sprites/bullet2.png",
        NULL);
    } if (new->type == 3) {
        new->range = 200, new->rate_fire = 2.0, new->bullet_speed = 8.0, new->
        dmg = 80, new->sell = 60, new->price = 60/2, new->r_speed = 1.5, new->
        text_bullet = sfTexture_createFromFile("sprites/bullet1.png", NULL);
    } if (new->type == 4) {
        new->r_speed = 3, new->rate_fire = 1000, new->bullet_speed = 0;
        new->dmg = 0, new->range = 260, new->sell = 80, new->price = 80/2;
        sfSprite_setPosition(new->bullet, (sfVector2f){-100, -100});
    } get_turret_texts(new, s_all), set_txt_sizes(new), init_upgrade_turret(
    s_all, new), sfSprite_setTexture(new->bullet, new->text_bullet, sfTrue);
}

void move_mob(tuto_t *mob, sfVector2f scl, all_t *s_all)
{
    if (s_all->s_game.pause == 1) {
        sfClock_restart(mob->clock2);
        return;
    }
    if (mob->direction == 0 && (scl.x >= 1 && scl.y >= 1)) {
        mob->pos.x -= 72 * mob->seconds2;
        mob->move -= 72 * mob->seconds2;
        if (mob->move <= 0) mob->direction = 1;
    }
    if (mob->direction == 1 && (scl.x >= 1 && scl.y >= 1)) {
        mob->pos.x += 72 * mob->seconds2;
        mob->move += 72 * mob->seconds2;
        if (mob->move >= 20) mob->direction = 0;
    }
    sfClock_restart(mob->clock2);
}