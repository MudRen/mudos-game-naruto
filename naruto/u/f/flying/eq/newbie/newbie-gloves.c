#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name("�s���M", ({ "newbie gloves","gloves" }) );

    set_weight(50);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�@�ӷs�⪺��M�A�ݰ_�ӹ��O�Y�⥶���ɩҥΪ��C\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}

