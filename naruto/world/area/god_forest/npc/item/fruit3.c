#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIG"甘露"HIW"果"NOR"", ({ "mp fruit", "fruit" }));
    set("unit", "顆");
    set("base_value", 0);
    set("no_box", 1);
    set("base_weight", 10);
    set("food_stuff", 10);
    set("long", "吃了可以立即恢復你的魔力值(MP) 1500 點。\n");
    set("heal", ([
        "mp": 1500,
    ]) );
    setup();
}
