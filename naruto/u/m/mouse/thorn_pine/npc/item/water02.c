#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIM"�����G"NOR, ({ "purple water", "water", "_HIM_WATER_" }));
    if( !clonep() ) {
        set("base_unit", "�~");
        set("unit", "�~");
        set("base_value", 20);
        set("base_weight", 10);
        set("long", "�@�~���⪺��G�C");
    }
    setup();
}
