#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"晶石"NOR, ({ "crystallize" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("unit", "顆");
        set("base_value", 5);
        set("base_weight", 1);
        set("long", "冰天雪地中所凝結的晶體，遇到炎熱便立刻融化。");
    }
    setup();
}