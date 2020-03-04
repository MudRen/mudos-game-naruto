#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIM"�����@�B"NOR, ({ "ninja guard", "guard" }) );
    set_weight(1500);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 25700);
        set("long", "�@�����Ԫ��Y���@�B�A�W����ۤ@�ӭ��šC");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 12,
            "evade": 10,
            "dex": 1,
        ]));

    }
    setup();
}
