#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(YEL"狼腳"NOR, ({ "wolf's forward feet", "feet" }) );

    set_weight(2000);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "對");
        set("value", 200);
        set("long", "一對狼的前腳，讓你可以裝成狼。\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 2,
        ]));
    }

    setup();
}
