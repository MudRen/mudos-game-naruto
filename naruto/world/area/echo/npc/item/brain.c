#include <ansi.h>
inherit F_FOOD;

void create()
{
    set_name(RED"鼠腦"NOR, ({ "mouse brain", "brain", "_MOUSE_HEAD_" }));

    if( !clonep() ) {
        set("base_unit", "顆");
        set("base_value", 100);
        set("base_weight", 600);
        set("food_stuff", 10);              // 食物量，食品一定要有食物量
        set("long", "一團紅色的地鼠腦袋。\n");
    }
    setup();
}
