#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIG"巨型海葵"NOR, ({ "anemone" }) );
    set_race("beast");
    set_level(15);
    set("age", random(500) + 5);
    set("long", "出現在強力海流區帶的大型海葵，利用堅韌的根刺擊地面移動。\n");
    set("limbs", ({ "身體", "葵根", "葵鬚", "葵心", "沙地" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":105, "amount":1, "p1":30, "p2":100 ]),   // 葵根
    }) );
    setup();
    set_stat_current("hp", 1000);
    set_stat_current("ap", 1000);
    set_stat_current("mp", 1000);
    set_stat_maximum("hp", 1000);
    set_stat_maximum("ap", 1000);
    set_stat_maximum("mp", 1000);
    add_temp("apply/armor", 100);
}
