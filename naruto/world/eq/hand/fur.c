#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(YEL"�ֻs��M"NOR, ({ "fur gloves","gloves" }) );

    set_weight(1000);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 200);
        set("long", "�@���ֻs����M�A���_�ӫܫO�x�C\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 2,
        ]));
    }

    setup();
}
