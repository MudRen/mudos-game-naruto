#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("阿飛", ({ "fe" }));
    set_race("human");
    set_level(15);
    set("age", 20);
    set("nickname",HIR"辣椒"NOR);
    set("long", "他故意把自己裝扮成黑社會的樣子，但是卻一點也不像。\n");
    set("gender", "male");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say 我阿飛勸大家說∼入黑社會沒前途∼" :),
        (: command, "sing" :),
    }));
    setup();
}
