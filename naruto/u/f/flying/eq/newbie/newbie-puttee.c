#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name("新手綁腿", ({ "newbie puttee", "puttee" }) );

    set_weight(200);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "對");
        set("value", 10);
        set("long", "新手的綁腿，是將厚紙板綁在腿上。\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "evade": 1,
        ]));
    }

    setup();
}


