#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name("新手鞋", ({ "newbie boots","boots" }) );

    set_weight(100);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 10);
        set("long", "油膩膩的新手鞋，穿上去腳底滑滑的。\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "move": 1,
        ]));
    }

    setup();
}

