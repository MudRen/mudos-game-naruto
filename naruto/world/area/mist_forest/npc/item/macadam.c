#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("碎石", ({ "macadam" }));
    if( !clonep() ) {
        set("base_unit", "粒");
        set("unit", "粒");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "小碎石子，看起來沒什麼特別的。");
    }
    setup();
}