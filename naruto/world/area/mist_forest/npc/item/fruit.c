#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"爛果"NOR, ({ "rotten fruit", "fruit" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("unit", "顆");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "因為擺太久而爛掉的水果，腐臭的外皮爬滿了蟲。");
    }
    setup();
}
