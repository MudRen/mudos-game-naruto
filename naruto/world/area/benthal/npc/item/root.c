#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(GRN"����"NOR, ({ "anemone root", "root" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 300);
        set("base_weight", 100);
        set("long", "���y�ϩҥͦs�������������ڳ��A�D�`�����ʡC\n");
    }
    setup();
}
