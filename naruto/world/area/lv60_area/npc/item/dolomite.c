#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�ۦ�", ({ "dolomite", "_DOLOMITE_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", -1);
        set("base_weight", 50);
        set("long", "�a���H�ʪ��ۦǡA�I����|�_���U�N�C");
    }
    setup();
}
