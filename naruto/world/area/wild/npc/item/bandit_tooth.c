#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIY"�s�������"NOR, ({ "bandit's tooth", "tooth" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 10000);
        set("base_weight", 600);
        set("long", "�@�������{�{�������C\n");
        set("level_c1", 1);
    }
    setup();
}
