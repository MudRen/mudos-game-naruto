#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(NOR"刺岩"NOR, ({ "splinter" }));
    if( !clonep() ) {
        set("base_unit", "片");
        set("unit", "片");
        set("base_value", 5);
        set("base_weight", 1);
        set("long", "被強風不斷衝擊下風化而成的尖石，非常銳利。");
    }
    setup();
}