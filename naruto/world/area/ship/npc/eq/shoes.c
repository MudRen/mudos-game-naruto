#include <ansi.h>
#include <armor.h>

inherit F_FEET_EQ;

void create()
{
    set_name(HIK"���Y�־c"NOR, ({ "black leather shoes", "shoes" }) );
    set_weight(1200);
    setup_feet_eq();
    if( !clonep() ) {
        set("unit", "��");
        set("value", -1);
        set("no_box", 1);
        set("long", "���N�h�u�¨��v���W���ѨӡA�w�Y���¥־c�C\n");
        set("wear_as", "feet_eq");
        set("apply_armor/feet_eq", ([
            "armor": 20,
            "evade": 25,
            "attack": 20,
            "heavy hit": 10,
        ]));
    }
    setup();
}
