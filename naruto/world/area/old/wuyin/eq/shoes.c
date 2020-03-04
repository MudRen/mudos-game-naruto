#include <armor.h>
inherit F_FEET_EQ;

void create()
{
        set_name("忍鞋", ({ "shoes" }) );
        set_weight(100);
        setup_feet_eq();

        if( !clonep() ) {
                set("unit", "雙");
                set("value", 10);
                set("long",
                        "一雙下忍所穿的草鞋，沒有什麼特別的。\n");
                set("wear_as", "feet_eq");
                set("apply_armor/feet_eq", ([
                        "armor" :1,

                ]));
        }

        setup();
}
