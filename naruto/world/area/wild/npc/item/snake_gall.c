#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"蛇膽"NOR, ({ "snake's gall", "gall", "_SNAKE_GALL_" }));

    if( !clonep() ) {
        set("base_unit", "粒");
        set("base_value", 200);
        set("base_weight", 600);
        set("food_stuff", 5);              // 食物量，食品一定要有食物量
        set("long", "一粒腥臭味十足的蛇膽。\n");
    }
    setup();
}
