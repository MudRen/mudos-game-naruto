#include <ansi.h>
#include <armor.h>
inherit F_NECK_EQ;

void create()
{
        set_name(HIY"金剛玉佛珠"NOR, ({ "kinkon rosary","rosary" }) );
        set_weight(1000);
        setup_neck_eq();

        if( !clonep() ) {
                set("unit", "串");
                set("value", 1000);
                set("long",
                        "傳說是風之國的無悔禪師將四十九隻妖魔斬除，將妖魔的靈魂超渡成一串七
七四十九顆的玉佛珠。\n");
                set("wear_as", "neck_eq");
                set("apply_armor/neck_eq", ([
                        "armor" :5,
                        "int":3,
                        "str":3,
                ]));
        }

        setup();
}

