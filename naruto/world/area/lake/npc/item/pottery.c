#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name("��������", ({ "pottery", "_UNKNOWN_POTTERY_" }));
    if( !clonep() ) {
        set("base_unit", "�y");
        set("unit", "�y");
        set("base_value", 20);
        set("base_weight", 100);
        set("long", "���۩_�S���޲������A�����D���X�ӻɪO�C");
    }
    setup();
}
