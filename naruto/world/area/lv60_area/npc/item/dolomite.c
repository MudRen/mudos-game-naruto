#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("石灰", ({ "dolomite", "_DOLOMITE_" }));
    if( !clonep() ) {
        set("base_unit", "堆");
        set("unit", "堆");
        set("base_value", -1);
        set("base_weight", 50);
        set("long", "帶有黏性的石灰，碰到水會起火燃燒。");
    }
    setup();
}
