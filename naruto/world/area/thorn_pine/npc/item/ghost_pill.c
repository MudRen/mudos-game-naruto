#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("二鬼丹", ({ "twoghost pill", "pill" }));
        set("unit", "顆");
        set("base_value", 3600);
        set("base_weight", 10);
        set("food_stuff", 1);   // 食物量，食品一定要有食物量
        set("long", "能補充體力與魔力的良藥。\n");
        set("heal", ([ 
            "mp": 900,
            "hp": 900,
        ]));
    setup();
}

