#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(BYEL"猴屎"NOR, ({ "monkey shit", "shit" }));
    if( !clonep() ) {
        set("base_unit", "沱");
        set("base_value", 2);
        set("base_weight", 50);
        set("long", "臭氣沖天的猴子大便。\n");
    }
    setup();
}
