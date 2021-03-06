#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("日向奅暉", ({ "ninja" }));
    set_race("human");
    set_level(21);
    set_class("middle");  // 中忍 
    set("long", "日向家族的忍者，因為出任務而身負重傷，應該活不過今晚了..\n");

    set("title", HIW"日向家族"NOR);
    set("age", 24);
    set("gender", "male");

    // 一般時動作
    set("chat_chance", 10);
    set("chat_msg", ({
        (: command, "say 可惡！...咳咳！" :),
        CYN"日向奅暉淚流滿面，似乎非常痛苦。\n"NOR,
    }) );
    setup();
    set_stat_current("hp", 1);
}
