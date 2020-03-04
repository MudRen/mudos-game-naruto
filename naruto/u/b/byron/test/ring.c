#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;
void create()
{
    set_name(MAG"紫玉戒"NOR,({"purple-jade ring","ring"}) );;
    set_weight(200);
    setup_finger_eq();
    if( !clonep() ) {
        set("unit", "枚");
        set("value", 50000);
        set("long", "一枚紫色的古戒，上面刻著看不懂的文字，泛著溫潤的光澤。\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "str": 5,
            "con": 5,
            "int": 5,
            "dex": 5,
            "armor": 50,
        ]));
    }
    setup();
}
