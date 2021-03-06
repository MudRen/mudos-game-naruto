#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(HIK"黑頭皮鞋"NOR, ({ "black leather shoes", "shoes" }) );
    set_weight(1200);
    setup_feet_eq();
    if( !clonep() ) {
        set("unit", "雙");
        set("value", -1);
        set("no_box", 1);
        set("long", "香吉士「黑足」之名的由來，硬頭的黑皮鞋。\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 20,
            "evade": 25,
            "attack": 20,
            "heavy hit": 10,
        ]));
    }
    setup();
}
