#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("Ĩۣ", ({ "agaric" }) );
    set_race("beast");
    set_level(1);

    set("long", "���䪺Ĩۣ�A���n�ġC\n");

    set("limbs", ({ "ۣ�Y", "ۣ��", "ۣ��", "ۣ��", "ۣ��" }) );
    set("verbs", ({ "bite" }) );

    setup();
    // �d�z
    set_temp("apply/attack", -5);         // �����O�q
    set_temp("apply/defend", -5);         // ���m�O�q
    set_temp("apply/exact", -5);          // �R���v
    set_temp("apply/evade", -5);          // �j�ײv
    set_temp("apply/intimidate", -5);     // ������O
    set_temp("apply/wittiness", -5);      // ���m��O

}
