/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create_fight
*/
#include "../../include/my.h"
#include "../../include/struct.h"

void destroy_fight(scene_t *fight)
{
    for (int i = 0; i != 5; i++)
        destroy_object(fight[i].objs->my_sprite, fight[i].objs->my_texture);
    free(fight[5].player);
    for (int i = 6; i != 14; i++)
        destroy_sound(fight[i].sounds->sound, fight[i].sounds->soundbuffer);
    for (int i = 14; i != 22; i++)
        sfRectangleShape_destroy(fight[i].buttons->rect);
    for (int i = 22; i != 37; i++)
        destroy_text(fight[i].texts->text, fight[i].texts->font);
    sfClock_destroy(fight[37].times->clock);
}

void create_fight_three(scene_t *fight, bool pause)
{
    char pv[10];
    char pm[10];
    char damage[10];
    char *text[7] = {pv, "pv", pm, "pm", damage, "", ""};
    sfVector2f pos[7] = {create_v2f(550, 500),
        create_v2f(615, 500), create_v2f(685, 500),
        create_v2f(760, 500), create_v2f(-30, -30),
        create_v2f(1025, 570), create_v2f(1050, 615)};
    sfColor color[7] = {sfCyan, sfCyan, sfMagenta, sfMagenta,
        sfWhite, sfCyan, sfCyan};

    int_to_str(text[0], fight[5].player->pv, 2);
    int_to_str(text[2], fight[5].player->pm, 2);
    int_to_str(text[4], 0, 2);
    for (int i = 30, j = 0; i != 37; i++, j++)
        fight[i].texts = create_text(text[j], pos[j], 30, color[j]);
    fight[37].times = create_time();
    if (pause == false)
        sfSound_play(fight[6].sounds->sound);
}

void create_fight_two(scene_t *fight, bool pause)
{
    char *sound[7] = {"sound/victory.ogg", "sound/blaster.ogg",
        "sound/damage.ogg", "sound/button.ogg", "sound/error.ogg",
        "sound/item.ogg", "sound/enemy_death.ogg"};
    char *buttons[7] = {"ATTAQUE", " OBJET", "FUITE", "   BLASTER",
        "    FEU 3pm", "   VENT 7pm", "ECLAIR 10pm"};
    sfColor color[4] = {sfCyan, sfRed, sfGreen, sfYellow};
    fight[6].sounds = create_sound("sound/fight.ogg", sfTrue);
    for (int i = 7, j = 0; i != 14; i++, j++)
        fight[i].sounds = create_sound(sound[j], sfFalse);
    fight[14].buttons = init_button(create_v2f(500, 550),create_v2f(1000, 150));
    for (int i = 15, j = 415; i != 18; i++, j += 450)
        fight[i].buttons = init_button(create_v2f(j, 700),create_v2f(300, 125));
    for (int i = 18, j = 150; i != 22; i++, j += 100)
        fight[i].buttons = init_button(create_v2f(915, j), create_v2f(200, 75));
    fight[22].texts = create_text("", create_v2f(517, 560), 37, sfCyan);
    for (int i = 23, j = 435, k = 0; i != 26; i++, j += 470, k++)
        fight[i].texts = create_text(buttons[k], create_v2f(j, 735),50, sfCyan);
    for (int i = 26, j = 175, k = 3, m = 0; i != 30; i++, j += 100, k++, m++)
        fight[i].texts = create_text(buttons[k], create_v2f(930, j),
                                     23, color[m]);
    create_fight_three(fight, pause);
}

int create_fight_one(sfRenderWindow *window, int max,
                     protagonist_t *chara, bool pause)
{
    scene_t fight[38];
    fight[0].objs = create_object("sprite/fight.png", create_v2f(0, 0),
                                create_rect_int(0, 0, 650, 365), create_v2f(3, 3));
    fight[1].objs = create_object("sprite/protagonist_fight.png", create_v2f(540, 300),
                                create_rect_int(400, 0, 200, 100), create_v2f(2.2, 2.2));
    fight[2].objs = create_object("sprite/enemies.png", create_v2f(1180, 125),
               create_rect_int(max * 150, rand() % 3 * 600, 150, 150), create_v2f(3, 3));
    fight[3].objs = create_object("sprite/inventory.png", create_v2f(645, 70),
                                create_rect_int(0, 0, 736, 435), create_v2f(1, 1));
    fight[4].objs = create_object("sprite/item.png", create_v2f(660, 100),
                                create_rect_int(0, 0, 350, 50), create_v2f(1, 1));
    fight[5].player = before_fight(fight[5].player, chara, max * 150);
    create_fight_two(fight, pause);
    if (draw_fight_one(window, fight, max + 1) == 1) {
        destroy_fight(fight);
        return (1);
    }
    after_fight(fight[5].player, chara);
    destroy_fight(fight);
}
