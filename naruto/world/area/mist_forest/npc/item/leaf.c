#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(CYN"�B��"NOR, ({ "leaf-ice", "leaf" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 2);
        set("base_weight", 1);
        set("long", "�Q�B�ҦB�᪺�����A�]���ɶ��L���Ӧ�������C");
    }
    setup();
}