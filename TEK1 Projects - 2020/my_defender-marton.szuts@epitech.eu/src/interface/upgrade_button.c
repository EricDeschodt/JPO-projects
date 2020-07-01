/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** upgrade_button
*/

#include "defender.h"
#include "utils.h"

void init_upgrade_button(all_t *s_all)
{
    s_all->s_upgrade.pos = (sfVector2f){1930, 830};
    s_all->s_upgrade.sprite = sfSprite_create();
    s_all->s_upgrade.gold = sfSprite_create();
    s_all->s_upgrade.texture =
        sfTexture_createFromFile("sprites/buttons/upgrade1.png", NULL);
    s_all->s_upgrade.texture2 =
        sfTexture_createFromFile("sprites/buttons/upgrade2.png", NULL);
    s_all->s_upgrade.texture3 =
        sfTexture_createFromFile("sprites/buttons/upgrade3.png", NULL);
    s_all->s_upgrade.gold_txt =
        sfTexture_createFromFile("sprites/money.png", NULL);
    sfSprite_setTexture(s_all->s_upgrade.sprite,
        s_all->s_upgrade.texture3, sfTrue);
    sfSprite_setTexture(s_all->s_upgrade.gold,
        s_all->s_upgrade.gold_txt, sfTrue);
    sfSprite_setPosition(s_all->s_upgrade.sprite,
        s_all->s_upgrade.pos);
    sfSprite_setPosition(s_all->s_upgrade.gold,
        (sfVector2f){s_all->s_upgrade.pos.x + 300, s_all->s_upgrade.pos.y});
}

void hitbox_upgrade_button(all_t *s_all)
{
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_upgrade.pos.x
        && mouse_pos.x <= s_all->s_upgrade.pos.x + 320)
        && (mouse_pos.y >= s_all->s_upgrade.pos.y
        && mouse_pos.y <= s_all->s_upgrade.pos.y + 63)
        && s_all->s_selected.tur != NULL) {
        if (s_all->s_player.money >= s_all->s_selected.tur->price)
            sfSprite_setTexture(s_all->s_upgrade.sprite,
                s_all->s_upgrade.texture2, sfTrue);
    }
}

void upgrade(turret_t *new, all_t *s_all)
{
    sfVector2f scale = sfSprite_getScale(new->zone);
    scale.x *= 1.1, scale.y *= 1.1;
    new->dmg *= 1.1, new->range *= 1.1, new->rate_fire /= 1.1;
    new->bullet_speed *= 1.1, new->r_speed *= 1.1;
    new->r_speed_str = strnbr_float(new->r_speed);
    new->rof_str = strnbr_float(1 / new->rate_fire);
    new->b_speed_str = strnbr_float(new->bullet_speed);
    new->range_str = strnbr(new->range);
    new->dmg_str = strnbr(new->dmg), new->strsell = strnbr(new->sell);
    sfSprite_setScale(new->zone, scale);
    sfText_setString(new->r_speed_txt, new->r_speed_str);
    sfText_setString(new->range_txt, new->range_str);
    sfText_setString(new->rof_txt, new->rof_str);
    sfText_setString(new->dmg_txt, new->dmg_str);
    sfText_setString(new->b_speed_txt, new->b_speed_str);
    sfText_setString(new->sell_txt, new->strsell);
    s_all->s_player.money -= new->upg_price; new->upg_price *= 2;
    free(new->strupg_price); new->strupg_price = strnbr(new->upg_price);
    upgrade2(new), sfText_setString(new->upg_price_txt, new->strupg_price);
    if (s_all->s_settings->sound == 1) sfSound_play(s_all->s_sounds.upgrade);
}

void release_upgrade_button(all_t *s_all)
{
    if (s_all->s_selected.tur != NULL
    && s_all->s_player.money >= s_all->s_selected.tur->price)
    sfSprite_setTexture(s_all->s_upgrade.sprite,
        s_all->s_upgrade.texture3, sfTrue);
    sfVector2i mouse_pos =
        sfMouse_getPositionRenderWindow(s_all->s_game.window);
    if ((mouse_pos.x >= s_all->s_upgrade.pos.x
    && mouse_pos.x <= s_all->s_upgrade.pos.x + 320)
    && (mouse_pos.y >= s_all->s_upgrade.pos.y && s_all->s_selected.tur != NULL
    && mouse_pos.y <= s_all->s_upgrade.pos.y + 63)
    && s_all->s_game.pause == 0 && s_all->s_game.scene == 1
    && s_all->s_player.money >= s_all->s_selected.tur->upg_price
    && s_all->s_selected.tur->counter < 3) {
        s_all->s_selected.tur->counter++;
        upgrade(s_all->s_selected.tur, s_all), free(s_all->s_player.strmoney);
        s_all->s_player.strmoney = strnbr(s_all->s_player.money);
        sfText_setString(s_all->s_player.txt_money, s_all->s_player.strmoney);
    } if (s_all->s_selected.tur != NULL &&
    s_all->s_selected.tur->counter == 3 && s_all->s_selected.tur->max != 1)
        max_upgrade(s_all, s_all->s_selected.tur);
}

void display_upgrade_button(all_t *s_all)
{
    if ((s_all->s_player.money < s_all->s_selected.tur->upg_price)
    || s_all->s_selected.tur->max == 1) {
        sfSprite_setTexture(s_all->s_upgrade.sprite,
            s_all->s_upgrade.texture, sfTrue);
        s_all->s_selected.tur->button = 1;
    } else if (s_all->s_player.money < s_all->s_selected.tur->price
    && s_all->s_selected.tur->button == 1) {
        sfSprite_setTexture(s_all->s_upgrade
        .sprite, s_all->s_upgrade.texture3, sfTrue);
        s_all->s_selected.tur->button = 0;
    } sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_upgrade.sprite, NULL);
    if (s_all->s_selected.tur->max != 1)
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_upgrade.gold, NULL);
}