#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"辣椒粉"NOR, ({ "chili powder", "powder", "_CHILI_D_" }));
    if( !clonep() ) {
        set("unit", "包");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 10);
        set("long","將辣椒磨成粉狀的樣子，用來給食品添上少許辣味。\n");
    }
    setup();
}
