#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("�_��", ({ "bowlu", "_BOW_LU_" }));
    if( !clonep() ) {
        set("base_unit", "�]");
        set("unit", "�]");
        set("base_value", 500);
        set("base_weight", 50);
        set("long", "�����~�A�e�}�l�����D�Y�F�|�ǰI�ܦӦ��C");
    }
    setup();
}
