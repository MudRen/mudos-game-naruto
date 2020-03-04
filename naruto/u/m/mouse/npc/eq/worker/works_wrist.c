#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name(HIR"����"HIW"���"NOR, ({ "Watch", "watch" }) );
    set_weight(100);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�����@���A�\��²��B��ΡC\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "dex": 1,
            "str": 1,
            "int": 1,
            "armor": 4,
        ]));
    }

    setup();
}
