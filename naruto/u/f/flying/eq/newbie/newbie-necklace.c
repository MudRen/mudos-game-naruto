#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name("�s�ⶵ��", ({ "newbie necklace", "necklace" }) );
    set_weight(300);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�β��K��¶���鱾�b��l�W�C\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}


