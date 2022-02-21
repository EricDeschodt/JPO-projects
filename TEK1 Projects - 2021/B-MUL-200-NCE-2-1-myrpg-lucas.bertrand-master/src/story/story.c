/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** story
*/
#include "../../include/my.h"
#include "../../include/struct.h"

char *entry_labo(int x, int y)
{
    int pos_x[14] = {10, 12, 18, 21, 23, 19, 29, 28, 31, 23, 15, 13, 8, 5};
    int pos_y[14] = {22, 22, 30, 30, 23, 23, 23, 32, 14, 14, 14, 17, 17, 22};
    char *entry[14] = {"Notre planete est mourrante, nous devons agir\navant qu'il ne soit trop tard.",
        "Nous avons reuni une equipe de scientifiques pour\nsauver notre monde, nous sommes 4 et avons\nchacun nos specialites.",
        "Les premieres experiences sont concluantes.\nNous avons pu extraire une forme d'energie\nprovenant des etres vivants.",
        "Cette energie nous l'avons appelee l'etilativ, elle\nest differente selon la forme de vie dont elle\nprovient.",
        "L'etilativ animale est rouge et flamboyante, la ou\ncelle des vegetaux est verte et plus volatile.",
        "En injectant l'etilativ vegetale dans les animaux,\net inversement, peut etre auront nous une\nnouvelle forme de vie.",
        "L'experience a eu lieu. La moitie du complexe\nparticipa a l'experience et seul 3 sujets ont\nsurvecu.",
        "Parmis eux, il y avait cette fleur teintee d'un\nbleue azur formidable. Ce sujet est actuellement\nen cours d'etude.",
        "Les 2 scientifiques ayant prit part a l'experience\nont survecu. Ils ont developpe des capacite\nhors du commun.",
        "Les sujets n'ayant pas survecu ont commence a\nfondre ou a fusionner entre eux. ce sont\ndesormais des etres qui ont perdu la raison.",
        "La folie a gagne les survivants de l'experience.\nNous devons aller plus loin, nous devons trouver\nune nouvelle forme d'etilativ.",
        "Nous avons fusione les deux types d'etilativ, pour\nen creer une nouvelle. Celle-ci est jaune et\nelectrique",
        "Je l'ai injectee dans les membres de l'observatoir,\nla derniere section du complexe. Il n'y a eu qu'un\nseul survivant",
        "Un nouveau sujet venu des etoiles est arrive,\nj'ai extrait l'etilativ de son corps. elle est\ndifferente de tout ce qu'on a vu."};
    for (int i = 0; i != 14; i++)
        if (x == pos_x[i] && y == pos_y[i])
            return (entry[i]);
    return (entry_labo_two(x, y));
}

char *entry_3(int x, int y)
{
    int pos_x[10] = {25, 5, 21, 5, 22, 14, 20, 8, 11, 15};
    int pos_y[10] = {26, 21, 18, 15, 10, 10, 6, 6, 3, 3};
    char *entry[10] = {"Nous recherchons de nouvelles etilativ parmis les\netoiles.",
        "Une lueur inhabituelle a ete observee. Au vu de\n"
        "ses deplacements, il s'agirait d'un vaisseau.",
        "Un objet est tombe du ciel, il s'agit d'un vaisseau.\n"
        "La lueur que nous observions a disparu.",
        "Le chef du complexe a recupere le pilote de la\nnavette,"
        "il est inconscient et semble etre blesse.",
        "Des experiences ont ete faites sur le corps\nrecupere, je ne peux pas le laisser faire.",
        "Qui sait jusqu'ou va aller sa folie ?",
        "J'ai reussi a le faire sortir du complexe. Son bras\n"
        "semble etre rempli d'une etilativ etrange.",
        "Je l'ai mis en lieu sur, les ruines sont inhabite\net aucun monstre n'y rode."
        " Je vais lui reparer\nson vaisseau.",
        "Les 2 premiers secteurs du complexe sont\nmeconnaissable"
        " et leurs chef ont totalement\nperdu la raison...",
        "Je le sens aussi, la folie me gagne depuis que\ntout ca a commence.",};
    for (int i = 0; i != 10; i++)
        if (x == pos_x[i] && y == pos_y[i]) return (entry[i]);
}

char *entry_2(int x, int y)
{
    int pos_x[3] = {25, 7, 9};
    int pos_y[3] = {23, 20, 20};
    char *entry[3] = {"L'etilativ va pouvoir faire renaitre les animaux\n"
    "de ce monde.",
    "La partie basse de mon corps s'est transformee.\n"
    "Je peux desormais me deplacer en levitant.",
    "Pour faciliter mes mouvements, je me suis\n"
    "fabriquer un baton capable d'exploiter l'etilativ."};

    for (int i = 0; i != 3; i++)
        if (x == pos_x[i] && y == pos_y[i])
            return (entry[i]);
}

char *entry_1(int x, int y)
{
    int pos_x[4] = {4, 15, 4, 26};
    int pos_y[4] = {24, 25, 1, 1};
    char *entry[4] = {"L'etilativ a ete extraite avec succes.\n"
    "L'experimentation va pouvoir commencer.",
    "La serre a pris feu... je n'ai pu sauver que tres\n"
    "peu de specimen et les replanter pres des\nruines...",
    "Toute les especes meurent petit a petit,\n"
    "il n'y a que cette fleur azur qui subsiste...",
    "Je perds petit a petit la raison,\n"
    "les choses deviennent de plus en plus flou..."};

    for (int i = 0; i != 4; i++)
        if (x == pos_x[i] && y == pos_y[i])
            return (entry[i]);
}

void entry(sfRenderWindow *window, scene_t *area, char **map)
{
    int x = (area[1].objs->pos.x - area[5].player->map_move[0] + 25) / 192;
    int y = ((area[1].objs->pos.y - area[5].player->map_move[1] - 10)  / 108) + 2;
    char *code = "123l";
    char *(*find_entry[4])(int, int) = {entry_1, entry_2, entry_3, entry_labo};

    if (map[0][0] != 'f' && map[y][x] == 'A') {
        if (my_strcmp(sfText_getString(area[15].texts->text), "") == 0) {
            for (int i = 0; code[i] != '\0'; i++)
                if (code[i] == map[0][0])
                    sfText_setString(area[15].texts->text, find_entry[i](x, y));
        }
        else
            sfText_setString(area[15].texts->text, "");
        sfSleep(sfSeconds(0.2));
    }
}
