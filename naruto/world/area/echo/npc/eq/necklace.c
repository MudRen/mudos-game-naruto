#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(GRN"蛇神"NOR"項鍊", ({ "snakegod necklace", "necklace" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "串");
        set("value", 5200);
        set("long", "一串鐵製的項鍊，中間刻著一條長著翅膀的蛇。\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "con": 4,
        ]));
    }
    setup();
}
