#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;
void create()
{
    set_name(BRED+HIR"���~�O�@"NOR, ({ "blood fist", "fist" }) );
    set_weight(100);
    setup_hand_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī����M\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,
            "attack": 100,            
        ]));
        set("wear_msg",RED+"$N��W"+name()+RED"���P�ɡA�ѤW���U�ƹD������¶��$N�I\n"NOR);
    }

    setup();
}

