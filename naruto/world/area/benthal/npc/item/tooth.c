#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIW"�T��"NOR, ({ "shark tooth", "tooth" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 100);
        set("base_weight", 600);
        set("long", "�`�����T���������C\n");
    }
    setup();
}
