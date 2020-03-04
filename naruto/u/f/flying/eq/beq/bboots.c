#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(BBLU+HIC"B級制式戰鞋"NOR, ({ "Blevel boots","boots" }) );

    set_weight(8000);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 7500);
        set("long", "B級NPC專用的制式鞋，有不錯的防禦能力。\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 5,
        ]));
    }

    setup();
}


