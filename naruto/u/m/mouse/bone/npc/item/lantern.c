#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIG"�q���Q�OŢ"NOR, ({ "tonbeli lantern", "lantern", "_TONBELI_A_" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10000);
        set("base_weight", 600);
        set("long", "�q���Q�Ү����OŢ�A�ɱ`�o�X��⪺�G���C\n");
    }
    setup();
}
