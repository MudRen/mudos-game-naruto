// man.c

#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("居民", ({ "dweller" }) );
    set_race("human");
    set_level(7);
    set("age", random(50)+18);
    set("long", "一個居住在這附近的居民，看起來普普通通，沒什麼特別。\n");

    // 隨機移動
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":11+random(10), "p1":50, "p2":100 ]),  // 銀子
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // 布衣
        ([ "type":"wp", "id":11, "amount":1, "p1":10, "p2":100 ]),    // 短劍
    }) );

    setup();
}
