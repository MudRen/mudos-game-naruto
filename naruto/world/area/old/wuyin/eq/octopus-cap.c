#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIW"�K�}�Q��U"NOR, ({ "octopus cap", "cap" }) );
    set_weight(5000);
    setup_head_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 20000);
        set("long", "���۸{���@�p���Q��U�A�˹��b�Y�W�ƷȷȪ������n��~~@��@~~�C");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 10,
            "int": 2,
            "parry": 5,
        ]));
    }

    setup();
}

