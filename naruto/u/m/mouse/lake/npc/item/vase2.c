#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�}��~", ({ "vase" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 2);
        set("base_weight", 100);
        set("long", "���~�@�ӡA�ڥ��O��}�l�Q�F�����F��C");
    }
    setup();
}
