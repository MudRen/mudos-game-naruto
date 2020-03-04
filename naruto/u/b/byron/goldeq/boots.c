#include <ansi.h>
#include <armor.h>
inherit F_FEET_EQ;
void create()
{
    set_name(HIY"黃金戰靴"NOR, ({ "Gold boots", "boots" }) );
    set_weight(1500);
    setup_feet_eq();
    if( !clonep() ) {
        set("unit", "雙");
        set("value", 20);
        set("long", "純金打造的靴子非常的值錢\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}
