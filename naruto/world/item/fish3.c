#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name("膏魚", ({ "qao fish", "fish" }));
    if( !clonep() ) {
        set("base_unit", "條");
        set("base_value", 20);
        set("base_weight", 100);
        set("food_stuff", 15);              // 食物量，食品一定要有食物量
        set("long", "一條長得奇形怪狀的魚。\n");
    }
    setup();
}
