#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIK"�����}"NOR, ({ "cockroach's foot", "foot" }));
    if( !clonep() ) {
        set("base_unit", "��");
        set("base_value", 4);
        set("base_weight", 100);
        set("long", "�@��c�䪺�����}�C\n");
    }
    setup();
}