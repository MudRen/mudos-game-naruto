#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("天氣預測表", ({ "weather forecast", "weather" }));
    if( !clonep() ) {
        set("base_unit", "張");
        set("base_value", 0);
        set("unit", "張");
        set("base_weight", 1);
        set("long", "童角所寫的天氣預測表單。\n");
    }
    setup();
}
