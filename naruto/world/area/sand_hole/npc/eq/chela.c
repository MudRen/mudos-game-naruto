#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(HIM"�r��"NOR"���g", ({ "scorpion chela", "chela" }) );

    set_weight(1500);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 63750);
        set("no_box", 1);
        set("long", "�F�ީ��U���r�Ȥ��u�A�w�פ��鵹�@��Z���C\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor" : 10,
            "parry" : 5,
            "wittiness" : 5,
        ]));
    }
    setup();
}
