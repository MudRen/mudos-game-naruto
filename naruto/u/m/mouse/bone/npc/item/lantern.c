#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIG"通倍利燈籠"NOR, ({ "tonbeli lantern", "lantern", "_TONBELI_A_" }));
    if( !clonep() ) {
        set("base_unit", "盞");
        set("base_value", 10000);
        set("base_weight", 600);
        set("long", "通倍利所拿的燈籠，時常發出綠色的亮光。\n");
    }
    setup();
}
