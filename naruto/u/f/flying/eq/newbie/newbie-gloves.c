#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name("新手手套", ({ "newbie gloves","gloves" }) );

    set_weight(50);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 10);
        set("long", "一個新手的手套，看起來像是吃手扒雞時所用的。\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}

