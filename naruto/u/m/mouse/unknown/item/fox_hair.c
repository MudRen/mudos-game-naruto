#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"����"NOR, ({ "fox hair", "hair", "_FOX_HAIR_" }) );

    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 30);
        set("base_weight", 400);
        set("long", "�@�ڴĦ⪺������C\n");
    }
    setup();
}
