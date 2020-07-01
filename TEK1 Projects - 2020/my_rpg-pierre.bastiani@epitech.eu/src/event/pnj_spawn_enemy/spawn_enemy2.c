/*
** EPITECH PROJECT, 2020
** utils
** File description:
** mob
*/

#include "include.h"

mobs *mob_three_lave(void)
{
    mobs *mob = malloc(sizeof(mobs));
    mob->state = mob->segment = 0;
    mob->life_max_enne = mob->life_ennemi = 10;
    init_mob_sprite(mob, "assets/pnj/boss2.png", convert_pos(7525, 1500));
    sfSprite_setScale(mob->sprit, (sfVector2f){0.5, 0.5});
    mob->sacha_f = sprite_creator("assets/s_player/right1.png");
    sfSprite_setScale(mob->sacha_f, (sfVector2f){10, 10});
    mob->vect_sacha_f = (sfVector2f){250, 600};
    sfSprite_setPosition(mob->sacha_f, mob->vect_sacha_f);
    mob->ennemi = sprite_creator("assets/pnj/boss2.png");
    sfSprite_setScale(mob->ennemi, (sfVector2f){1, 1});
    mob->vect_ennemi = (sfVector2f){1002, 240};
    sfSprite_setPosition(mob->ennemi, mob->vect_ennemi);
    mob->attack =
    sprite_creator("assets/assets_fight/attack/background_cave_lava.png");
    init_fight(mob);
    mob->recompense = 50;
    sfText_setString(mob->txt_win,
    "vous avez gagner 50xp et vaincue le terrible Alexicar, disiple de Damswe");
    return (mob);
}

mobs *mob_four_lave(void)
{
    mobs *mob = malloc(sizeof(mobs));
    mob->state = mob->segment = 0;
    mob->life_max_enne = mob->life_ennemi = 10;
    init_mob_sprite(mob, "assets/pnj/boss3.png", convert_pos(4950, 1500));
    sfSprite_setScale(mob->sprit, (sfVector2f){1, 1});
    mob->sacha_f = sprite_creator("assets/s_player/right1.png");
    sfSprite_setScale(mob->sacha_f, (sfVector2f){10, 10});
    mob->vect_sacha_f = (sfVector2f){250, 600};
    sfSprite_setPosition(mob->sacha_f, mob->vect_sacha_f);
    mob->ennemi = sprite_creator("assets/pnj/boss3.2.png");
    sfSprite_setScale(mob->ennemi, (sfVector2f){1.15, 1.15});
    mob->vect_ennemi = (sfVector2f){1002, 240};
    sfSprite_setPosition(mob->ennemi, mob->vect_ennemi);
    mob->attack =
    sprite_creator("assets/assets_fight/attack/background_cave_lava.png");
    init_fight(mob);
    mob->recompense = 50;
    sfText_setString(mob->txt_win,
    "vous avez gagner 50xp et vaincue le terrible Ericar, disiple de Damsweb");
    return (mob);
}

mobs *mob_boss_final(void)
{
    mobs *mob = malloc(sizeof(mobs));
    mob->state = 0;
    mob->segment = 8;
    mob->life_max_enne = mob->life_ennemi = 10;
    init_mob_sprite(mob, "assets/pnj/boss_final.png", convert_pos(6250, 650));
    mob->sacha_f = sprite_creator("assets/s_player/right1.png");
    sfSprite_setScale(mob->sacha_f, (sfVector2f){10, 10});
    mob->vect_sacha_f = (sfVector2f){250, 600};
    sfSprite_setPosition(mob->sacha_f, mob->vect_sacha_f);
    mob->ennemi = sprite_creator("assets/pnj/boss_final.png");
    sfSprite_setScale(mob->ennemi, (sfVector2f){1, 1});
    mob->vect_ennemi = (sfVector2f){1002, 240};
    sfSprite_setPosition(mob->ennemi, mob->vect_ennemi);
    mob->attack =
    sprite_creator("assets/assets_fight/attack/background_cave_lava.png");
    init_fight(mob);
    mob->recompense = 100;
    sfText_setString(mob->txt_win,
    "vous avez gagner 100xp en terrasant le terrible Big Dams");
    return (mob);
}