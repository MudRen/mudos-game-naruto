#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(HIW"����"NOR"��", ({ "owl claw","claw" }) );

    set_weight(1500);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 15750);
        set("long", "�a�����������A���l�y�U�B��w�L��C\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor" : 5,
            "attack" : 5,
            "intimidate" : 5,
        ]));
    }
    setup();
}
