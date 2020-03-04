#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("小螃蟹", ({ "small crab", "crab" }) );
    set_race("beast");
    set_level(3);
    set("age", 5+random(105));
    set("long", "這是一隻小螃蟹，生活在海邊的沙灘上。\n");
    set("limbs", ({ "蟹殼", "蟹鉗", "肚子", "蟹腳", "蟹眼" }) );
    set("verbs", ({ "bite" }) );
    set("set_drop", ({
        ([ "type":"food", "id":47, "amount":1, "p1":80, "p2":100 ]),    // 蟹肉
        ([ "type":"food", "id":48, "amount":1, "p1":60, "p2":100 ]),    // 蟹黃
            ([ "type":"obj", "id":87, "amount":1, "p1":1, "p2":500 ]),    // 飛天掃帚
    }) );
    setup();

}
