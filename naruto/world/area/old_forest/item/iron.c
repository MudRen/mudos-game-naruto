#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(RED"鐵礦"NOR, ({ "iron", "_IRON_" }));
    if( !clonep() ) {
        set("base_unit", "塊");
        set("unit", "塊");
        set("base_value", -1);
        set("base_weight", 50);
        set("long", "堅硬的鐵礦，不過尚未經過處理還很粗糙。");
    }
    setup();
}
