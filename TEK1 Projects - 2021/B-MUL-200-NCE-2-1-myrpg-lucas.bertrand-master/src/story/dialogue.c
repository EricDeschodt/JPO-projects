/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** dialogue
*/
#include "../../include/my.h"
#include "../../include/struct.h"

char *entry_labo_two(int x, int y)
{
    int pos_x[9] = {3, 2, 6, 15, 18, 21, 24, 10, 12};
    int pos_y[9] = {17, 11, 11, 11, 11, 11, 11, 1, 1};
    char *entry[9] = {"Cette etilativ bleue azur m'a permis d'alimenter\ndes centaine de machines.",
        "Beyond Stars, est le nom que j'ai donne au sujet\n"
        "qui s'est ecraser sur cette planete. Il a perdu un\nbras dans l'accident.",
        "Je lui ai creer une prothese alimente avec sa\npropre etilativ.",
        "Beyond Stars a disparu, il etait pourtant\ninconscient et ne connaissais pas"
        "le complexe.\nIl n'a pas pu fuir seul",
        "J'ai repare son vaisseau, il y a par dela les etoiles\ndes etilativs sans"
        "doute bien plus interressantes.\nje partirais apres mon utlime experience.",
        "Deux nouvelles etilativs ont ete\ndecouvertes suite a des fusions entre les 4"
        "que\nnous avions deja.",        
        "La premiere est violette, je ne sais rien de ses\ncapacites, mais je suis oblige"
        "de l'exploiter pour\nutiliser la derniere.",
        "La derniere etilativ est lumineuse, elle permettrait\nd'avoir des pouvoirs digne"
        "d'un dieu. Je pourrais\nsurement les ramener d'entre les morts",
        "La prochaine experience sera la derniere, l'avenir\nde notre planete se joue la,"
        "je sais que Beyond\nStars approche. La confrontation est inevitable."};
    for (int i = 0; i != 9; i++)
        if (x == pos_x[i] && y == pos_y[i]) return (entry[i]);
}

void intro_dialogue(scene_t *intro, int i)
{
    char *text[8] = {"Nous sommes assez eloigne pour le moment...",
        "Je te ramene ton vaisseau des que possible.",
        "Tu vas pouvoir t'echapper de la...",
        "Tu n'as pas a etre impliquer la dedans, alors...",
        "S'il te plait...",
        "n'intervient pas.",
        "Il est deja trop tard pour nous...",
        ""};
    sfText_setString(intro[3].texts->text, text[i]);
    sfSound_play(intro[5].sounds->sound);
}

sfColor ending_color(int i)
{
    if (i == 3 || i == 11 || i == 13 || i == 16 || i == 17 || i == 18 || i == 19)
        return (sfYellow);
    else if (i == 5 || i == 9 || i == 15)
        return (sfRed);
    else if (i == 7 || i == 12 || i == 14)
        return (sfGreen);
    return (sfWhite);
}

void ending_dialogue(scene_t *ending, int i)
{
    char *text[20] = {"Mais j'ai une planete a sauver.",
        "Pour te recompenser de tes efforts je t'offrirais\nune mort rapide.",
        "...", "ARRETE CA !!", "QUOI ?", "Evite de trop bouger si tu ne veux pas finir brule.",
        "Ne voyez vous pas que j'essaie de sauver notre\nmonde ?",
        "Notre monde etait deja perdu, on a fait ce qu'on a\npu...",
        "Alors quoi ? vous abandonnez ?", "Non, notre mission est accomplie.",
        "Toute les vies de cette planete ont disparues...\net vous me dites qu'on a reussi ?",
        "Toute ? Es-tu aveugle a ce point par\ntes nouveaux pouvoirs ?", 
        "Elle est pourtant juste sous tes\nyeux.",
        "Cette fleur d'une couleur bleue azur formidable,\nc'est pourtant ce "
        "qu'il y avait ecrit dans ton\nrapport.",
        "Nous ne le verrons pas mais notre planete\nrenaitra.",
        "C'est grace au differentes formes d'etilativ qu'il\na pu obtenir ce pouvoir.",
        "On t'a donne les notres, en les utilisant en meme\n"
        "temps tu devrais etre capable de le detruire.",
        "Je suis desole d'avoir du t'impliquer la dedans...\n"
        "mais tu vas enfin pouvoir rentrez chez-toi.",
        "Acheve-le maintenant Beyond Stars !", ""};
    sfText_setString(ending[7].texts->text, text[i]);
    sfText_setColor(ending[7].texts->text, ending_color(i));
    sfSound_play(ending[3].sounds->sound);
}
