#include <ansi.h>
#include <armor.h>
inherit F_WRIST_EQ;
void create()
{
    set_name(BRED+HIR"���~�u�@"NOR, ({ "blood wrist", "wrist" }) );
    set_weight(100);
    setup_wrist_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", 0);
        set("long", "�㦳�����\�Ī��@��\n");
        set("wear_as", "wrist_eq");
        set("apply_armor/wrist_eq", ([
            "dex": 5,
            "str": 5,
            "int": 5,
            "con": 5,
            "armor": 20,
        ]));
        set("wear_msg",RED"$N���W"+name()+RED"���P�ɡA�����@�D�����g�J$N���餺�I\n"NOR);
    }

    setup();
}

