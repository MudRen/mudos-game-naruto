#include <npc.h>

void create()
{
    set_name("母猴", ({ "female monkey", "monkey" }) );
    set_race("beast");
    set_level(10);
    set("age", 16+random(30));
    set("long", "比較壯的猴子，身旁總是跟著幾隻小猴子。\n");
    set("limbs", ({ "猴頭", "身體", "肚子", "猴臂", "尾巴", "猴背", "屁股" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
    set("set_drop", ({
        ([ "type":"obj", "id":37, "amount":1+random(7), "p1":70, "p2":100 ]),   // 猴屎
        ([ "type":"obj", "id":38, "amount":1+random(5), "p1":60, "p2":100 ]),   // 猴牙
        ([ "type":"eq", "id":73, "amount":1, "p1":40, "p2":100 ]),              // 猴皮
        ([ "type":"food", "id":43, "amount":1, "p1":30, "p2":100 ]),            // 猴掌
        ([ "type":"obj", "id":36, "amount":1, "p1":1, "p2":100 ]),              // 古老地圖
    }) );
    setup();
    // 削弱
    set_temp("apply/attack", -5);         // 攻擊力量
    set_temp("apply/defend", -5);         // 防禦力量
    set_temp("apply/exact", -10);          // 命中率
    set_temp("apply/evade", -10);          // 迴避率
    set_temp("apply/intimidate", -5);     // 攻擊能力
}
