#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("���Y", ({ "dog", "_MY_PET_" }));
    set_race("beast");
    set_level(50);
    set("no_fight", 1);
    set("age", 8);
    set("long", "����������A�ݰ_�Ӥp�p�����Q���i�R�C\n");
    setup();
}
