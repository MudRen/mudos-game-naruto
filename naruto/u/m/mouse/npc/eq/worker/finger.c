#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
    set_name(HIM"�i����"NOR, ({ "Thumb","thumb" }) );
    set_weight(100);
    setup_finger_eq();

    if( !clonep() ) {
        set("unit", "�T");
        set("value", 10);
        set("long", "���j�i���b�u�@���������˪��O�@�˳ơC\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "parry": 10,
        ]));
    }

    setup();
}
