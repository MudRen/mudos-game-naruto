#include <ansi.h>
#include <npc.h>

void create()
{
    set_name(HIG"���"NOR, ({ "daemon frog", "frog" }) );
    set_race("beast");

    set_level(90);
    set("long", "�@�����j�L������A�L���٤N�ڷϺޡC\n");

    set("limbs", ({ "����Y", "����", "����", "����L", "����" }) );
    set("verbs", ({ "bite" }) );

    setup();
}
