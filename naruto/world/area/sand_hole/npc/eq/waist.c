#include <ansi.h>
#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
    set_name("護帶", ({ "waist" }) );
    set_weight(6000);
    setup_waist_eq();
    if( !clonep() ) {
        set("unit", "條");
        set("value", 24000);
        set("long", "石像巨兵的腰帶，似乎擁有各種不同的能力。\n");
        set("wear_as", "waist_eq");
    }
    set("apply_armor/waist_eq", ([
        "armor": 8,
    ]));
    setup();
}
