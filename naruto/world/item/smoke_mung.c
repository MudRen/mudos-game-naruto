#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIG"���t��"NOR, ({ "Smoke mung", "mung" }));
    if( !clonep() ) {
        set("base_unit", "�M");
        set("base_value", -1);
        set("unit", "�M");
        set("base_weight", 500);
        set("long", "�H���q�ѱC�C�ӶO�ߦ�s�@���ǩ_�񨧡C\n");
    }
    setup();
}
