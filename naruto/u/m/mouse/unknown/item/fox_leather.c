#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"狐皮"NOR, ({ "fox leather", "leather", "_FOX_LEATHER_" }) );

    if( !clonep() ) {
        set("base_unit", "張");
        set("unit", "張");
        set("base_value", 50);
        set("base_weight", 300);
        set("long", "狐熊的毛皮，摸起來很暖和。\n");
    }
    setup();
}
