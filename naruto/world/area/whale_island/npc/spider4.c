#include <npc.h>
#include <ansi.h>

void create()
{
    set_name( HIK"突變毒蛛" NOR, ({ "mutation spider", "spider" }) );
    set_race("beast");
    set_level(22);

    set("long", "一隻巨型的突變劇毒蜘蛛，長的非常噁心，還發出非常噁心的味道，讓人看了只想作嘔。\n");
    set("title","陰影巢穴");

    set("limbs", ({ "蛛頭", "身體", "腹部", "蛛腿" }) );
    set("verbs", ({ "bite" }) );

    set("attitude", "aggressive");         // 主動攻擊
    set("set_drop", ({
        ([ "type":"obj", "id":52, "amount":2, "p1":80, "p2":100 ]),   // 蜘蛛腿
        ([ "type":"obj", "id":53, "amount":1, "p1":80, "p2":100 ]),   // 蜘蛛眼睛
        ([ "type":"wp", "id":24, "amount":1, "p1":1, "p2":100 ]),     // 大蜘蛛腿
        ([ "type":"eq", "id":80, "amount":1, "p1":1, "p2":650 ]),     // 絲質手套
        ([ "type":"obj", "id":54, "amount":1, "p1":2, "p2":100 ]),    // 毒液
        ([ "type":"obj", "id":55, "amount":1, "p1":1, "p2":300 ]),    // 蜘蛛胃袋
    }) );
    setup();
    add_temp("apply/attack", 20);
    set_skill("combat", 110);
    set_skill("dodge", 110);
    set_skill("parry", 110);
    set_skill("savage hit", 110);
    set_skill("heavy hit", 110);
    set_skill("continual hit", 110);
}
