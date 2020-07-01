/*
** EPITECH PROJECT, 2020
** utils
** File description:
** nb_util
*/

#include "../include/include.h"

void print_nb_util(sfRenderWindow *window, sfText *text, char *str)
{
    sfText_setString(text, str);
    sfRenderWindow_drawText(window, text, 0);
}

void print_util(sfRenderWindow *window, mobs *mob, players *player)
{
    char *kick = str_add(int_to_char(player->kick->cur), "/",
    int_to_char(player->kick->max));
    char *punch = str_add(int_to_char(player->punch->cur), "/",
    int_to_char(player->punch->max));
    char *headbut = str_add(int_to_char(player->headbut->cur), "/",
    int_to_char(player->headbut->max));
    char *strangle = str_add(int_to_char(player->strangle->cur), "/",
    int_to_char(player->strangle->max));
    if (player->combat == 2 || player->combat == 3 || player->combat == 4) {
        print_nb_util(window, mob->nb_kick, kick);
        print_nb_util(window, mob->nb_punch, punch);
    }
    if (player->combat == 3 || player->combat == 4)
        print_nb_util(window, mob->nb_head, headbut);
    if (player->combat == 4)
        print_nb_util(window, mob->nb_strangle, strangle);
}

void init_util_text(mobs *mob)
{
    sfFont *font = sfFont_createFromFile("assets/fonts.ttf");
    mob->nb_head = sfText_create();
    sfText_setFont(mob->nb_head, font);
    sfText_setPosition(mob->nb_head, (sfVector2f){1420, 890});
    mob->nb_punch = sfText_create();
    sfText_setFont(mob->nb_punch, font);
    sfText_setPosition(mob->nb_punch, (sfVector2f){1420, 730});
    mob->nb_kick = sfText_create();
    sfText_setFont(mob->nb_kick, font);
    sfText_setPosition(mob->nb_kick, (sfVector2f){1420, 810});
    mob->nb_strangle = sfText_create();
    sfText_setFont(mob->nb_strangle, font);
    sfText_setPosition(mob->nb_strangle, (sfVector2f){1420, 949});
}

void init_nb_util(players *player)
{
    player->headbut = malloc(sizeof(nb_util));
    player->headbut->max = 5;
    player->headbut->cur = player->headbut->max;
    player->kick = malloc(sizeof(nb_util));
    player->kick->max = 5;
    player->kick->cur = player->kick->max;
    player->strangle = malloc(sizeof(nb_util));
    player->strangle->max = 5;
    player->strangle->cur = player->strangle->max;
    player->punch = malloc(sizeof(nb_util));
    player->punch->max = 5;
    player->punch->cur = player->punch->max;
}