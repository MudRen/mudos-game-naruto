#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"����"NOR, ({ "bear's hair", "hair" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 50);
        set("base_weight", 600);
        set("long", "�@�ڲʲʦǦǪ�����C\n");
    }
    setup();
}
