#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"���x"NOR, ({ "fox paw", "paw", "_FOX_PAW_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 500);
        set("base_weight", 300);
        set("long", "��������x�A�W�������l�D�`�U�Q�C\n");
    }
    setup();
}
