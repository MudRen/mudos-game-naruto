#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name(HIK"維"NOR"骨力", ({ "gls" }) );

    set_weight(1500);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "瓶");
        set("value", 34300);
        set("no_box", 1);
        set("long", "認明金字標籤才是真正的維骨力喔。\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "con": 5,
            "dex": 2,
        ]));
    }
    setup();
}
