#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(BBLU+HIC"B�Ũ�Ծc"NOR, ({ "Blevel boots","boots" }) );

    set_weight(8000);

    setup_feet_eq();

    if( !clonep() ) {
        set("unit", "��");
        set("value", 7500);
        set("long", "B��NPC�M�Ϊ���c�A�����������m��O�C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 5,
        ]));
    }

    setup();
}


