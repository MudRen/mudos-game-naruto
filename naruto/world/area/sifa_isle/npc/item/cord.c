#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("火繩", ({ "cord", "_CORD_" }));
    if( !clonep() ) {
        set("base_unit", "條");
        set("unit", "條");
        set("base_weight", 100);
        set("base_value", 50);
        set("long", "用來發射火砲必須使用的導火繩。");
    }
    setup();
}
