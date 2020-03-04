#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BRED+HIR"紅玉"NOR, ({ "carbuncle" }));
    if( !clonep() ) {
        set("base_unit", "顆");
        set("unit", "顆");
        set("base_value", 20000);
        set("base_weight", 1);
        set("no_box", 1);
        set("long", "通體成紅的玉，發出血紅色的光澤，是一些皇室貴族特別喜歡的玉類\n"
                    "，能夠發出的光芒越鮮紅，價格越高。\n");
    }
    setup();
}