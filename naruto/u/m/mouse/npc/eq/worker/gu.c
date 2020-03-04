#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name(HIW"威"BLK"骨"NOR"力", ({ "Power Bone","bone" }) );

    set_weight(1500);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "罐");
        set("value", 10);
        set("long", "常吃威骨力，保持健康的骨骼。\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "armor": 20,
            "con": 10,
        ]));
    }

    setup();
}
