#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BGRN"雜草"NOR, ({ "weeds" }));
    if( !clonep() ) {
        set("base_unit", "株");
        set("unit", "株");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "生命特別頑強的小草，不過已經奄奄一息了。");
    }
    setup();
}