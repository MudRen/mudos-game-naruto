#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(NOR"�멥"NOR, ({ "splinter" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 5);
        set("base_weight", 1);
        set("long", "�Q�j�����_�����U���ƦӦ����y�ۡA�D�`�U�Q�C");
    }
    setup();
}