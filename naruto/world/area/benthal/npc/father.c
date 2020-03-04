#include <npc.h>
#include <ansi.h>

void to_do_say()
{
    do_chat( ({
        (: command, "say 為了輕鬆的在海底活動。" :),
        (: command, "say 每天都要出門去搬移珊瑚礁。" :),
        (: command, "sweat" :),
    }) );
}
void create()
{
    set_name("魚公", ({ "fish father", "father" }) );
    set_race("human");
    set_level(10);
    set("nickname", HIG"魚公移珊"NOR);
    set("age", 41);
    set("long", "一位生活在海底的魚人，不知道他離群而居是什麼原因？\n");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: to_do_say :),
    }));
    setup();
}
