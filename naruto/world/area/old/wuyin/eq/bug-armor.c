#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(GRN"綠虫鱗甲"NOR, ({ "bug armor", "armor" }) );

    set_weight(6000);
    setup_armor();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 1000);
        set("long", "一件綠虫鱗甲，穿上去有一種保護色，在樹林裡不易被敵人發現。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
                
        ]));
    }

    setup();
}

