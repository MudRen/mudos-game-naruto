#include <ansi.h>
#include <npc.h>

void create()
{
    set_name(HIR"�E����"NOR, ({ "demon fox", "fox" }) );
    set_race("beast");

    set_level(99);
    set("long", "�@���֦��E�����ڪ����W�A�g���U�_���������A���G�n��A�����F�C\n");

    set("limbs", ({ "���Y", "����", "����", "���L", "����" }) );
    set("verbs", ({ "bite" }) );

    setup();
}
