#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name("新生布甲", ({ "Newchar Armor", "armor" }) );

    set_weight(1500);
    setup_armor();

    if( !clonep() ) {
        set("unit", "件");
        set("value", 20);
        set("long", "一件兩套布衣縫在一起的厚布甲，由防大師製作。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 3,
        ]));
    }
    setup();
}
