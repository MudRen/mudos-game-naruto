#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name(YEL"樹果"NOR, ({ "Fruit", "fruit", "_TREE_FRUIT_" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("base_value", 10);
        set("base_weight", 200);
        set("food_stuff", 5);
        set("long", "樹上掉下來的果實。\n");
    }
    setup();
}
