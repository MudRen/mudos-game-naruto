#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"�j��L"NOR, ({ "spider leg", "leg" }));
    if( !clonep() ) {
        set("base_unit", "��");
            set("base_value", 10);
        set("base_weight", 100);
        set("long", "�@���٤U�Ӫ��j��L�C\n");
    }
    setup();
}

