#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(RED"蜘蛛脫殼"NOR, ({ "queen spider armor", "armor" }) );
    set_weight(5000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "件");
        set("value", 12950);
        set("long", "皇后蜘蛛的紅色外殼，看起來有點噁心。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 15,
            "str": 1,
            "wittiness": 5,
            "hp": 50,
            "mp": 30,
        ]));
    }
    setup();
}
