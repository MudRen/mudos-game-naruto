// write by -Acme-

#include <npc.h>

inherit F_FIGHTER;

void create()
{
    set_name("小孩", ({ "child" }));
    set_race("human");
    set_level(3);
    set("age", 6+random(10));
    set("long", "一個流著鼻涕的小孩，不知在哪玩得全身髒兮兮。\n");

    // 隨機移動
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    // 設定掉落物結構： (分子/分母) 是掉落機率
    // ({ ([ "type":類別, "id":編號, "amount":數量, "p1":分子, "p2":分母 ]),
    //    ([ ... ]), ([ ... ]), ... })
    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":random(10)+1, "p1":50, "p2":100 ]),  // 銀子
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // 布衣
        ([ "type":"wp", "id":9, "amount":1, "p1":10, "p2":100 ]),     // 蘿蔔
    }) );

    setup();

    // 削弱
    set_attr("str", 12);
    set_attr("con", 12);
    set_attr("dex", 12);
    set_attr("int", 12);
    set_temp("apply/attack", -5);         // 攻擊力量
    set_temp("apply/defend", -5);         // 防禦力量
    set_temp("apply/exact", -5);          // 命中率
    set_temp("apply/evade", -5);          // 迴避率
    set_temp("apply/intimidate", -5);     // 攻擊能力
    set_temp("apply/wittiness", -5);      // 防禦能力
}
