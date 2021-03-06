#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("母牛", ({ "cow" }) );
    set_race("beast");
    set_level(15);
    set("age", 5 + random(11));
    set("limbs", ({ "牛頭", "牛角", "乳頭", "背部", "尾巴", "腿部" }) );
    set("long", "平常可以擠牛奶喝，偶爾也能殺一隻吃吃牛肉，真是一舉兩得。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
        CYN"母牛叫道：哞∼∼哞∼∼\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"food", "id":77, "amount":1, "p1":40, "p2":100 ]),   // 牛肉
    }) );
    setup();
}
