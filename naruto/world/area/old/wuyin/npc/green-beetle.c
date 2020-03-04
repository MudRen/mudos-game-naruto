#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("��]��", ({ "green beetle","beetle"  }) );
    set_race("beast");
    set_level(1);

    set("long", "�@���������]�ΡA�i�R���Ҽˬݰ_�ӬO���N���������C\n");

    set("limbs", ({ "�Y��", "����", "�I��", "Ĳ��" }) );
    set("verbs", ({ "bite" }) );

    setup();

    // �d�z
    set_temp("apply/attack", -5);         // �����O�q
    set_temp("apply/defend", -5);         // ���m�O�q
    set_temp("apply/exact", -5);          // �R���v
    set_temp("apply/evade", -5);          // �j�ײv
    set_temp("apply/intimidate", -5);     // ������O
    set_temp("apply/wittiness", -5);      // ���m��O

    if( random(100) > 80 ) carry_object("/world/area/wuyin/eq/bug-armor.c");
    if( random(100) > 60 ) carry_object("/world/area/wuyin/obj/honey.c");
}
