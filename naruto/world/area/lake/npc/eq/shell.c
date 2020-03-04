#include <ansi.h>
#include <armor.h>
inherit F_ARMOR;

void create()
{
    set_name(HIB"貝殼"NOR, ({ "shell" }) );
    set_weight(1000);
    setup_armor();
    if( !clonep() ) {
        set("unit", "個");
        set("value", 500);
        set("long", "大蚌的外殼，非常的堅硬。\n");
        set("wear_as", "armor");
        set("apply_armor/armor", ([
            "armor": 5,
        ]));
    }
    setup();
}
