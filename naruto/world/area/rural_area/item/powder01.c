#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"咖哩粉"NOR, ({ "curry powder", "powder", "_KARE_C_" }));
    if( !clonep() ) {
        set("unit", "包");
        set("value", 0);
        set("base_value", 0);
        set("base_weight", 10);
        set("long","製作擁有咖哩香味的食品時，通常都會添加此物。\n");
    }
    setup();
}
