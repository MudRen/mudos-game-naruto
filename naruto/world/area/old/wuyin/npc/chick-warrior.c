#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�԰���", ({ "chick warrior","warrior","chick" }) );
    set_race("beast");
    set_level(23);

    set("long", "�@�������V�m�L�����A�������n�Z�\���j�C\n");

    set("limbs", ({ "���a", "����", "���L", "������", "����" }) );
    set("verbs", ({ "bite" }) );
 
    setup();

    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/jelly.c");
    if( random(100) > 60 ) carry_object("/world/area/wuyin/eq/cockscomb.c")->wear();
    if( random(100) > 90 ) carry_object("/world/area/wuyin/eq/war-boots.c")->wear();
    if( random(100) > 60 ) carry_object("/world/eq/hand/fist")->wear();

}
