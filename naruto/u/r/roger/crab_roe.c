#include <ansi.h>

inherit F_FOOD;

void create()
{
    set_name( "蟹黃", ({ "crab roe", "roe", "__CRAB_ROE__"}));
    if( !clonep() ) {
        set("base_unit", "團");
        set("unit", "團");
        set("base_value", 10);
        set("base_weight", 10);
        set("food_stuff", 5);
        set("long", "這是一小團新鮮的蟹黃。\n");
    }
    setup();
}

