#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
    set_name(YEL"銅戒指"NOR, ({ "copper ring","ring" }) );
    set_weight(100);
    setup_finger_eq();

    if( !clonep() ) {
        set("unit", "枚");
        set("value", 480);
        set("long", "一枚銅戒指，戴在手指上讓你的運氣更好。\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "dodge": 4,
        ]));
    }

    setup();
}
