#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name("�j�L", ({ "puttee" }) );

    set_weight(800);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "���s���j�L�A���Ѥ@�몺���@�C\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}

