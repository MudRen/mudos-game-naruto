#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�}"NOR, ({ "sugar", "_PILL_SUGAR_" }));
    if( !clonep() ) {
        set("unit", "�]");
        set("value", 100);
        set("base_value", 100);
        set("base_weight", 5);
        set("long","���q���}�A�q�`�Q���ӽը��ϥΡC\n");
    }
    setup();
}
