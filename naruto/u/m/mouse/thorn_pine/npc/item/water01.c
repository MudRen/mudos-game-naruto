#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIG"����G"NOR, ({ "green water", "water", "_HIG_WATER_" }));
    if( !clonep() ) {
        set("base_unit", "�~");
        set("unit", "�~");
        set("base_value", 20);
        set("base_weight", 10);
        set("long", "�@�~��⪺��G�C");
    }
    setup();
}
