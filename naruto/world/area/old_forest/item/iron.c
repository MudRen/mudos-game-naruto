#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(RED"�K�q"NOR, ({ "iron", "_IRON_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", -1);
        set("base_weight", 50);
        set("long", "��w���K�q�A���L�|���g�L�B�z�٫ܲ��W�C");
    }
    setup();
}
