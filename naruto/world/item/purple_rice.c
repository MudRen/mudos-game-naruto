#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIM"紫米"NOR, ({ "Purple rice", "rice" }));
    if( !clonep() ) {
        set("base_unit", "包");
        set("base_value", -1);
        set("unit", "包");
        set("base_weight", 500);
        set("long", "一包上面蓋著"HIR"[正]"NOR"字印章的紫米。\n");
    }
    setup();
}
