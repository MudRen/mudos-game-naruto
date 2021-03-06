#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name("海賊便當", ({ "bento" }));
        set("unit", "盒");
        set("base_value", 600);
        set("base_weight", 250);
        set("food_stuff", 50);              // 食物量，食品一定要有食物量
        set("long", "草帽海賊團外出時必備的重要物品，由香吉士所製作的特製海賊便當\n"
                    "，便當裡所用的都是一些附近海島上的特產，明明各有特色卻因為香\n"
                    "吉士的調製使得味道得以合而為一，除了美味的配菜之外，最重要的\n"
                    "就是主菜「肉」味道甜鹹適中，吃起來很有口感。在吃過這個便當之\n"
                    "後感覺全身的活力都來了，果然是最棒的便當。\n"
                    "三十秒內恢復 600 點精力值、體力值、魔力值。\n" );
        set("condition", ([
            "food": ([
                "name": HIG"進食中"NOR,
                "heal_ap": 40,
                "heal_hp": 40,
                "heal_mp": 40,
                "duration": 15,
            ]),
        ]) );
        setup();
}
