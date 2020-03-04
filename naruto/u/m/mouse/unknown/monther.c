#include <npc.h>

void create()
{
    set_name("黏怪", ({ "monther" }) );
    set_race("beast");
    set_level(8);

    set("long", "全身軟軟的像果凍，散發出噁心的臭味。\n");

    set("limbs", ({ "果凍頭", "果凍身", "果凍手", "果凍眼" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // 主動攻擊

    set("set_drop", ({
    //  ([ "type":"food", "id":??, "amount":1, "p1":40, "p2":100 ]),   // 果凍
    //  ([ "type":"eq", "id":??, "amount":1, "p1":10, "p2":100 ]),     // 果凍帽
    }) );
    setup();
}
