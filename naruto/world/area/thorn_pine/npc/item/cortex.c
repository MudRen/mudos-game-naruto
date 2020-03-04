#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"樹皮"NOR, ({ "cortex" }));
    if( !clonep() ) {
        set("base_unit", "塊");
        set("unit", "塊");
        set("base_value", 200);
        set("base_weight", 10);
        set("long", "刺松林樹人的樹皮，時常被人收集。");
    }
    setup();
}
