#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�z��"NOR, ({ "wafer", "_KARE_B_" }));
    if( !clonep() ) {
        set("unit", "�U");
        set("value", 300);
        set("base_value", 300);
        set("base_weight", 10);
        set("long","��@�몺�̧���ߩʡA�A�X�ΨӰ��̤Y�l�����������C\n");
    }
    setup();
}
