#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name(BWHT+HIB"呼拉圈"NOR, ({ "hula hoop", "hoop" }) );
    set_weight(1000);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "個");
        set("value", 750);
        set("long", "一個讓你瘦身用的呼拉圈，神奇的是不用搖也不會掉在地上。\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "evade": 5,
        ]));
    }

    setup();
}
