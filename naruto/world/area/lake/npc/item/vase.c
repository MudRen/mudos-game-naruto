#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�j����~", ({ "vase", "_OLD_VASE_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 20);
        set("base_weight", 100);
        set("long", "�ݰ_�Ӧ��q���v����~�A�W�����I�����C");
    }
    setup();
}
