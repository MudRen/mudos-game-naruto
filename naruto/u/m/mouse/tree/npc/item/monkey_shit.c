#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(BYEL"�U��"NOR, ({ "monkey shit", "shit" }));
    if( !clonep() ) {
        set("base_unit", "�b");
        set("base_value", 1);
        set("base_weight", 50);
        set("long", "���R�Ѫ��U�l�j�K�C\n");
    }
    setup();
}
