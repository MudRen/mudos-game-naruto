#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIY"������G"NOR, ({ "gold water", "water", "_HIY_WATER_" }));
    if( !clonep() ) {
        set("base_unit", "�~");
        set("unit", "�~");
        set("base_value", 200);
        set("base_weight", 10);
        set("long", "�D�`�}����������G�C");
    }
    setup();
}
