#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("大螃蟹", ({ "big crab", "crab" }) );
    set_race("beast");
    set_level(8);
    set("age", 5+random(105));
    set("long", "這是一隻頗大隻的螃蟹，生活在海邊的沙灘上。\n");
    set("limbs", ({ "蟹殼", "蟹鉗", "肚子", "蟹腳", "蟹眼" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 6);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"food", "id":47, "amount":1, "p1":80, "p2":100 ]),    // 蟹肉
        ([ "type":"food", "id":48, "amount":1, "p1":60, "p2":100 ]),    // 蟹黃
    }) );
    setup();

}
