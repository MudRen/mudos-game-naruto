#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIW"大白鯊"NOR, ({ "white shark", "shark" }) );
    set_race("beast");
    set_level(21);
    set("age", random(100) + 5);
    set("long", "大型鯊魚，非常具有危險性。\n");
    set("limbs", ({ "鯊頭", "身體", "腹部", "鯊尾", "鯊鰭" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"food", "id":75, "amount":1, "p1":80, "p2":100 ]),   // 鯊魚肉
        ([ "type":"obj", "id":104, "amount":1, "p1":30, "p2":100 ]),   // 鯊牙
        ([ "type":"obj", "id":103, "amount":1, "p1":20, "p2":100 ]),   // 鯊魚皮
    }) );
    setup();
    add_temp("apply/attack", 50);
    add_temp("apply/armor", 30);
}
