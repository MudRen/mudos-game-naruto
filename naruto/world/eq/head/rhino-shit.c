#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"�R��"NOR+YEL"�j�K�U"NOR, ({ "rhino shit hat", "hat" }) );

    set_weight(3300);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 3700);
        set("long", "�@���R���y���[�W�j�K�y�����U�l�A���A�d���S���O�R�K�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 6,
            "int": 1,
        ]));
    }

    setup();
}
