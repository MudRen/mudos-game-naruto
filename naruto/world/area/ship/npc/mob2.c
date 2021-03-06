#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("探索兵", ({ "search man", "man" }) );
    set_race("human");
    set_level(28);
    set("title",HIY"猿山連合"NOR);
    set("gender", "male");
    set("class","little_sea");
    set("camp", "robber");
    set("age", 10+random(71));
    set("long", "頭上帶著椰子殼，不停四處張望的人，似乎在探索什麼。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"eq", "id":70, "amount":1, "p1":10, "p2":100 ]),        // 椰子殼
        ([ "type":"wp", "id":12, "amount":1, "p1":20, "p2":100 ]),        // 砍馬大刀
        ([ "type":"wp", "id":40, "amount":1, "p1":1, "p2":100 ]),         // 螺旋劍
    }) );
    setup();
}
