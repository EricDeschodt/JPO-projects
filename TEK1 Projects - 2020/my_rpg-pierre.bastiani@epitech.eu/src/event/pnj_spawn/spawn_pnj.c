/*
** EPITECH PROJECT, 2020
** utils
** File description:
** pnj
*/

#include "include.h"

pnjs *pnj_spawn1(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 0;
    init_pnj_sprite(pnj, "assets/pnj/villagois.png", convert_pos(6000, 3950));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"L'elus est t'il enfin arrive ?\n", NULL};
    for (; discus[nbsentences] != NULL; nbsentences++);
    pnj->discus = malloc(sizeof(char *) * (nbsentences + 1));
    for (int i = 0, o; discus[i] != NULL; i++) {
        pnj->discus[i] = malloc(sizeof(char) * (my_strlen(discus[i]) + 1));
        for (o = 0; discus[i][o] != '\0'; o++)
            pnj->discus[i][o] = discus[i][o];
        pnj->discus[i][o] = '\0';
    }
    pnj->discus[nbsentences] = NULL;
    return (init_bubble(pnj));
}

pnjs *pnj_spawn2(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 0;
    init_pnj_sprite(pnj, "assets/pnj/villagoise.png", convert_pos(6500, 4300));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"D'ou vient t'il ..?\n", NULL};
    for (; discus[nbsentences] != NULL; nbsentences++);
    pnj->discus = malloc(sizeof(char *) * (nbsentences + 1));
    for (int i = 0, o; discus[i] != NULL; i++) {
        pnj->discus[i] = malloc(sizeof(char) * (my_strlen(discus[i]) + 1));
        for (o = 0; discus[i][o] != '\0'; o++)
            pnj->discus[i][o] = discus[i][o];
        pnj->discus[i][o] = '\0';
    }
    pnj->discus[nbsentences] = NULL;
    return (init_bubble(pnj));
}

pnjs *pnj_spawn3(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 0;
    pnj->state = 0;
    pnj->segment = 0;
    init_pnj_sprite(pnj, "assets/pnj/ninja.png", convert_pos(6450, 3500));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"Damsweb ne va pas etre\ncontent de ta venu ..\n", NULL};
    for (; discus[nbsentences] != NULL; nbsentences++);
    pnj->discus = malloc(sizeof(char *) * (nbsentences + 1));
    for (int i = 0, o; discus[i] != NULL; i++) {
        pnj->discus[i] = malloc(sizeof(char) * (my_strlen(discus[i]) + 1));
        for (o = 0; discus[i][o] != '\0'; o++)
            pnj->discus[i][o] = discus[i][o];
        pnj->discus[i][o] = '\0';
    }
    pnj->discus[nbsentences] = NULL;
    return (init_bubble(pnj));
}

pnjs *pnj_spawn4(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 0;
    pnj->state = 0;
    pnj->segment = 0;
    init_pnj_sprite(pnj, "assets/pnj/viking.png", convert_pos(8000, 2700));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"On raconte certaine histoire sur\nce chemin..\n",
    "Personne n'y reviens si\n se n'es pas l'elus...", NULL};
    for (; discus[nbsentences] != NULL; nbsentences++);
    pnj->discus = malloc(sizeof(char *) * (nbsentences + 1));
    for (int i = 0, o; discus[i] != NULL; i++) {
        pnj->discus[i] = malloc(sizeof(char) * (my_strlen(discus[i]) + 1));
        for (o = 0; discus[i][o] != '\0'; o++)
            pnj->discus[i][o] = discus[i][o];
        pnj->discus[i][o] = '\0';
    }
    pnj->discus[nbsentences] = NULL;
    return (init_bubble(pnj));
}

pnjs *pnj_merlin(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 0, pnj->state = 0, pnj->segment = 0;
    init_pnj_sprite(pnj, "assets/pnj/merlin.png", convert_pos(6450, 3100));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.35, 1.35});
    int nbsentences = 0;
    char *discus[] = {"Chere aventurier,\n",
    "si vous voulez connaitre votre\n passe",
    "vous devrez passer plusieur\n epreuves", "pour retrouver la memoire.",
    "Continuer votre chemin\nen prenant la 1er a droite.", NULL};
    for (; discus[nbsentences] != NULL; nbsentences++);
    pnj->discus = malloc(sizeof(char *) * (nbsentences + 1));
    for (int i = 0, o; discus[i] != NULL; i++) {
        pnj->discus[i] = malloc(sizeof(char) * (my_strlen(discus[i]) + 1));
        for (o = 0; discus[i][o] != '\0'; o++)
            pnj->discus[i][o] = discus[i][o];
        pnj->discus[i][o] = '\0';
    }
    pnj->discus[nbsentences] = NULL;
    return (init_bubble(pnj));
}