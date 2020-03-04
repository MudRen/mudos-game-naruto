#include <ansi.h>
#include <armor.h>
inherit F_LEG_EQ;
void create()
{
    set_name(HIY"黃金護腿"NOR, ({ "Gold leggings", "leggings" }) );
    set_weight(1500);
    setup_leg_eq();
    if( !clonep() ) {
        set("unit", "對");
        set("value", 20);
        set("long", "純金打造的護腿非常的值錢\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "armor": 50,
            "str"  : 5,
            "con"  : 5,
            "dex"  : 5,
            "int"  : 5,
       ]));
    }
    setup();
}

