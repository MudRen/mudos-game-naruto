#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIG"�D�r"NOR, ({ "snake venom", "venom" }));
    if( !clonep() ) {
        set("base_unit", "�~");
        set("unit", "�~");
        set("base_value", 500);
        set("base_weight", 100);
        set("long", "�@�~�D���r�G�C\n");
    }
    setup();
}
