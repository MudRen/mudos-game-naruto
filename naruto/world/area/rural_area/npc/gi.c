#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
    set_name("阿基", ({ "gi" }));
    set_race("human");
    set_level(15);
    set("age", 21);
    set("nickname",YEL"咖哩"NOR);
    set("long", "他故意把自己裝扮成黑社會的樣子，但是卻一點也不像。\n");
    set("gender", "male");
    set("chat_chance", 3);
    set("chat_msg", ({
        (: command, "say 我阿基給大家說∼千萬別混黑社會∼" :),
        (: command, "sing" :),
    }));
    setup();
}
