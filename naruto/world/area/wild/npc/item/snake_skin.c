#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(GRN"蛇皮"NOR, ({ "snake's skin", "skin", "_SNAKE_SKIN_" }));

    if( !clonep() ) {
        set("base_unit", "片");
        set("base_value", 10);
        set("base_weight", 600);
        set("long", "一片還算完整的蛇皮。\n");
    }
    setup();
}
