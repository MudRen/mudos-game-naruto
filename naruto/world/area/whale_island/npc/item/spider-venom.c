#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{
    set_name(HIM"�j��r�G"NOR, ({ "spider venom", "venom","__QUEST_D_2__" }));
    if( !clonep() ) {
        set("base_unit", "�~ ");
        set("base_value", 45);
        set("base_weight", 100);
        set("long", "�@�~��Ķ��Ӫ��j��r�G�C\n");
    }
    setup();
}

