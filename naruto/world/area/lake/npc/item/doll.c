#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("精緻娃娃", ({ "doll", "_EXQUISITE_DOLL_" }));
    if( !clonep() ) {
        set("base_unit", "盒");
        set("unit", "盒");
        set("base_value", 20);
        set("base_weight", 100);
        set("long", "造型精美的娃娃，連關節部份都可活動。");
    }
    setup();
}
