#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("�ѹA��", ({ "old farmer", "farmer" }));
    set_race("human");
    set_level(5);
    set("age", 81);
    set("long", "���y�K�����ѹA�ҡA�����N���@���u�������������C\n");
    set("gender", "male");
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "laugh" :),
        (: command, "smile" :),
        (: command, "ssmile" :),
        (: command, "huge" :),
    }));
    setup();
}
