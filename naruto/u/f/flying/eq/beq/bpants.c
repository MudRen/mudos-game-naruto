#include <ansi.h>
#include <armor.h>

inherit F_PANTS;

void create()
{
    set_name(BBLU+HIC"B級制式長褲"NOR, ({ "blevel short", "short" }) );
    set_weight(1000);
    setup_pants();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 5000);
        set("long", "B級NPC專用的制式長褲，有不錯的防禦能力。\n");
        set("wear_as", "pants");
        set("apply_armor/pants", ([
            "armor": 10,
        ]));
    }

    setup();
}

