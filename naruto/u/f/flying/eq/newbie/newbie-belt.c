#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name("新手皮帶", ({ "newbie belt", "belt" }) );
    set_weight(100);
    setup_waist_eq();

    if( !clonep() ) {
        set("unit", "條");
        set("value", 10);
        set("long", "一條破破爛爛的小皮帶，已經無法看出是用什麼材料製成。\n");
        set("wear_as", "waist_eq");
        set("apply_armor/waist_eq", ([
            "armor": 1,
        ]));
    }

    setup();
}


