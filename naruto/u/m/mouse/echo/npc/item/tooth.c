#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"�T��"NOR, ({ "wolf tooth", "tooth", "_WOLF_TOOTH_" }));

    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 100);
        set("base_weight", 600);
        set("long", "�@���s�T�~�����y�U�y���C\n");
    }
    setup();
}
