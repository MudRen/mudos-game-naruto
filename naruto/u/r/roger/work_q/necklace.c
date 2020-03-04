#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(GRN"�D��"NOR"����", ({ "snakegod necklace", "necklace" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5200);
        set("long", "�@���K�s������A������ۤ@�����ۯͻH���D�C\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "con": 4,
        ]));
    }
    setup();
}
