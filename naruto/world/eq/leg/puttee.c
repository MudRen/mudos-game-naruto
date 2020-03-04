#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name("綁腿", ({ "puttee" }) );

    set_weight(800);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "對");
        set("value", 100);
        set("long", "布製的綁腿，提供一般的防護。\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}

