#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name(BBLU+HIC"B�Ũ�j�L"NOR, ({ "Blevel puttee", "puttee" }) );

    set_weight(500);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 13500);
        set("long", "B��NPC�M�Ϊ���j�L�A�����������m��O�C\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "armor": 9,
        ]));
    }

    setup();
}

