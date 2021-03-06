#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
    set_name(HIY"司法裁判戒"NOR, ({ "court martial ring", "ring" }) );
    set_weight(200);
    setup_finger_eq();
    if( !clonep() ) {
        set("unit", "枚");
        set("value", 29600);
        set("no_box", 1);
        set("long", "象徵司法島最高裁判長的戒指，上面寫了兩個字「公正」。\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "heavy hit": 10,
            "int": 5,
            "armor": 1,
        ]));
    }
    setup();
}
