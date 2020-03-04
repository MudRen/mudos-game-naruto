#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
    set_name(HIG"瑪瑙"NOR"項鍊", ({ "agate necklace", "necklace" }) );
    set_weight(600);
    setup_neck_eq();

    if( !clonep() ) {
        set("unit", "串");
        set("value", 5000);
        set("long", "一串瑪瑙項鍊，有著神秘的力量。\n");
        set("wear_as", "neck_eq");
        set("apply_armor/neck_eq", ([
            "hp": 100,
        ]));
    }

    setup();
}
