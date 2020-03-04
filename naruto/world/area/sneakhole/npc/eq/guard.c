#include <ansi.h>
#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
    set_name(HIM"音忍護額"NOR, ({ "ninja guard", "guard" }) );
    set_weight(1500);
    setup_head_eq();
    if( !clonep() ) {
        set("unit", "塊");
        set("value", 25700);
        set("long", "一塊音忍的頭部護額，上面刻著一個音符。");
        set("wear_as", "head_eq");
        set("apply_armor/head_eq", ([
            "armor": 12,
            "evade": 10,
            "dex": 1,
        ]));

    }
    setup();
}
