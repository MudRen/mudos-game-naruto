#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(GRN"��U"NOR, ({ "straw hat", "hat" }) );

    set_weight(500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "�@���ί�÷�s´�Ӧ�����U�A�ݰ_�Ӭ۷��O�o�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}
