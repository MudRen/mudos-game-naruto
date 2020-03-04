#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIK"��l"NOR, ({ "boiler" }) );

    set_weight(2000);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 400);
        set("long", "�@�Ӭݰ_�ӫܰ�T����l�A����٦����C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 4,
        ]));
    }

    setup();
}
