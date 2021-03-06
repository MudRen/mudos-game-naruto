#include <npc.h>
#include <ansi.h>

void create()
{
    set_name("猴子", ({ "monkey" }));
    set_race("beast");
    set_level(15);
    set("age", 10+random(20));

    set("long", "一隻對人類沒有敵意的大猴子。\n");

    set("limbs", ({ "猴頭", "身體", "肚子", "猴臂", "尾巴", "猴背", "屁股" }) );
    set("verbs", ({ "bite" }) );
    set("chat_chance", 5);
    set("chat_msg", ({
        CYN"猴子吱吱的叫著。\n"NOR,
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"eq", "id":73, "amount":1, "p1":60, "p2":100 ]),              // 猴皮
        ([ "type":"food", "id":43, "amount":1+random(1), "p1":50, "p2":100 ]),  // 猴掌
        ([ "type":"food", "id":42, "amount":1, "p1":20, "p2":100 ]),            // 猴腦
        ([ "type":"eq", "id":70, "amount":1, "p1":5, "p2":100 ]),               // 椰子殼
        ([ "type":"obj", "id":36, "amount":1, "p1":5, "p2":100 ]),              // 古老地圖
    }) );
    setup();
}
