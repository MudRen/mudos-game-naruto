#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"漆黑的石頭"NOR, ({ "black stone" }));
    if( !clonep() ) {
        set("base_unit", "枚");
        set("unit", "枚");
        set("base_value", 0);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "一顆黑色的小石頭，看起來非常不起眼。");
    }
    setup();
}
