#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("甜湯", ({ "sweet broth", "broth" }));
        set("unit", "份");
        set("base_unit", "份");
        set("base_value", 600);
        set("base_weight", 200);
        set("food_stuff", 40);
        set("long","在吃完燒賣後喝一碗能夠去除油膩還有鹹味的甜湯吧。\n"
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
