#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name("��÷", ({ "cord", "_CORD_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_weight", 100);
        set("base_value", 50);
        set("long", "�Ψӵo�g���������ϥΪ��ɤ�÷�C");
    }
    setup();
}
