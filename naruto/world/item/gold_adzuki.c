#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIY"黃金紅豆"NOR, ({ "Gold adzuki", "adzuki" }));
    if( !clonep() ) {
        set("base_unit", "罐");
        set("base_value", -1);
        set("unit", "罐");
        set("base_weight", 500);
        set("long", "上面有著御手洗家冠軍標籤的極品紅豆。\n");
    }
    setup();
}
