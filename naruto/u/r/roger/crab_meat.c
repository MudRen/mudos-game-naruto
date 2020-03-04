#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name( "蟹肉", ({ "crab meat","meat", "__CRAB_MEAT__"}));
    if( !clonep() ) {
        set("base_unit", "片");
        set("unit", "片");
        set("base_value", 4);
        set("base_weight", 10);
        set("food_stuff", 5);
        set("long", "這是一小片新鮮的蟹肉。\n");
    }
    setup();

}
