#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("�Ǯ{", ({ "student" }) );
    set_race("human");
    set_level(5);
    set("age", 13);
    set("long", "�K�����󦬪��p�{�̡A�u�|����²�檺����C\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        CYN"�Ǯ{�M�ߪ���ť�K�����󪺫��ɡC\n"NOR,
    }));
    setup();
}
