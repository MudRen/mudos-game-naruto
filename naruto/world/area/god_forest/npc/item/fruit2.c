#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIC"水蓮"HIW"果"NOR"", ({ "hp fruit", "fruit" }));
    set("unit", "顆");
    set("base_value", 0);
    set("no_box", 1);
    set("base_weight", 10);
    set("food_stuff", 10);
    set("long", "吃了可以立即恢復你的體力值(HP) 1500 點。\n");
    set("heal", ([
        "hp": 1500,
    ]) );
    setup();
}
