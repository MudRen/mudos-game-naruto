#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
    set_name(HIM"姆指環"NOR, ({ "Thumb","thumb" }) );
    set_weight(100);
    setup_finger_eq();

    if( !clonep() ) {
        set("unit", "枚");
        set("value", 10);
        set("long", "讓大姆指在工作中不易受傷的保護裝備。\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "parry": 10,
        ]));
    }

    setup();
}
