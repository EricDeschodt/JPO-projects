/*
** EPITECH PROJECT, 2020
** utils
** File description:
** pnj
*/

#include "include.h"

pnjs *pnj_ange_1(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 8;
    init_pnj_sprite(pnj, "assets/pnj/ange_1.png", convert_pos(10050, 1600));
    sfSprite_setScale(pnj->sprit, (sfVector2f){2.5, 2.5});
    int nbsentences = 0;
    char *discus[] = {"Bonjour Hestol..\nTes souvenir on ete vole..", NULL};
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

pnjs *pnj_ange_2(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 8;
    init_pnj_sprite(pnj, "assets/pnj/ange_1.1.png", convert_pos(10500, 1500));
    sfSprite_setScale(pnj->sprit, (sfVector2f){2.5, 2.5});
    int nbsentences = 0;
    char *discus[] = {"Nous allons te raconter\n ton histoire..", NULL};
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

pnjs *pnj_ange_3(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 8;
    init_pnj_sprite(pnj, "assets/pnj/ange_1.png", convert_pos(10050, 1328));
    sfSprite_setScale(pnj->sprit, (sfVector2f){2.5, 2.5});
    int nbsentences = 0;
    char *discus[] = {"Ton pere etait autre fois",
    "le sauveur du jardin du Paon", NULL};
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

pnjs *pnj_ange_4(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 8;
    init_pnj_sprite(pnj, "assets/pnj/ange_1.1.png", convert_pos(10500, 1200));
    sfSprite_setScale(pnj->sprit, (sfVector2f){2.5, 2.5});
    int nbsentences = 0;
    char *discus[] = {"Il a su nous proteger jusqu'a l'arriver\n de .."
    ,"Damsweb..", NULL};
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

pnjs *pnj_ange_5(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 8;
    init_pnj_sprite(pnj, "assets/pnj/ange_1.png", convert_pos(10050, 1050));
    sfSprite_setScale(pnj->sprit, (sfVector2f){2.5, 2.5});
    int nbsentences = 0;
    char *discus[] = {"Ta force te viens de se jardin\n selui de ton pere ..",
    "Tu as ete\n l'elus pour battre Dasmweb", NULL};
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