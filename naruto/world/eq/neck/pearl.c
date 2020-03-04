#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIW"�ï]"NOR"����", ({ "pearl necklace", "necklace" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 1500);
        set("long", "�Τ@�������ï]��_�Ӫ�����A�۷������C\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "hp": 30,
        ]));
    }

    setup();
}
