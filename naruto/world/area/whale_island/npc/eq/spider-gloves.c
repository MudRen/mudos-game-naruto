#include <ansi.h>
#include <armor.h>
inherit F_HAND_EQ;

void create()
{
    set_name(HIW"�����M"NOR, ({ "spider gloves","gloves" }) );

    set_weight(1200);
    setup_hand_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 4500);
        set("long", "�@����ƫD�`�n�������M�A���ӬO�Y�جöQ���j�ﵷ�C\n");
        set("wear_as", "hand_eq");
        set("apply_armor/hand_eq", ([
            "armor": 3,
            "hp": 50,
        ]));
    }

    setup();
}

