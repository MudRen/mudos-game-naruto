#include <ansi.h>
#include <armor.h>
inherit F_FINGER_EQ;

void create()
{
    set_name(HIY"麵神戒"NOR, ({ "noodlegod ring", "ring" }) );
    set_weight(200);
    setup_finger_eq();
    if( !clonep() ) {
        set("unit", "枚");
        set("value", 4700);
        set("no_box", 1);
        set("long", "老張與「一樂」拉麵店老闆比賽獲勝的戒指。\n");
        set("wear_as", "finger_eq");
        set("apply_armor/finger_eq", ([
            "combat": 5,
            "dex": 1,
            "armor": 2,
        ]));
    }
    setup();
}
