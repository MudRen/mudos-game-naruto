#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(BYEL+HIY"���ܷǤ�M"NOR, ({ "pajozhun gloves","gloves" }) );

    set_weight(1550);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 7100);
        set("long", "���W�F���A�s���˳������I\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "exact" : 10,
            "armor" : 1,
        ]));
    }

    setup();
}

