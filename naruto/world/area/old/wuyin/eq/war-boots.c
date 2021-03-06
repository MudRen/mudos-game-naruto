#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(HIY"戰旅之靴"NOR, ({ "war boots", "boots" }) );

    set_weight(50000);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 7000);
        set("long", "鬥士們在戰場上穿著的鞋子，十分厚重。\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "move": 10,
            "armor": 5,
            "dex": -1,
        ]));
    }

    setup();
}
