#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"���q"NOR, ({ "coal", "_COAL_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", -1);
        set("base_weight", 10);
        set("long", "�¶ª��ѺҡA�A�X�ΨӿN���[�šC");
    }
    setup();
}
