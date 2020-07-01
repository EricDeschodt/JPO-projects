/*
** EPITECH PROJECT, 2020
** utils
** File description:
** pnj
*/

#include "../../include/include.h"

pnjs *init_bubble(pnjs *pnj)
{
    pnj->d = 0;
    pnj->clock = sfClock_create();
    pnj->text_bubble = sfTexture_createFromFile("assets/bubble.png", NULL);
    pnj->sprit_bubble = sfSprite_create();
    sfSprite_setTexture(pnj->sprit_bubble, pnj->text_bubble, 0);
    sfSprite_setPosition(pnj->sprit_bubble,
    (sfVector2f){pnj->posi->x - 100, pnj->posi->y - 100});
    pnj->text_struct = sfText_create();
    pnj->font = sfFont_createFromFile("assets/fonts.ttf");
    sfText_setFont(pnj->text_struct, pnj->font);
    sfText_setPosition(pnj->text_struct, (sfVector2f){pnj->posi->x - 90,
    pnj->posi->y - 90});
    sfText_setColor(pnj->text_struct, sfWhite);
    sfText_setCharacterSize(pnj->text_struct, 50);
    sfText_setLineSpacing(pnj->text_struct, 0.5);
    return (pnj);
}

void print_pnj2(sfRenderWindow *window, pnjs *pnj, players *player)
{
    if (pnj->discus[pnj->d] == NULL &&
    sfClock_getElapsedTime(pnj->clock).microseconds > 3000000)
        pnj->state = 2;
    if (pnj->state == 0 || pnj->stay == 1) {
        sfSprite_setPosition(pnj->sprit, (sfVector2f)
        {pnj->posi->x - player->pos_x, pnj->posi->y - player->pos_y});
        sfRenderWindow_drawSprite(window, pnj->sprit, NULL);
    }
}

void print_pnj(sfRenderWindow *window, pnjs *pnj, players *player)
{
    print_pnj2(window, pnj, player);
    if (pnj->state == 1) {
        if (sfClock_getElapsedTime(pnj->clock).microseconds > 3000000) {
            sfText_setString(pnj->text_struct, pnj->discus[pnj->d]);
            pnj->d++;
            sfClock_restart(pnj->clock);
        }
        sfSprite_setPosition(pnj->sprit, (sfVector2f)
        {pnj->posi->x - player->pos_x, pnj->posi->y - player->pos_y});
        sfRenderWindow_drawSprite(window, pnj->sprit, NULL);
        sfSprite_setPosition(pnj->sprit_bubble, (sfVector2f)
        {pnj->posi->x - 100 - player->pos_x, pnj->posi->y - 100 -
        player->pos_y});
        sfRenderWindow_drawSprite(window, pnj->sprit_bubble, NULL);
        sfText_setPosition(pnj->text_struct, (sfVector2f)
        {pnj->posi->x - 90 - player->pos_x, pnj->posi->y - 100 -
        player->pos_y});
        sfRenderWindow_drawText(window, pnj->text_struct, NULL);
    }
}

void init_pnj2(players *player)
{
    player->pnj[11] = pnj_mineur_2();
    player->pnj[12] = pnj_two_lave();
    player->pnj[13] = pnj_easter_egg2();
    player->pnj[14] = pnj_two_lave2();
    player->pnj[15] = pnj_ange_1();
    player->pnj[16] = pnj_ange_2();
    player->pnj[17] = pnj_ange_3();
    player->pnj[18] = pnj_ange_4();
    player->pnj[19] = pnj_ange_5();
    player->pnj[20] = pnj_ange_6();
    player->pnj[21] = pnj_ange_7();
    player->pnj[22] = pnj_ange_8();
    player->pnj[23] = pnj_easter_egg_fin1();
    player->pnj[24] = pnj_easter_egg_fin2();
    player->pnj[25] = NULL;
}

void init_pnj(players *player)
{
    player->pnj = malloc(sizeof(pnjs *) * 26);
    player->pnj[0] = pnj_merlin();
    player->pnj[1] = pnj_spawn1();
    player->pnj[2] = pnj_spawn2();
    player->pnj[3] = pnj_spawn3();
    player->pnj[4] = pnj_spawn4();
    player->pnj[5] = pnj_cave();
    player->pnj[6] = pnj_monster_cave();
    player->pnj[7] = pnj_easter_egg();
    player->pnj[8] = pnj_champ_1();
    player->pnj[9] = pnj_champ_2();
    player->pnj[10] = pnj_mineur();
    init_pnj2(player);
}
