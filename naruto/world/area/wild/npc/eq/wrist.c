#include <ansi.h>
#include <armor.h>

inherit F_WRIST_EQ;

void create()
{
    set_name(CYN"�C���@��"NOR, ({ "bronze wrist", "wrist" }) );
    set_weight(100);
    setup_wrist_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 5900);
        set("long", "�@�Ӱ�w���@��\n");
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
