#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(HIM"水果王"NOR, ({ "Fruit", "fruit", "_KING_FRUIT_" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("base_value", 200);
        set("base_weight", 500);
        set("food_stuff", 20);
        set("long", "大顆的水果，香甜好吃。\n");
    }
    setup();
}
