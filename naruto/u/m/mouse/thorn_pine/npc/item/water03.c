#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIR"�����G"NOR, ({ "red water", "water", "_HIR_WATER_" }));
    if( !clonep() ) {
        set("base_unit", "�~");
        set("unit", "�~");
        set("base_value", 20);
        set("base_weight", 10);
        set("long", "�@�~���⪺��G�C");
    }
    setup();
}
