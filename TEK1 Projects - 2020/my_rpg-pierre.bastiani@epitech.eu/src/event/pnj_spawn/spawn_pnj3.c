/*
** EPITECH PROJECT, 2020
** utils
** File description:
** pnj
*/

#include "include.h"

pnjs *pnj_two_lave2(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 0;
    pnj->state = 0;
    pnj->segment = 8;
    init_pnj_sprite(pnj, "assets/pnj/cave.png", convert_pos(6300, 1500));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"Grrrrr.. tu as eu les disciple",
    "Mais Damsweb\n aura raison de toi", NULL};
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

pnjs *pnj_two_lave(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 5;
    init_pnj_sprite(pnj, "assets/pnj/cave.png", convert_pos(6300, 1500));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"Combat les disciples de Damsweb\n",
    "a droite et gauche de nous", NULL};
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

pnjs *pnj_easter_egg2(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1, pnj->state = 0, pnj->segment = 0;
    init_pnj_sprite(pnj, "assets/pnj/villagoise.png", convert_pos(1400, 4650));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"Je t'attendais Hestol..",
    "Tu as su prouver ta force et\n ton bravoure",
    "La fontaine du Jardin du Paon\n t'apportera l'immortalite",
    "Sa sera a toi maintenant\n de proteger cette valee", NULL};
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

pnjs *pnj_easter_egg_fin1(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 19;
    init_pnj_sprite(pnj, "assets/pnj/garde.png", convert_pos(5005, 4650));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"Cette endroit est interdit a ce",
    "qui on visiter le monde des \nmorts", NULL};
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

pnjs *pnj_easter_egg_fin2(void)
{
    pnjs *pnj = malloc(sizeof(pnjs));
    pnj->stay = 1;
    pnj->state = 0;
    pnj->segment = 20;
    init_pnj_sprite(pnj, "assets/pnj/garde.png", convert_pos(5005, 4650));
    sfSprite_setScale(pnj->sprit, (sfVector2f){1.25, 1.25});
    int nbsentences = 0;
    char *discus[] = {"Bravo tu as terraser Dasmweb,\nEstelle t'attend",NULL};
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