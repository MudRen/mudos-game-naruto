#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�ЮJ", ({ "dust" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 1);
        set("base_weight", 1);
        set("long", "�L�Ϊ��Фg�A�]����Ԫ����Y�Ӳֿn����C");
    }
    setup();
}