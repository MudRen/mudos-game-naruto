#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"�R���U"NOR, ({ "rhino hat", "hat" }) );

    set_weight(3000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 3000);
        set("long", "�@���R���y�����U�l�A���A���O�R�K�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 6,
        ]));
    }

    setup();
}
