#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"�U��"NOR, ({ "monkey tooth", "tooth", "_MONKEY_TOOTH_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10);
        set("base_weight", 400);
        set("long", "���������V�Q���_�ӱ����a�����U�l�����C\n");
    }
    setup();
}
