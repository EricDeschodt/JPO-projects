/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** ultimate_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

protagonist_t *before_ultimate_fight(protagonist_t *fighter, protagonist_t *stat)
{
    fighter = malloc(sizeof(protagonist_t));
    fighter->lvl = stat->lvl;
    fighter->exp = stat->lvl;
    fighter->pv = stat->pv;
    fighter->pm = stat ->pm;
    fighter->attack = false;
    fighter->defense = false;
    fighter->inventory = false;
    fighter->victory = false;
    fighter->attack_up = 0;
    fighter->defense_up = 0;
    fighter->enemy_pv = 300;
    fighter->item = stat->item;
    return (fighter);
}

void destroy_ultimate_fight(scene_t * fight)
{
    for (int i = 0; i != 5; i++)
        destroy_object(fight[i].objs->my_sprite, fight[i].objs->my_texture);
    free(fight[5].player);
    for (int i = 6; i != 11; i++)
        destroy_sound(fight[i].sounds->sound, fight[i].sounds->soundbuffer);
    for (int i = 11; i != 18; i++)
        sfRectangleShape_destroy(fight[i].buttons->rect);
    for (int i = 18; i != 33; i++)
        destroy_text(fight[i].texts->text, fight[i].texts->font);
    for (int i = 33; i != 36; i++)
        sfClock_destroy(fight[i].times->clock);
        
    
}

void create_ultimate_fight_three(scene_t *fight)
{
    char pv[10];
    char pm[10];
    char damage[10];
    char *text[7] = {pv, "pv", pm, "pm", damage, "", ""};
    sfVector2f pos[7] = {create_v2f(125, 725),
        create_v2f(185, 725), create_v2f(125, 775),
        create_v2f(185, 775), create_v2f(-30, -30),
        create_v2f(1025, 570), create_v2f(1050, 615)};
    sfColor color[7] = {sfCyan, sfCyan, sfMagenta, sfMagenta,
        sfWhite, sfCyan, sfCyan};

    int_to_str(text[0], fight[5].player->pv, 2);
    int_to_str(text[2], fight[5].player->pm, 2);
    for (int i = 26, j = 0; i != 33; i++, j++)
        fight[i].texts = create_text(text[j], pos[j], 30, color[j]);
    fight[33].times = create_time();
    fight[34].times = create_time();
    fight[35].times = create_time();
}

void create_ultimate_fight_two(scene_t *fight)
{
    char *sound[5] = {"sound/blaster.ogg", "sound/light_blaster.ogg",
        "sound/button.ogg", "sound/error.ogg", "sound/item.ogg"};
    char *buttons[6] = {"ATTAQUE", " OBJET", "   BLASTER",
        "    FEU 3pm", "   VENT 7pm", "ECLAIR 10pm"};
    sfColor color[4] = {sfCyan, sfRed, sfGreen, sfYellow};

    for (int i = 6, j = 0; i != 11; i++, j++)
        fight[i].sounds = create_sound(sound[j], sfFalse);
    fight[11].buttons = init_button(create_v2f(100, 850), create_v2f(1000, 150));
    for (int i = 12, j = 270; i != 14; i++, j += 400)
        fight[i].buttons = init_button(create_v2f(j, 700), create_v2f(300, 125));
    for (int i = 14, j = 200; i != 18; i++, j += 100)
        fight[i].buttons = init_button(create_v2f(535, j), create_v2f(200, 75));
    fight[18].texts = create_text("", create_v2f(117, 857), 37, sfCyan);
    fight[19].texts = create_text("", create_v2f(117, 857), 37, sfWhite);
    for (int i = 20, j = 290, k = 0; i != 22; i++, j += 420, k++)
        fight[i].texts = create_text(buttons[k], create_v2f(j, 735), 50, sfCyan);
    for (int i = 22, j = 225, k = 2, m = 0; i != 26; i++, j += 100, k++, m++)
        fight[i].texts = create_text(buttons[k], create_v2f(550, j), 23, color[m]);
    create_ultimate_fight_three(fight);
}

int create_ultimate_fight_one(sfRenderWindow *window, protagonist_t *stat,
                              sound_t *music)
{
    scene_t fight[36];

    fight[0].objs = create_object("sprite/epilepsie.jpg.png", create_v2f(0, 0),
                                  create_rect_int(0, 0, 650, 365), create_v2f(3, 3));
    fight[1].objs = create_object("sprite/protagonist_fight.png", create_v2f(260, 395),
                                  create_rect_int(400, 0, 200, 100), create_v2f(1.7, 1.7));
    fight[2].objs = create_object("sprite/epilepsie_lazer.png", create_v2f(0, 25),
                                  create_rect_int(0, 0, 640, 360), create_v2f(2.5, 2.5));
    fight[3].objs = create_object("sprite/inventory.png", create_v2f(270, 195),
                                  create_rect_int(0, 0, 736, 435), create_v2f(1, 1));
    fight[4].objs = create_object("sprite/item.png", create_v2f(285, 225),
                                  create_rect_int(0, 0, 350, 50), create_v2f(1, 1));
    fight[5].player = before_ultimate_fight(fight[5].player, stat);
    create_ultimate_fight_two(fight);
    if (draw_ultimate_fight_one(window, fight, music) == 1) {
        destroy_ultimate_fight(fight);
        return (1);
    }
    destroy_ultimate_fight(fight);
}
