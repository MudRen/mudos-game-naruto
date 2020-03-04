#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
        set_name(HIG"玄武護膝"NOR, ({ "turtle legs","legs" }) );
        set_weight(4000);
        setup_leg_eq();

        if( !clonep() ) {
                set("unit", "對");
        set("value", 500);
                set("long", "相傳是四大聖獸【玄武】的殼所製成的護膝，硬綁綁的看起來十分堅硬。\n");
                set("wear_as", "leg_eq");
                set("apply_armor/leg_eq", ([
                        "armor": 15,
                        "int": -1,
                ]));
        }

        setup();
}

