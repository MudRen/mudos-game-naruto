#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("����", ({ "fish scale", "scale", "_FISH_SCALE_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 100);
        set("base_weight", 700);
        set("long", "�h��������A�~����ơA�o�w�פQ���C\n");
    }
    setup();
}
