#include <ansi.h>
#include <npc.h>

void create()
{
    set_name("村長", ({ "village head", "head" }));
    set_race("human");
    set_level(1);
    set("title","鯨魚島村長");
    set("long", "這是鯨魚島的現任村長，看起來和藹可親，雖然年紀已大，但仍然顯\n"
                "得很有精神。\n");

    set("chat_chance", 1);
    set("chat_msg", ({
        "村長重重地嘆了口氣，似乎有什麼煩惱的心事。\n",
    }));
    setup();
}
