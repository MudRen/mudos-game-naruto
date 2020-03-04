#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIG"海葵"NOR+GRN"編成鎧"NOR, ({ "root armor", "armor" }) );
    set_weight(2500);
    setup_armor();
    if( !clonep() ) {
        set("unit", "件");
        set("value", 121000);
        set("no_box", 1);
        set("long", "由巨型海葵根部編成的盔甲，強大的生命力對使用者也會造成影響。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 10,
            "hp": 200,
            "mp": 100,
            "ap": 100,
        ]));
    }
    setup();
}
