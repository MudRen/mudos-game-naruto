#include <ansi.h>
#include <armor.h>
inherit F_HEAD_EQ;
void create()
{
    set_name(BRED+HIR"���~�F�@"NOR, ({ "blood helmet", "helmet" }) );
    set_weight(100);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī��@�B\n");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 30,
            "exact": 30,
        ]));
        set("wear_msg",RED"$N���W"+name()+RED"���P�ɡA$N�����������ܦ�����I\n"NOR);
    }

    setup();
}

