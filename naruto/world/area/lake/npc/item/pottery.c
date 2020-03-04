#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("未知陶壺", ({ "pottery", "_UNKNOWN_POTTERY_" }));
    if( !clonep() ) {
        set("base_unit", "座");
        set("unit", "座");
        set("base_value", 20);
        set("base_weight", 100);
        set("long", "長相奇特的詭異陶壺，不知道能賣幾個銅板。");
    }
    setup();
}
