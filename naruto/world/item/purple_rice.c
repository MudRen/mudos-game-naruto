#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
    set_name(HIM"����"NOR, ({ "Purple rice", "rice" }));
    if( !clonep() ) {
        set("base_unit", "�]");
        set("base_value", -1);
        set("unit", "�]");
        set("base_weight", 500);
        set("long", "�@�]�W���\��"HIR"[��]"NOR"�r�L�������̡C\n");
    }
    setup();
}
