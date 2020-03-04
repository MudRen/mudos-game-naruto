#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("捕獸夾", ({ "trap" }) );

    if( !clonep() ) {
        set("base_unit", "具");
        set("unit", "具");
        set("base_value", 100);
        set("base_weight", 800);
        set("long", "捕獸用的夾子，但是已經壞掉了。\n");
    }
    setup();
}
