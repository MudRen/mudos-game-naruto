#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name(BBLU+HIC"B級制式綁腿"NOR, ({ "Blevel puttee", "puttee" }) );

    set_weight(500);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "對");
        set("value", 13500);
        set("long", "B級NPC專用的制式綁腿，有不錯的防禦能力。\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "armor": 9,
        ]));
    }

    setup();
}

