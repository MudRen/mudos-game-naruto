#include <ansi.h>
#include <armor.h>
inherit F_LEG_EQ;
void create()
{
    set_name(BRED+HIR"���~���@"NOR, ({ "blood legging", "legging" }) );
    set_weight(100);
    setup_leg_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī��@��\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,            
        ]));
        set("wear_msg",RED+"$N��W"+name()+RED"���P�ɡA�|�P��_�F����ۭ��I\n"NOR);
    }

    setup();
}

