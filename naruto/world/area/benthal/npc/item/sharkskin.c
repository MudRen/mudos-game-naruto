#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�T����"NOR, ({ "sharkskin" }));

    if( !clonep() ) {
        set("base_unit", "�i");
        set("base_value", 200);
        set("base_weight", 1000);
        set("long", "�T�����~�֡A���G�Z��w���C\n");
    }
    setup();
}
