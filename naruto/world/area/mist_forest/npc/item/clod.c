#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"結塊"NOR, ({ "clod" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("unit", "顆");
        set("base_value", 5);
        set("base_weight", 1);
        set("long", "在沙塵中慢慢凝聚起來的塊狀物體，非常脆弱，一捏即碎。");
    }
    setup();
}