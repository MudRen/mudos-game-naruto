#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"���q"NOR, ({ "copper", "_COPPER_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", -1);
        set("base_weight", 50);
        set("long", "����g�⪺�n����q�A�O�j�ƪZ�����ʤ��i�ʤ֪��q���C");
    }
    setup();
}
