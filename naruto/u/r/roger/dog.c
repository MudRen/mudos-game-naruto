/* dog.c
   write by -Acme-
*/

#include <npc.h>

void create()
{
    set_name("野狗", ({ "dog" }) );
    set_race("beast");
    set_level(1);

    set("long", "一隻髒兮兮的野狗，嘴角還滴著口水。\n");

    set("limbs", ({ "狗頭", "身體", "腹部", "狗腿", "尾巴" }) );
    set("verbs", ({ "bite" }) );

    // 隨機移動
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    set("set_drop", ({
        ([ "type":"eq", "id":5, "amount":1, "p1":10, "p2":100 ]),     // 繩子
    }) );

    setup();
    
    // 削弱
    set_attr("str", 5);
    set_attr("con", 5);
    set_attr("dex", 5);
    set_attr("int", 5);
    set_temp("apply/attack", -10);         // 攻擊力量
    set_temp("apply/defend", -10);         // 防禦力量
    set_temp("apply/exact", -10);          // 命中率
    set_temp("apply/evade", -10);          // 迴避率
    set_temp("apply/intimidate", -10);     // 攻擊能力
    set_temp("apply/wittiness", -10);      // 防禦能力
}