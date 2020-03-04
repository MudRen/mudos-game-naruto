#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
        set_name(RED"雀戒"NOR, ({ "bird ring","ring" }) );
        set_weight(100);
        setup_finger_eq();

        if( !clonep() ) {
                set("unit", "指");
                set("value", 1000);
                set("long",
                        "相傳是四大聖獸【朱雀】的眼睛所製成的戒指，閃閃發著紅光看起來就很高貴的樣子。\n");
                set("wear_as", "finger_eq");
                set("apply_armor/finger_eq", ([
                        "con" :2,
                ]));
        }

        setup();
}
