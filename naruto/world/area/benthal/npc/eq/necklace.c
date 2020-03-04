#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIC"���v"HIW"����"NOR, ({ "sea heart necklace", "necklace", "heart" }) );
    set_weight(1000);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 46400);
        set("no_box", 1);
        set("long", "���Ŧ⪺�ߧζ���A������ģ�ɤ��Ŧ���o�Q���ͰʡC\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "ap": 150,
            "armor": 5,
            "int": 2,
        ]));
    }
    setup();
}
