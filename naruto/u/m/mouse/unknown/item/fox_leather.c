#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"����"NOR, ({ "fox leather", "leather", "_FOX_LEATHER_" }) );

    if( !clonep() ) {
        set("base_unit", "�i");
        set("unit", "�i");
        set("base_value", 50);
        set("base_weight", 300);
        set("long", "��������֡A�N�_�ӫܷx�M�C\n");
    }
    setup();
}
