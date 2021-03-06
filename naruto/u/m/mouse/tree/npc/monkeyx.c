#include <npc.h>
#include <ansi.h>

void create()
{
    set_name(HIR"猴"HIY"王"NOR, ({ "monkey king", "monkey", "king" }));
    set_race("beast");
    set_level(25);
    set("age", 150);
    set("title", "大金剛");
    set("long", "體型類似猩猩般壯碩的大猴子，手上的傷痕正是牠成為王者的證明。\n");
    set("limbs", ({ "猴頭", "身體", "肚子", "猴臂", "尾巴", "猴背", "屁股" }) );
    set("verbs", ({ "bite" }) );
    set("attitude", "aggressive");         // 主動攻擊
    set("set_drop", ({
        ([ "type":"eq", "id":73, "amount":1, "p1":90, "p2":100 ]),              // 猴皮
        ([ "type":"food", "id":43, "amount":1+random(1), "p1":80, "p2":100 ]),  // 猴掌
        ([ "type":"food", "id":42, "amount":1, "p1":50, "p2":100 ]),            // 猴腦
        ([ "type":"eq", "id":72, "amount":1, "p1":30, "p2":100 ]),              // 猴臂
        ([ "type":"eq", "id":69, "amount":1, "p1":10, "p2":100 ]),              // 金剛臂
    }) );
    setup();
    // 加強
    set_attr("str", 3);
    set_skill("combat", 100);             // 格鬥
    set_attr("str", 48);                   // 設定力量
    set_skill("parry", 100);              // 格擋
    set_skill("savage hit", 100);         // 暴擊
    set_skill("heavy hit", 100);          // 重擊
    set_skill("continual hit", 80);       // 連擊
    set_temp("apply/armor", 2);           // 防禦力量
    set_temp("apply/attack", 20);         // 攻擊力量
    set_temp("apply/defend", 20);         // 防禦力量
    set_temp("apply/exact", 10);          // 命中率
    set_temp("apply/intimidate", 10);     // 攻擊能力
    set_temp("apply/wittiness", 10);      // 防禦能力
    set_stat_current("hp", 1500);         // 體力
    set_stat_maximum("hp", 1500);         // 最大值
}

