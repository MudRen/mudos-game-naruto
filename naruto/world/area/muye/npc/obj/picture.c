#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("的照片", ({ "picture", "__PIC__" }));
    set("unit", "張");
    set("base_unit", "張");
    set("base_value", -1);
    set("base_weight", 1);
    set("no_box", 1);
    setup();
}
