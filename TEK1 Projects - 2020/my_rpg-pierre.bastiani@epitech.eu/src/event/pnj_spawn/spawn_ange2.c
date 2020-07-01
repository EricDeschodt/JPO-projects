/*
** EPITECH PROJECT, 2020
** utils
** File description:
** pnj
*/

#include "include.h"

pnjs *pnj_ange_6(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 8;
    init_pnj_sprite(pnj, "assets/pnj/ange_1.1.png", convert_pos(10500, 880));
    sfSprite_setScale(pnj->sprit, (sfVector2f){2.5, 2.5});
    int nbsentences = 0;
    char *discus[] = {"C'est a toi maintenant",
    "de reprendre ce flambeau", NULL};
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

pnjs *pnj_ange_7(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 8;
    init_pnj_sprite(pnj, "assets/pnj/ange_1.png", convert_pos(10050, 736));
    pnj->posi = convert_pos(10050, 736);
    sfSprite_setScale(pnj->sprit, (sfVector2f){2.5, 2.5});
    int nbsentences = 0;
    char *discus[] = {"Trouve ce puit que ton pere\n proteger tant.", NULL};
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

pnjs *pnj_ange_8(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 0;
    pnj->state = 0;
    pnj->segment = 8;
    init_pnj_sprite(pnj, "assets/pnj/merlin.png", convert_pos(10265, 500));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.35, 1.35});
    int nbsentences = 0;
    char *discus[] = {"Et deviant Roi de se jardin.", NULL};
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