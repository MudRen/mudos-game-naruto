#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIC"�u�@��"NOR, ({ "An I.D. Card", "card" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "�i");
        set("value", 10);
        set("long", "�@�i���u�u�@�ҡA�W�����۷Ӥ��Щ����u�����C\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "int": 10,
        ]));
    }

    setup();
}
