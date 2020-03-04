#include <ansi.h>
#include <armor.h>

inherit F_LEG_EQ;

void create()
{
    set_name(HIW"��"BLK"��"NOR"�O", ({ "Power Bone","bone" }) );

    set_weight(1500);
    setup_leg_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 10);
        set("long", "�`�Y�°��O�A�O�����d�����f�C\n");
        set("wear_as", "leg_eq");
        set("apply_armor/leg_eq", ([
            "armor": 20,
            "con": 10,
        ]));
    }

    setup();
}
