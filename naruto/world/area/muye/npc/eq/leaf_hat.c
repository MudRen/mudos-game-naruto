#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(GRN"���"NOR, ({ "leaf hat", "hat" }) );

    set_weight(1500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 22000);
        set("long", "�@���ί�÷�s´�Ӧ�������A�ݰ_�Ӭ۷��O�o�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 10,
            "exact": 10,
        ]));
    }

    setup();
}
