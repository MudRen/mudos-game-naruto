#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIC"����"NOR, ({ "crystallize" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 5);
        set("base_weight", 1);
        set("long", "�B�ѳ��a���Ҿ���������A�J�쪢���K�ߨ�ĤơC");
    }
    setup();
}