#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"�����"NOR, ({ "Peanut", "peanut" }));
    if( !clonep() ) {
        set("base_unit", "�U");
        set("base_value", -1);
        set("unit", "�U");
        set("base_weight", 500);
        set("long", "�ݰ_�ӫܦn�Y���@�U����͡C\n");
    }
    setup();
}
