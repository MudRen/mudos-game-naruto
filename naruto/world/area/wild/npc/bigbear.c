#include <npc.h>

void create()
{
    set_name("大熊", ({ "big bear", "bear" }) );
    set_race("beast");
    set_level(27);

    set("long", "一隻看起來很強壯且巨大的熊\n");

    set("limbs", ({ "熊頭", "身體", "腹部", "熊腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // 主動攻擊

    set("set_drop", ({
        ([ "type":"obj", "id":23, "amount":1, "p1":50, "p2":100 ]),   // 熊毛
        ([ "type":"food", "id":21, "amount":1, "p1":5, "p2":100 ]),   // 熊掌
        ([ "type":"eq", "id":65, "amount":1, "p1":5, "p2":100 ]),   // 熊大衣
    }) );

    setup();
}
