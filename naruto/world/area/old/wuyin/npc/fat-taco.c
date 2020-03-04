#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(YEL"�λL��"NOR, ({ "fat taco","taco" }) );
    set_race("beast");
    set_level(19);

    set("long", "�@���x�{���ت��ͪ��A�`�`�Ϯ��b�����ꪺ������A�@�����i���ҼˡC\n");

    set("limbs", ({ "Ĳ�}", "�L��", "�Y��", "����" }) );
    set("verbs", ({ "bite" }) );
 
    set("chat_chance", 3);
    set("chat_msg", ({
        "�λL���ƷȷȪ��b�a�W½�u�C\n",
                (: random_move :),
        }));

    setup();

    carry_money("silver", 20);
    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/taco-burn.c");
    if( random(100) > 95 ) carry_object("/world/area/wuyin/eq/octopus-cap.c");

}
