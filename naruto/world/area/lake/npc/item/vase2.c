#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("破花瓶", ({ "vase" }));
    if( !clonep() ) {
        set("base_unit", "個");
        set("unit", "個");
        set("base_value", 2);
        set("base_weight", 100);
        set("long", "爛花瓶一個，根本是方糖勁想騙錢的東西。");
    }
    setup();
}
