#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"落花生"NOR, ({ "Peanut", "peanut" }));
    if( !clonep() ) {
        set("base_unit", "袋");
        set("base_value", -1);
        set("unit", "袋");
        set("base_weight", 500);
        set("long", "看起來很好吃的一袋落花生。\n");
    }
    setup();
}
