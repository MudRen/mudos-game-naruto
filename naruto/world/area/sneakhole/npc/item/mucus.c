#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�j���H�G"NOR, ({ "spider mucus", "mucus","_SPIDER_MUCUS_" }));
    if( !clonep() ) {
        set("base_unit", "�b");
        set("base_value", 60);
        set("base_weight", 100);
        set("long", "�@���H�H���j��G��C\n");
    }
    setup();
}
