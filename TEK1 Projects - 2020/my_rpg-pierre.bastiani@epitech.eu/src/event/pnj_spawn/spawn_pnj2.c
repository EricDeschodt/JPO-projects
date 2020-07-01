/*
** EPITECH PROJECT, 2020
** utils
** File description:
** pnj
*/

#include "include.h"

pnjs *pnj_cave(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 0, pnj->state = 0;
    pnj->segment = 2;
    init_pnj_sprite(pnj, "assets/pnj/cave.png", convert_pos(8000, 4100));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.5, 1.5});
    int nbsentences = 0;
    char *discus[] = {"Prouve ta valeur en combattant\n le monstre",
    "Si tu es digne de confiance\napres ton combat",
    "Tu te dirigera de l'autre\ncote  du chemin",
    "Pour prouver ta bravoure" ,NULL};
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

pnjs *pnj_monster_cave(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 0;
    pnj->state = 0;
    pnj->segment = 3;
    init_pnj_sprite(pnj, "assets/pnj/boss_one.png", convert_pos(10100, 4150));
    sfSprite_setScale(pnj->sprit, (sfVector2f){2, 2});
    int nbsentences = 0;
    char *discus[] = {"PREAPRE TOI !",NULL};
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

pnjs *pnj_easter_egg(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 2;
    init_pnj_sprite(pnj, "assets/pnj/garde.png", convert_pos(5005, 4650));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"Tu n'es pas encore pret !",
    "Seulement l'elus le sera !",NULL};
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

pnjs *pnj_champ_2(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 5;
    init_pnj_sprite(pnj, "assets/pnj/villagois.png", convert_pos(4900, 2900));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"L'elus serait donc arrive..",
    "Trouve la cle pour avoir\nreponse a tes questions.",NULL};
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

pnjs *pnj_champ_1(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 1;
    init_pnj_sprite(pnj, "assets/pnj/villagois.png", convert_pos(4900, 2900));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"Un chemin serais cachee dans\n cette foret.. ", NULL};
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