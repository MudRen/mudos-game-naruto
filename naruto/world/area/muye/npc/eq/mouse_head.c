#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"���Y"NOR, ({ "mouse's head", "head" }) );

    set_weight(1000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 100);
        set("long", "�@��ѹ��y�����Y�A�i�H���ꦨ�ѹ��C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}
