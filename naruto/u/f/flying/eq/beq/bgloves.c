#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(BBLU+HIC"B�Ũ��M"NOR, ({ "blevel gloves","gloves" }) );

    set_weight(400);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 7500);
        set("long", "B��NPC�M�Ϊ����M�A�����������m��O�C\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 5,
        ]));
    }

    setup();
}

