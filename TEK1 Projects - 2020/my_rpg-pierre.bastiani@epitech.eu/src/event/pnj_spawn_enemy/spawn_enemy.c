/*
** EPITECH PROJECT, 2020
** utils
** File description:
** mob
*/

#include "include.h"

mobs *mob_pioche(void)
{
    mobs *mob = malloc(sizeof(mobs));
    mob->state = 0;
    mob->segment = 2;
    mob->life_max_enne = mob->life_ennemi = 10;
    init_mob_sprite(mob, "assets/pnj/ninja.png", convert_pos(8750, 2700));
    mob->sacha_f = sprite_creator("assets/s_player/right1.png");
    sfSprite_setScale(mob->sacha_f, (sfVector2f){10, 10});
    mob->vect_sacha_f = (sfVector2f){250, 600};
    sfSprite_setPosition(mob->sacha_f, mob->vect_sacha_f);
    mob->ennemi = sprite_creator("assets/pnj/ninja.png");
    sfSprite_setScale(mob->ennemi, (sfVector2f){2, 2});
    mob->vect_ennemi = (sfVector2f){1002, 240};
    sfSprite_setPosition(mob->ennemi, mob->vect_ennemi);
    mob->attack = sprite_creator("assets/assets_fight/attack/attak.png");
    init_fight(mob);
    mob->recompense = 100;
    sfText_setString(mob->txt_win,
    "vous avez gagner 100xp et trouver la pioche du mineur !");
    return (mob);
}

mobs *mob_champ_1(void)
{
    mobs *mob = malloc(sizeof(mobs));
    mob->state = 0;
    mob->segment = 4;
    mob->life_max_enne = mob->life_ennemi = 10;
    init_mob_sprite(mob, "assets/pnj/ninja.png", convert_pos(4050, 3900));
    mob->sacha_f = sprite_creator("assets/s_player/right1.png");
    sfSprite_setScale(mob->sacha_f, (sfVector2f){10, 10});
    mob->vect_sacha_f = (sfVector2f){250, 600};
    sfSprite_setPosition(mob->sacha_f, mob->vect_sacha_f);
    mob->ennemi = sprite_creator("assets/pnj/ninja.png");
    sfSprite_setScale(mob->ennemi, (sfVector2f){2, 2});
    mob->vect_ennemi = (sfVector2f){1002, 240};
    sfSprite_setPosition(mob->ennemi, mob->vect_ennemi);
    mob->attack = sprite_creator("assets/assets_fight/attack/attak.png");
    init_fight(mob);
    mob->recompense = 50;
    sfText_setString(mob->txt_win,
    "vous avez gagner 50xp et battue une complice de Damsweb");
    return (mob);
}

mobs *mob_champ_2(void)
{
    mobs *mob = malloc(sizeof(mobs));
    mob->state = 0;
    mob->segment = 4;
    mob->life_max_enne = mob->life_ennemi = 10;
    init_mob_sprite(mob, "assets/pnj/ninja.png", convert_pos(3500, 3800));
    mob->sacha_f = sprite_creator("assets/s_player/right1.png");
    sfSprite_setScale(mob->sacha_f, (sfVector2f){10, 10});
    mob->vect_sacha_f = (sfVector2f){250, 600};
    sfSprite_setPosition(mob->sacha_f, mob->vect_sacha_f);
    mob->ennemi = sprite_creator("assets/pnj/ninja.png");
    sfSprite_setScale(mob->ennemi, (sfVector2f){2, 2});
    mob->vect_ennemi = (sfVector2f){1002, 240};
    sfSprite_setPosition(mob->ennemi, mob->vect_ennemi);
    mob->attack = sprite_creator("assets/assets_fight/attack/attak.png");
    init_fight(mob);
    mob->recompense = 50;
    sfText_setString(mob->txt_win,
    "vous avez gagner 50xp et trouver la clef vers Damsweb");
    return (mob);
}

mobs *mob_champ_3(void)
{
    mobs *mob = malloc(sizeof(mobs));
    mob->state = 0;
    mob->segment = 4;
    mob->life_max_enne = mob->life_ennemi = 10;
    init_mob_sprite(mob, "assets/pnj/ninja.png", convert_pos(3700, 3350));
    mob->sacha_f = sprite_creator("assets/s_player/right1.png");
    sfSprite_setScale(mob->sacha_f, (sfVector2f){10, 10});
    mob->vect_sacha_f = (sfVector2f){250, 600};
    sfSprite_setPosition(mob->sacha_f, mob->vect_sacha_f);
    mob->ennemi = sprite_creator("assets/pnj/ninja.png");
    sfSprite_setScale(mob->ennemi, (sfVector2f){2, 2});
    mob->vect_ennemi = (sfVector2f){1002, 240};
    sfSprite_setPosition(mob->ennemi, mob->vect_ennemi);
    mob->attack = sprite_creator("assets/assets_fight/attack/attak.png");
    init_fight(mob);
    mob->recompense = 50;
    sfText_setString(mob->txt_win,
    "vous avez gagner 50xp et battue une complice de Damsweb");
    return (mob);
}

mobs *mob_boss_one(void)
{
    mobs *mob = malloc(sizeof(mobs));
    mob->state = 0, mob->segment = 4;
    mob->life_max_enne = mob->life_ennemi = 10;
    init_mob_sprite(mob, "assets/pnj/boss_one.png", convert_pos(10100, 4150));
    sfSprite_setScale(mob->sprit, (sfVector2f){2, 2});
    mob->sacha_f = sprite_creator("assets/s_player/right1.png");
    sfSprite_setScale(mob->sacha_f, (sfVector2f){10, 10});
    mob->vect_sacha_f = (sfVector2f){250, 600};
    sfSprite_setPosition(mob->sacha_f, mob->vect_sacha_f);
    mob->ennemi = sprite_creator("assets/pnj/boss_one.png");
    sfSprite_setScale(mob->ennemi, (sfVector2f){1.5, 1.5});
    mob->vect_ennemi = (sfVector2f){1002, 240};
    sfSprite_setPosition(mob->ennemi, mob->vect_ennemi);
    mob->attack =
    sprite_creator("assets/assets_fight/attack/background_cave.png");
    init_fight(mob);
    mob->recompense = 50;
    sfText_setString(mob->txt_win,
    "vous avez gagner 50xp, une cate recupere vous a reveler un chemin");
    return (mob);
}