#include <armor.h>
inherit F_FEET_EQ;

void create()
{
        set_name("�Ծc", ({ "shoes" }) );
        set_weight(100);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 10);
                set("long",
                        "�@���U�ԩҬ諸��c�A�S������S�O���C\n");
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor" :1,

                ]));
        }

        setup();
}
