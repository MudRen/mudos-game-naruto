#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name(GRN"�C�D�@�L"NOR, ({ "snake legging", "legging" }) );

    set_weight(800);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 6000);
        set("long", "�C�D�ֻs�����@�L�A�]���ʤQ�������_�Ӭ۷�e�����ʡC\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "armor": 5,
            "dex": 1,
            "move": 2,
            "ap": 20,
            "mp": 30,
        ]));
    }

    setup();
}
