#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("腐屍", ({ "zombie" }) );
    set_race("beast");
    set_level(15);
    set("age", 100+random(500));
    set("long", "全身腐爛的屍體，看久了有點噁心。\n");
    set("limbs", ({ "屍首", "屍身", "屍足", "屍腿", "屍臂", "屍手" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
    set("chat_chance", 5);                 // 戰鬥動作
    set("chat_msg", ({
        (: random_move :),
    }));
    set("chat_chance_combat", 3);          // 戰鬥速率
    set("chat_msg_combat", ({
        CYN"腐屍發出「嗚∼嗚∼∼」的怪聲。\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":50+random(100), "p1":50, "p2":100 ]),  // 銀子
        ([ "type":"eq", "id":5, "amount":1+random(1), "p1":40, "p2":100 ]),       // 繩子
        ([ "type":"eq", "id":4, "amount":1, "p1":30, "p2":100 ]),                 // 皮帶
    }) );
    setup();
    // 增強
    set_temp("apply/attack", 30);            // 攻擊力量
    set_temp("apply/armor", 180);            // 防禦力量
    set_stat_current("hp", 900);             // 體力
    set_stat_maximum("hp", 900);             // 最大值
}
