#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"糖"NOR, ({ "sugar", "_PILL_SUGAR_" }));
    if( !clonep() ) {
        set("unit", "包");
        set("value", 100);
        set("base_value", 100);
        set("base_weight", 5);
        set("long","普通的糖，通常被拿來調味使用。\n");
    }
    setup();
}
