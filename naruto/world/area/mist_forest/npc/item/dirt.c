#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(BYEL"廢土"NOR, ({ "dirt" }));
    if( !clonep() ) {
        set("base_unit", "沱");
        set("unit", "沱");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "發出噁心臭味的土壤，不知道是哪來的。");
    }
    setup();
}