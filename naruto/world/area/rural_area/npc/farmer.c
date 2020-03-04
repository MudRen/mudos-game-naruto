#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("老農夫", ({ "old farmer", "farmer" }));
    set_race("human");
    set_level(5);
    set("age", 81);
    set("long", "滿臉皺紋的老農夫，眼睛瞇成一條線不停的笑呵呵。\n");
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
