#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(HIR"空氣鞋"NOR, ({ "air boots", "boots" }) );

    set_weight(1000);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 25250);
        set("long", "此雙鞋是蠍王跟Air Jordan corssover所製的，全球限量一雙。\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "dex": 5,
            "evade": 5,
            "dodge": 5,
            "armor": 6,
        ]));
    }

    setup();
}

