#include <npc.h>

void create()
{
    set_name("巨海蟑螂", ({ "large cockroach", "cockroach" }) );
    set_race("beast");
    set_level(5);

    set("long", "一隻噁心的巨海蟑螂，通常都生活在海邊的沙灘上，而不是在下水道中。\n");

    set("limbs", ({ "蟑頭", "身體", "腹部", "蟑腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // 主動攻擊

    set("set_drop", ({
        ([ "type":"obj", "id":25, "amount":1, "p1":80, "p2":100 ]),   // 蟑螂觸角
        ([ "type":"food", "id":34, "amount":1, "p1":60, "p2":100 ]),   // 蟑螂卵
        ([ "type":"obj", "id":26, "amount":1, "p1":80, "p2":100 ]),   // 蟑螂腳
    }) );

    setup();
}
