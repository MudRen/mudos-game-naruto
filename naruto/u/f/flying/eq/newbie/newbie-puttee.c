#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name("�s��j�L", ({ "newbie puttee", "puttee" }) );

    set_weight(200);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�s�⪺�j�L�A�O�N�p�ȪO�j�b�L�W�C\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "evade": 1,
        ]));
    }

    setup();
}


