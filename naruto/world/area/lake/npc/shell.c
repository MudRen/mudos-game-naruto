#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("貝帥", ({ "shell commander", "commander" }) );
    set_race("beast");
    set_level(12);
    set("age", 5+random(105));
    set("long", "貝殼元帥，半張的貝中那顆巨大珍珠讓人看了直流口水。\n");
    set("limbs", ({ "貝殼", "貝肉", "珍珠" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
    set("chat_chance", 3);                 // 動作速率
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 3);          // 戰鬥速率
    set("chat_msg_combat", ({
        CYN"貝帥偷偷的打開外殼透氣。\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"food", "id":45, "amount":1, "p1":50, "p2":100 ]),  // 生蠔
        ([ "type":"eq", "id":76, "amount":1, "p1":30, "p2":100 ]),    // 貝殼
        ([ "type":"obj", "id":44, "amount":1, "p1":5, "p2":100 ]),    // 巨大珍珠
    }) );
    setup();

    // 增強
    add_temp("apply/armor", 50);
}
