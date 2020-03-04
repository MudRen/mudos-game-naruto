#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(HIW"風行靴"NOR, ({ "white cloth boots", "boots" }) );

    set_weight(1500);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 7000);
        set("long", "可以讓移動速度增加的靴子。\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "move": 10,
        ]));
    }

    setup();
}
