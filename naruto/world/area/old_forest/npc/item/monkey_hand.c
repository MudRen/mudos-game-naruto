#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(YEL"猴掌"NOR, ({ "monkey hand", "hand" }));
    if( !clonep() ) {
        set("base_unit", "個");
        set("base_value", 20);
        set("base_weight", 600);
        set("food_stuff", 10);
        set("long", "猴子手掌，常被當成裝飾用品。\n");
    }
    setup();
}
