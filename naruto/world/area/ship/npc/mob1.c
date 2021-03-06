#include <ansi.h>
#include <npc.h>

inherit F_SEABANDIT;

void create()
{
    set_name("打撈兵", ({ "drag man", "man" }) );
    set_race("human");
    set_level(25);
    set("title",HIY"猿山連合"NOR);
    set("gender", "male");
    set("class","little_sea");
    set("camp", "robber");
    set("age", 10+random(71));
    set("long", "穿著一身潛水裝，沒事喜歡跳來跳去吱吱學猴叫。\n");
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }));
    set("set_drop", ({
        ([ "type":"eq", "id":99, "amount":1, "p1":1, "p2":300 ]),         // 蛙鞋
        ([ "type":"eq", "id":100, "amount":1, "p1":1, "p2":200 ]),        // 潛水衣
        ([ "type":"eq", "id":3, "amount":1, "p1":1, "p2":100 ]),          // 龜甲
        ([ "type":"eq", "id":14, "amount":1, "p1":40, "p2":100 ]),        // 蛙鏡
        ([ "type":"wp", "id":57, "amount":1, "p1":30, "p2":100 ]),        // 魚叉
    }) );
    setup();
}
