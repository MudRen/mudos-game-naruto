// write by -Acme-

#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("路人", ({ "passerby" }));
    set_race("human");
    set_level(5);
    set("age", random(50)+18);
    set("long", "一位很普通的路人，一天在路上也可以碰見幾十個。\n");
    // 隨機移動
    set("chat_chance", 1);
    set("chat_msg", ({
        (: random_move :),
    }));

    set("set_drop", ({
        ([ "type":"obj", "id":29, "amount":16+random(10), "p1":50, "p2":100 ]),  // 銀子
        ([ "type":"eq", "id":7, "amount":1, "p1":10, "p2":100 ]),     // 布衣
        ([ "type":"wp", "id":10, "amount":1, "p1":10, "p2":100 ]),    // 短劍
    }) );

    setup();
}
