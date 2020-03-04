#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(BYEL+HIY"打很準手套"NOR, ({ "pajozhun gloves","gloves" }) );

    set_weight(1550);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "雙");
        set("value", 7100);
        set("long", "戴上了它，連泰森都能秒殺！\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "exact" : 10,
            "armor" : 1,
        ]));
    }

    setup();
}

