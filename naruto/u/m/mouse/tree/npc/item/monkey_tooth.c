#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
     set_name(HIW"猴牙"NOR, ({ "monkey tooth", "tooth", "_MONKEY_TOOTH_" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("base_value", 10);
        set("base_weight", 400);
        set("long", "打鬥中不慎被打斷而掉落地面的猴子牙齒。\n");
    }
    setup();
}
