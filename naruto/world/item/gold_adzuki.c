#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIY"��������"NOR, ({ "Gold adzuki", "adzuki" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", -1);
        set("unit", "��");
        set("base_weight", 500);
        set("long", "�W�����۱s��~�a�a�x���Ҫ����~�����C\n");
    }
    setup();
}
