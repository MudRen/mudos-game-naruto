#include <ansi.h>
#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("土著射手", ({ "aborigines shooter", "shooter" }));
    set_race("human");
    set("gender", "female");
    set("age", 10+random(40));
    set_level(10);
    set("long", "土著的保衛戰士，手持弓箭驅逐外人進入。\n");
    set("attitude", "aggressive");
    set("set_drop", ({
        ([ "type":"food", "id":40, "amount":1+random(5), "p1":50, "p2":100 ]),  // 乾果
        ([ "type":"food", "id":38, "amount":1+random(2), "p1":30, "p2":100 ]),  // 樹果
        ([ "type":"food", "id":39, "amount":1+random(1), "p1":15, "p2":100 ]),  // 水果
        ([ "type":"eq", "id":71, "amount":1, "p1":10, "p2":100 ]),              // 樹葉
        ([ "type":"wp", "id":19, "amount":1, "p1":5, "p2":100 ]),               // 弓
        ([ "type":"wp", "id":18, "amount":1, "p1":5, "p2":100 ]),               // 箭
    }) );
    setup();
    // 增強
    set_temp("apply/attack", 255);           // 攻擊力量
    set_temp("apply/armor", 50);            // 防禦力量
    set_temp("apply/exact", 60);            // 命中率
    set_temp("apply/evade", 10);            // 迴避率
    set_temp("apply/armor", 51);            // 防禦力量
    set_skill("combat", 50);             // 格鬥
    set_skill("dodge", 50);              // 閃躲
    set_skill("continual hit", 50);      // 連擊
    set_stat_current("hp", 700);         // 體力
    set_stat_maximum("hp", 700);         // 最大值
}
