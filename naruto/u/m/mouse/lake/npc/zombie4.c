#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("腐屍", ({ "zombie" }) );
    set_race("beast");
    set_level(16);
    set("age", 450);
    set("nickname", "女傭");
    set("long", "從她身上未完全腐爛的衣服可以看出是一位女傭。\n");
    set("limbs", ({ "屍首", "屍身", "屍足", "屍腿", "屍臂", "屍手" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
    set("chat_chance_combat", 5);          // 戰鬥動作
    set("chat_msg_combat", ({
        NOR"腐屍幽幽怨道﹕"HIG"主人阿∼主人阿∼\n"NOR,
    }));
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":100+random(150), "p1":70, "p2":100 ]), // 銀子
        ([ "type":"eq", "id":5, "amount":1+random(1), "p1":40, "p2":100 ]),       // 繩子
        ([ "type":"eq", "id":4, "amount":1, "p1":30, "p2":100 ]),                 // 皮帶
        ([ "type":"obj", "id":46, "amount":1, "p1":20, "p2":100 ]),               // 紅卷
    }) );
    setup();
    // 增強
    set_temp("apply/attack", 30);            // 攻擊力量
    set_temp("apply/armor", 180);            // 防禦力量
    set_stat_current("hp", 1000);            // 體力
    set_stat_maximum("hp", 1000);            // 最大值
}
