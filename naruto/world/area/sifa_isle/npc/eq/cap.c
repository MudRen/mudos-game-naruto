#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIC"���x�U"NOR, ({ "service cap", "cap" }) );

    set_weight(1500);

    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 19200);
        set("long", "¸�ۡu�ۢϢ�עܢӡv�r�˪����x�U�l�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 10,
            "evade": 6,
        ]));
    }
    setup();
}
