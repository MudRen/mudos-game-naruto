#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�۶갮"NOR, ({ "Longan", "longan" }));
    if( !clonep() ) {
        set("base_unit", "�U");
        set("base_value", -1);
        set("unit", "�U");
        set("base_weight", 500);
        set("long", "�����ذe���@�U�۶갮�A�S�Q�٬��s���C\n");
    }
    setup();
}
