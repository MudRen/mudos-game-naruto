#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"���j�ï]"NOR, ({ "pearl" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("unit", "��");
        set("base_value", 3000);
        set("base_weight", 200);
        set("long", "�{�G���j���ï]�A�Q���M�ӤH�̪��̷R�C\n");
    }
    setup();
}
