#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("蛇蛋", ({ "snake's egg", "egg", "_SNAKE_EGG_" }));

    if( !clonep() ) {
        set("base_unit", "顆");
        set("base_value", 100);
        set("base_weight", 600);
        set("food_stuff", 10);              // 食物量，食品一定要有食物量
        set("long", "一顆只有姆指般大小的蛇蛋。\n");
    }
    setup();
}
