#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("���]��", ({ "red beetle","beetle"  }) );
    set_race("beast");
    set_level(15);

    set("long", "�@���������]�ΡA��өM��]�γ��O�P�@�Ӻرڪ��C\n");

    set("limbs", ({ "�Y��", "����", "�I��", "Ĳ��" }) );
    set("verbs", ({ "bite" }) );

    setup();

    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/honey.c");
    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/honey.c");
}
