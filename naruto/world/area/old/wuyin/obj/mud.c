#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(YEL"��d��"NOR, ({ "mud" }));
    if( !clonep() ) {
        set("base_unit", "�b");
        set("base_value", 0);
        set("base_weight", 100);
        set("long", "�@�b��d�ڡC\n");
    }
    setup();
}
