#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(YEL"�j�K�U"NOR, ({ "shit hat", "hat" }) );

    set_weight(3000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 700);
        set("long", "�@���j�K�y�����U�l�A���G�O�Ψӷd���Ϊ��C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "int": 1,
        ]));
    }

    setup();
}
