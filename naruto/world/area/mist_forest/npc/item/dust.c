#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("塵埃", ({ "dust" }));
    if( !clonep() ) {
        set("base_unit", "堆");
        set("unit", "堆");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "無用的塵土，因為氣候的關係而累積成堆。");
    }
    setup();
}