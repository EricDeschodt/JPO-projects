/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** after_boss_intro
*/
#include "../../include/my.h"
#include "../../include/struct.h"

char *before_ultimate_boss(int i)
{
    char *text[5] = {"Mon ultime experience va commencer...",
        "Tu m'auras bien tenu tete.", "Mais ton voyage s'acheve ici desormais.",
        "Je vais pouvoir tous les ramener a la vie...\nCette terre renaitra grace a moi !", ""};
    return (text[i]);
}

char *after_boss_3(int i)
{
    char *text[6] = {"Je n'aurais pas pu tenir ma promesse, excuse moi...",
        "Je t'ai demande de t'enfuir, mais il devient un\nvrai danger, tu dois l'arreter.",
        "Je te donne tout mon pouvoir, utilise le a bon\nescient. Tu es notre ultime espoir...",
        "Je l'ai su des que je t'ai vu. Tes yeux et ton bras\nbrillent du meme bleu que cette fleur.",
        "(Vous obtenez une nouvelle attaque !\nVos pv et pm sont recharge au max !)", ""};
    return (text[i]);
}

char *after_boss_2(int i)
{
    char *text[6] = {"Ca me revient maintenant...",
        "S'il te plait ne tue pas le chef de l'observatoire,\nil n'y est pour rien lui aussi.",
        "La seule chose que je peux faire pour t'aider\ndans ta quete est de te leguer mes pouvoir",
        "(Vous obtenez une nouvelle attaque !\nVos pv et pm sont recharge au max !)", "", ""};
    return (text[i]);
}

char *after_boss_1(int i)
{
    char *text[6] = {"Que s'est-il passe ?\nTout a brule autour de moi puis...",
        "C'est a cause de l'experience...\nIl s'est joue de nous.", "Je suppose que tu peux agir.",
        "Tu m'a l'air d'avoir la puissance pour avoir\nmon pouvoir... je te donne ce qui me reste.",
        "(Vous obtenez une nouvelle attaque !\nVos pv et pm sont recharge au max !)", ""};
    return (text[i]);
}

void after_boss_dialogue(scene_t *boss, char code, int *i)
{
    char *map = "123";
    char *(*find_after_boss[4])(int) = {after_boss_1, after_boss_2,
        after_boss_3};

    for (int j = 0; j != 3; j++)
        if (map[j] == code) {
            if (my_strcmp(sfText_getString(boss[5].texts->text), "") == 0)
                return;
            else if (my_strcmp(find_after_boss[j](i[0] + 1), "") == 0)
                sfSound_play(boss[3].sounds->sound);
            else
                sfSound_play(boss[2].sounds->sound);
            sfText_setString(boss[5].texts->text, find_after_boss[j](i[0]));
        }
}
