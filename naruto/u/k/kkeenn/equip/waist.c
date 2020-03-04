#include <ansi.h>
#include <armor.h>
inherit F_WAIST_EQ;
void create()
{
    set_name(BRED+HIR"���~�x�@"NOR, ({ "blood waist", "waist" }) );
    set_weight(100);
    setup_waist_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī��y�a\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,
            "continual hit": 50,
            "parry": 50,
            "combat": 50,
            "ninja": 50,
            "magic": 50,
            "force": 50,
            "savage hit": 50,
            "heavy hit": 50,         
        ]));
        set("wear_msg",RED"$N��W"+name()+RED"���Ǿ��E�X�U�D���⵷���d�J�ԡI\n"NOR);
    }

    setup();
}

