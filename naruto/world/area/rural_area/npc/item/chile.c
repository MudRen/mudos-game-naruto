#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(RED"辣椒醬"NOR, ({ "chile", "_CHILI_C_" }));
    if( !clonep() ) {
        set("unit", "罐");
        set("value", 1000);
        set("base_value", 1000);
        set("base_weight", 50);
        set("long","用朝天椒製作而成的辣椒醬，瓶子上還貼了一個《極辣》的字樣。\n");
    }
    setup();
}
