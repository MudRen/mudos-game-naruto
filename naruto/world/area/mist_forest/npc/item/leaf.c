#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(CYN"冰葉"NOR, ({ "leaf-ice", "leaf" }));
    if( !clonep() ) {
        set("base_unit", "片");
        set("unit", "片");
        set("base_value", 2);
        set("base_weight", 1);
        set("long", "被冰所冰凍的葉片，因為時間過長而成為晶體。");
    }
    setup();
}