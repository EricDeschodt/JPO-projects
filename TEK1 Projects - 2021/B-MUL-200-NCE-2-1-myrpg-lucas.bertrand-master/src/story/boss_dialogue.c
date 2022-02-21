/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** boss_intro
*/
#include "../../include/my.h"
#include "../../include/struct.h"

char *boss_4(int i)
{
    char *text[6] = {"Tu arrives un peu plus tot que prevu...",
        "Tu connais notre histoire desormais,\nn'est-ce pas ?",
        "Tu comptes arreter mon plan alors que je cherche\n"
        "juste a sauver cette planete.",
        "Bien...",
        "Si tu survie assez lontemps tu auras surement la\n"
        "chance de voir la renaissance de notre monde.",
        ""};
    return (text[i]);
}

char *boss_3(int i)
{
    char *text[6] = {"Tu aurais du partir quand tu en avais l'occasion...",
        "Je ne te laisserais pas aller plus loin apres\n"
        "toutes les vies que tu as prises.",
        ""};
    return (text[i]);
}

char *boss_2(int i)
{
    char *text[3] = {"J'ai entendu dire que tu t'es deja debarasse de\n"
        "l'un d'entre nous.",
        "Je prefere te le dire, tu ne me battras pas aussi\nfacilement.",  ""};
    return (text[i]);
}

char *boss_1(int i)
{
    char *text[5] = {"Bienvenue a toi dans mon monde de flamme !",
        "j'espere que tu m'offrira un combat digne de ce\nnom.",
        "Je t'offirai une mort a la hauteur !", "C'est carre ?", ""};
    return (text[i]);
}

void boss_dialogue(scene_t *boss, char code, int *i)
{
    char *map = "123l";
    char *(*find_boss[4])(int) = {boss_1, boss_2, boss_3, boss_4};

    for (int j = 0; j != 4; j++)
        if (map[j] == code) {
            if (my_strcmp(sfText_getString(boss[6].texts->text), "") == 0)
                return;
            else
                sfSound_play(boss[3].sounds->sound);
            sfText_setString(boss[6].texts->text, find_boss[j](i[0]));
        }
}
