#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"�j��Х�"NOR, ({ "spider smaple", "smaple", "__SMAPLE__" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 500);
        set("base_weight", 100);
        set("long", "�@���μ@�r�j��Ұ����Х��C\n");
    }
    setup();
}
