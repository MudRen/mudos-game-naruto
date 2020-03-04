#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(BBLU+HIC"B級制式手套"NOR, ({ "blevel gloves","gloves" }) );

    set_weight(400);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 7500);
        set("long", "B級NPC專用的制式手套，有不錯的防禦能力。\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 5,
        ]));
    }

    setup();
}

