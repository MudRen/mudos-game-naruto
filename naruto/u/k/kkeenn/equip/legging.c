#include <ansi.h>
#include <armor.h>
inherit F_LEG_EQ;
void create()
{
    set_name(BRED+HIR"血繼風護"NOR, ({ "blood legging", "legging" }) );
    set_weight(100);
    setup_leg_eq();
    if( !clonep() ) {
        set("unit", "對");
        set("value", 0);
        set("long", "具有神秘功效的護足\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,            
        ]));
        set("wear_msg",RED+"$N穿上"+name()+RED"的同時，四周刮起了紅色旋風！\n"NOR);
    }

    setup();
}

