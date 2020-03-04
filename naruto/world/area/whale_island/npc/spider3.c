#include <npc.h>
#include <ansi.h>

void create()
{
    set_name( HIK"巨型毒蛛" NOR, ({ "hug spider", "spider" }) );
    set_race("beast");
    set_level(20);

    set("long", "一隻巨型的劇毒蜘蛛，幾乎快要跟一隻老虎一樣大隻了，長的非常噁心，讓人看了只想作嘔。\n");
    set("title","陰影巢穴");

    set("limbs", ({ "蛛頭", "身體", "腹部", "蛛腿" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // 主動攻擊
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),   // 蜘蛛腿
        ([ "type":"obj", "id":53, "amount":1, "p1":80, "p2":100 ]),   // 蜘蛛眼睛
        ([ "type":"wp", "id":24, "amount":1, "p1":1, "p2":150 ]),     // 大蜘蛛腿
        ([ "type":"eq", "id":80, "amount":1, "p1":1, "p2":800 ]),     // 絲質手套
        ([ "type":"obj", "id":54, "amount":1, "p1":1, "p2":100 ]),    // 毒液
    }) );
    setup();
    add_temp("apply/attack", 20);
}
